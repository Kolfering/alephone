#include "NetworkServer.h"

NetworkServer* NetworkServer::_instance = nullptr;

bool NetworkServer::InitNetworkServer(short port)
{
	if (_instance) return true;
	_instance = new NetworkServer(port);
	return NetEnter(false);
}

NetworkServer::NetworkServer(short port)
{
	_port = port;
	_server = std::make_unique<CommunicationsChannelFactory>(port);
}

NetworkServer::~NetworkServer()
{
	NetExit();
}

bool NetworkServer::SetupGathererGame(bool& gathering_done)
{
	gathering_done = false;

	if (!_gatherer && _gatherer_client.expired())
	{
		_gatherer = std::shared_ptr<CommunicationsChannel>(_server->newIncomingConnection());

		if (!_gatherer) return true;
		NetSetDefaultInflater(_gatherer.get());
	}

	_topology_message = std::unique_ptr<TopologyMessage>(static_cast<TopologyMessage*>(_gatherer->receiveSpecificMessage<TopologyMessage>())); //yaaay

	if (!_topology_message || !GetGameDataFromGatherer()) return Reset();

	SetNetscriptStatus(_lua_message.get());

	_gatherer->enqueueOutgoingMessage(DedicatedServerReadyMessage());

	if (!NetProcessNewJoiner(_gatherer)) return Reset();

	_gatherer_client = std::weak_ptr<CommunicationsChannel>(_gatherer);
	_gatherer.reset();

	_start_check_timeout_ms = machine_tick_count();

	bool success = NetworkGatherCore(&_topology_message->topology()->game_data, &_topology_message->topology()->players->player_data, false, !_physics_message, false, false);

	if (!success) return Reset();

	gathering_done = true;
	return success;
}

bool NetworkServer::Reset()
{
	auto port = _instance->_port;
	delete _instance;
	_instance = nullptr;
	return InitNetworkServer(port);
}

bool NetworkServer::GatherJoiners()
{
	while (!_gatherer_client.expired() && !_start_game_signal && machine_tick_count() - _start_check_timeout_ms < _gathering_timeout_ms)
	{
		//MetaserverClient::pumpAll();
		GathererAvailableAnnouncer::pump();
		prospective_joiner_info player;
		NetCheckForNewJoiner(player, _server.get(), _gatherer_joined_as_client);
	}

	return _start_game_signal;
}

bool NetworkServer::SendMessageToGatherer(const Message& message)
{
	if (_gatherer_client.expired()) return false;

	if (auto gatherer = _gatherer_client.lock()) 
	{
		gatherer->enqueueOutgoingMessage(message);
		gatherer->pumpSendingSide();
	}
}

bool NetworkServer::GetGameDataFromGatherer()
{
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

int NetworkServer::GetMapData(uint8** data)
{
	if (!_map_message) return 0;

	*data = _map_message->buffer();
	return _map_message->length();
}

int NetworkServer::GetPhysicsData(uint8** data)
{
	if (!_physics_message) return 0;

	*data = _physics_message->buffer();
	return _physics_message->length();
}

int NetworkServer::GetLuaData(uint8** data)
{
	if (!_lua_message) return 0;

	*data = _lua_message->buffer();
	return _lua_message->length();
}