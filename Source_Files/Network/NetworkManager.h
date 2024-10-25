/*
    Copyright (C) 2024 Benoit Hauquier and the "Aleph One" developers.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    This license is contained in the file "COPYING",
    which is included with this source code; it is available online at
    http://www.gnu.org/licenses/gpl.html
*/

#ifndef NETWORK_MANAGER_H
#define NETWORK_MANAGER_H

#include <asio.hpp>
#ifdef __WIN32__
#undef CreateDirectory
#endif
#include <string>
#include <optional>

class IPaddress {
private:
    friend class NetworkManager;
    friend class UDPsocket;
    friend class TCPsocket;

    asio::ip::address _address;
    uint16_t _port = 0;

    IPaddress(const asio::ip::tcp::endpoint& endpoint);
    IPaddress(const asio::ip::udp::endpoint& endpoint);

public:
    IPaddress(const std::string& host, uint16_t port);
    IPaddress(const uint8_t ip[4], uint16_t port);
    IPaddress() = default;
    bool is_v4() const { return _address.is_v4(); }
    std::string address() const { return _address.to_string(); }
    std::array<unsigned char, 4> IPaddress::address_bytes() const { return _address.to_v4().to_bytes(); }
    uint16_t port() const { return _port; }
    void set_port(uint16_t port);
    void set_address(const std::string& host);
    void set_address(const uint8_t ip[4]);
};

/* missing from AppleTalk.h */
// ZZZ: note that this determines only the amount of storage allocated for packets, not
// the size of actual packets sent.  I believe UDP on Ethernet should be able to carry
// around 1.5K per packet, not sure of the exact figure off the top of my head though.
#define ddpMaxData 1500

struct UDPpacket
{
    IPaddress address;
    std::array<uint8_t, ddpMaxData> buffer;
    int data_size;
};

class UDPsocket {
private:
    asio::io_service& _io_context;
    asio::ip::udp::socket _socket;
    UDPsocket(asio::io_service& io_context, const asio::ip::udp::endpoint& endpoint);
    friend class NetworkManager;
public:
    int64_t broadcast_send(const UDPpacket& packet);
    int64_t send(const UDPpacket& packet);
    int64_t receive(UDPpacket& packet);
    int64_t check();
    bool broadcast(bool enable);
};

class TCPsocket {
private:
    asio::io_service& _io_context;
    asio::ip::tcp::acceptor _acceptor;
    asio::ip::tcp::socket _socket;
    TCPsocket(asio::io_service& io_context, const asio::ip::tcp::endpoint& endpoint);
    TCPsocket(asio::io_service& io_context, asio::ip::tcp::socket&& socket);
    friend class NetworkManager;
public:
    int64_t send(uint8_t* buffer, size_t size);
    int64_t receive(uint8_t* buffer, size_t size);
    IPaddress remote_address() const { return IPaddress(_socket.remote_endpoint()); }
    std::unique_ptr<TCPsocket> accept_connection();
};

class NetworkManager {
private:
    asio::io_service _io_context;
    asio::ip::tcp::resolver _resolver;
public:
    NetworkManager::NetworkManager();
    std::unique_ptr<UDPsocket> open_udp_socket(uint16_t port);
    std::unique_ptr<TCPsocket> connect_tcp_socket(const IPaddress& address);
    std::unique_ptr<TCPsocket> open_tcp_socket(uint16_t port);
    std::optional<IPaddress> NetworkManager::resolve(const std::string& host, uint16_t port);
};

#endif // NETWORK_MANAGER_H