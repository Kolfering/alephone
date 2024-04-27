#ifndef __NETWORK_SERVER_H
#define __NETWORK_SERVER_H

#include "MessageInflater.h"
#include "network_messages.h"

class NetworkServer {
private:
	static NetworkServer* _instance;
	std::unique_ptr<CommunicationsChannelFactory> _server;
	std::shared_ptr<CommunicationsChannel> _gatherer;
	std::weak_ptr<CommunicationsChannel> _gatherer_client;
	std::unique_ptr<TopologyMessage> _topology_message;
	std::unique_ptr<LuaMessage> _lua_message;
	std::unique_ptr<MapMessage> _map_message;
	std::unique_ptr<PhysicsMessage> _physics_message;
	int _port;
	bool _start_game_signal = false;
	NetworkServer(short port);
	bool GetGameDataFromGatherer();
public:
	bool GatherJoiners();
	bool SetupGathererGame();
	static bool InstantiateNetworkServer(short port);
	static NetworkServer* Instance() { return _instance; }
	CommunicationsChannel* GetGathererChannel() const { return _gatherer ? _gatherer.get() : _gatherer_client.lock().get(); }
	bool SendMessageToGatherer(const Message& message);
	void StartGame() { _start_game_signal = true; }
	void Reset();
};

#endif