#include "StandaloneHub.h"

StandaloneHub* StandaloneHub::_instance = nullptr;

bool StandaloneHub::Init(uint16 port)
{
	if (_instance) return true;
	if (!port) return false;
	_instance = new StandaloneHub(port);
	return NetEnter(false);
}

StandaloneHub::StandaloneHub(uint16 port)
{
	_port = port;
	_server = std::make_unique<CommunicationsChannelFactory>(port);
}

StandaloneHub::~StandaloneHub()
{
	NetExit();
}

bool StandaloneHub::SetupGathererGame(bool& gathering_done)
{
	gathering_done = false;

	if (!GotGatherer()) return true;

	_topology_message = std::unique_ptr<TopologyMessage>(_gatherer->receiveSpecificMessage<TopologyMessage>());

	if (!_topology_message || !GetGameDataFromGatherer()) return Reset();

	SetNetscriptStatus(_lua_message.get());

	_gatherer->enqueueOutgoingMessage(RemoteHubReadyMessage());

	if (!NetProcessNewJoiner(_gatherer)) return Reset();

	_gatherer_client = std::weak_ptr<CommunicationsChannel>(_gatherer);
	_gatherer.reset();

	_start_check_timeout_ms = machine_tick_count();

	if (!NetGather(&_topology_message->topology()->game_data, sizeof(game_info), &_topology_message->topology()->players->player_data, sizeof(player_info), !_physics_message, false))
	{
		return Reset();
	}

	if (!GatherJoiners())
	{
		NetCancelGather();
		return Reset();
	}

	gathering_done = true;
	return true;
}

bool StandaloneHub::GotGatherer()
{
	if (_gatherer || !_gatherer_client.expired()) return true;

	_gatherer = std::shared_ptr<CommunicationsChannel>(_server->newIncomingConnection());

	if (!_gatherer) return false;

	NetSetDefaultInflater(_gatherer.get());

	auto gatherer_request = std::unique_ptr<RemoteHubHostConnectMessage>(_gatherer->receiveSpecificMessage<RemoteHubHostConnectMessage>(3000u, 3000u));

	if (!gatherer_request)
	{
		_gatherer.reset();
		return false;
	}

	bool can_use_hub = gatherer_request->version() == kNetworkSetupProtocolID;

	if (can_use_hub)
	{
		auto gatherer_capabilities = std::unique_ptr<CapabilitiesMessage>(_gatherer->receiveSpecificMessage<CapabilitiesMessage>(5000u, 5000u));
		can_use_hub = gatherer_capabilities && CheckGathererCapabilities(gatherer_capabilities->capabilities());
	}

	_gatherer->enqueueOutgoingMessage(RemoteHubHostResponseMessage(can_use_hub));
	_gatherer->pumpSendingSide();

	if (!can_use_hub)
	{
		_gatherer.reset();
		return false;
	}

	return true;
}

bool StandaloneHub::CheckGathererCapabilities(const Capabilities* capabilities)
{
	return 
		capabilities->kStarVersion == Capabilities::kStarVersion &&
		capabilities->kGatherableVersion == Capabilities::kGatherableVersion &&
		capabilities->kLuaVersion == Capabilities::kLuaVersion &&
		capabilities->kZippedDataVersion == Capabilities::kZippedDataVersion &&
		capabilities->kNetworkStatsVersion == Capabilities::kNetworkStatsVersion;
}

bool StandaloneHub::Reset()
{
	auto port = _instance->_port;
	delete _instance;
	_instance = nullptr;
	return Init(port);
}

bool StandaloneHub::GatherJoiners()
{
	while (!_gatherer_client.expired() && !_start_game_signal && machine_tick_count() - _start_check_timeout_ms < _gathering_timeout_ms)
	{
		prospective_joiner_info player;
		NetCheckForNewJoiner(player, _server.get(), _gatherer_joined_as_client);
		sleep_for_machine_ticks(1);
	}

	return _start_game_signal;
}

bool StandaloneHub::SendMessageToGatherer(const Message& message)
{
	if (_gatherer_client.expired()) return false;

	if (auto gatherer = _gatherer_client.lock()) 
	{
		gatherer->enqueueOutgoingMessage(message);
		gatherer->pumpSendingSide();
	}
}

bool StandaloneHub::GetGameDataFromGatherer()
{
	_map_message.reset();
	_physics_message.reset();
	_lua_message.reset();

	if (auto client = _gatherer ? _gatherer : _gatherer_client.lock())
	{
		while (auto message = client->receiveMessage())
		{
			switch (message->type())
			{
				case kLUA_MESSAGE:
				case kZIPPED_LUA_MESSAGE:
					_lua_message = std::unique_ptr<LuaMessage>(static_cast<LuaMessage*>(message));
					break;
				case kPHYSICS_MESSAGE:
				case kZIPPED_PHYSICS_MESSAGE:
					_physics_message = std::unique_ptr<PhysicsMessage>(static_cast<PhysicsMessage*>(message));
					break;
				case kMAP_MESSAGE:
				case kZIPPED_MAP_MESSAGE:
					_map_message = std::unique_ptr<MapMessage>(static_cast<MapMessage*>(message));
					break;
				case kEND_GAME_DATA_MESSAGE:
					delete message;
					return _map_message != nullptr;
				default:
					delete message;
					break;
			}
		}
	}

	return false;
}

int StandaloneHub::GetMapData(uint8** data)
{
	if (!_map_message) return 0;

	*data = _map_message->buffer();
	return _map_message->length();
}

int StandaloneHub::GetPhysicsData(uint8** data)
{
	if (!_physics_message) return 0;

	*data = _physics_message->buffer();
	return _physics_message->length();
}

int StandaloneHub::GetLuaData(uint8** data)
{
	if (!_lua_message) return 0;

	*data = _lua_message->buffer();
	return _lua_message->length();
}