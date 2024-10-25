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

#include "NetworkManager.h"

IPaddress::IPaddress(const asio::ip::tcp::endpoint& endpoint)
{
    _address = endpoint.address();
    set_port(endpoint.port());
}

IPaddress::IPaddress(const asio::ip::udp::endpoint& endpoint)
{
    _address = endpoint.address();
    set_port(endpoint.port());
}

IPaddress::IPaddress(const std::string& host, uint16_t port)
{
    set_address(host);
    set_port(port);
}

IPaddress::IPaddress(const uint8_t ip[4], uint16_t port)
{
    set_address(ip);
    set_port(port);
}

void IPaddress::set_port(uint16_t port)
{
    _port = port;
}

void IPaddress::set_address(const std::string& host)
{
    _address = asio::ip::make_address(host);
}

void IPaddress::set_address(const uint8_t ip[4])
{
    std::array<unsigned char, 4> bytes = { ip[0], ip[1], ip[2], ip[3] };
    _address = asio::ip::make_address_v4(bytes);
}

UDPsocket::UDPsocket(asio::io_service& io_context, const asio::ip::udp::endpoint& endpoint) : _io_context(io_context), _socket(io_context, endpoint) {}

int64_t UDPsocket::send(const UDPpacket& packet)
{
    asio::error_code error_code;
    asio::ip::udp::endpoint destination(packet.address._address, packet.address.port());
    auto result = _socket.send_to(asio::buffer(packet.buffer, packet.data_size), destination, 0, error_code);
    return error_code ? -1 : result;
}

int64_t UDPsocket::broadcast_send(const UDPpacket& packet)
{
    asio::error_code error_code;
    asio::ip::udp::endpoint broadcast_endpoint(asio::ip::address_v4::broadcast(), packet.address.port());
    auto result = _socket.send_to(asio::buffer(packet.buffer, packet.data_size), broadcast_endpoint, 0, error_code);
    return error_code ? -1 : result;
}

int64_t UDPsocket::receive(UDPpacket& packet)
{
    if (!check()) return 0;
    asio::error_code error_code;
    asio::ip::udp::endpoint endpoint;
    auto result = _socket.receive_from(asio::buffer(packet.buffer), endpoint, 0, error_code);
    if (error_code) return -1;
    packet.address = endpoint;
    packet.data_size = result;
    return result;
}

bool UDPsocket::broadcast(bool enable)
{
    asio::error_code error_code;
    _socket.set_option(asio::socket_base::broadcast(enable), error_code);
    return !error_code;
}

int64_t UDPsocket::check()
{
    return _socket.available();
}

TCPsocket::TCPsocket(asio::io_service& io_context, const asio::ip::tcp::endpoint& endpoint) : _io_context(io_context),  _socket(io_context), _acceptor(io_context, endpoint) 
{
    _acceptor.non_blocking(true);
}

TCPsocket::TCPsocket(asio::io_service& io_context, asio::ip::tcp::socket&& socket) : _io_context(io_context), _socket(std::move(socket)), _acceptor(io_context) 
{
    _socket.non_blocking(true);
}

int64_t TCPsocket::send(uint8_t* buffer, size_t size)
{
    asio::error_code error_code;
    auto result = _socket.send(asio::buffer(buffer, size), 0, error_code);
    return !error_code || error_code == asio::error::would_block ? result : -1;
}

int64_t TCPsocket::receive(uint8_t* buffer, size_t size)
{
    asio::error_code error_code;
    auto result = _socket.read_some(asio::buffer(buffer, size), error_code);
    return !error_code || error_code == asio::error::would_block ? result : -1;
}

std::unique_ptr<TCPsocket> TCPsocket::accept_connection()
{
    asio::error_code error_code;
    _acceptor.accept(_socket, error_code);
    if (error_code) return nullptr;

    auto connection = std::unique_ptr<TCPsocket>(new TCPsocket(_io_context, std::move(_socket)));
    _socket = asio::ip::tcp::socket(_io_context);
    return connection;
}

NetworkManager::NetworkManager() : _io_context(), _resolver(_io_context) {}

std::unique_ptr<UDPsocket> NetworkManager::open_udp_socket(uint16_t port)
{
    return  std::unique_ptr<UDPsocket>(new UDPsocket(_io_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), port)));
}

std::unique_ptr<TCPsocket> NetworkManager::open_tcp_socket(uint16_t port)
{
    return std::unique_ptr<TCPsocket>(new TCPsocket(_io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)));
}

std::unique_ptr<TCPsocket> NetworkManager::connect_tcp_socket(const IPaddress& address)
{
    auto socket = asio::ip::tcp::socket(_io_context);
    asio::error_code error_code;
    socket.connect(asio::ip::tcp::endpoint(address._address, address.port()), error_code);
    if (error_code) return nullptr;
    return std::unique_ptr<TCPsocket>(new TCPsocket(_io_context, std::move(socket)));
}

std::optional<IPaddress> NetworkManager::resolve(const std::string& host, uint16_t port)
{
    asio::error_code error_code;
    asio::ip::tcp::resolver::results_type endpoints = _resolver.resolve(host, std::to_string(port), error_code);
    if (error_code) return std::nullopt;

    for (const auto& endpoint : endpoints)
    {
        if (endpoint.endpoint().address().is_v4())
        {
            return IPaddress(endpoint.endpoint());
        }
    }

    return std::nullopt;
}