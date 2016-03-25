 ///
 /// @file    TcpConnection.cc
 /// @author  zzseven
 /// @date    2016-03-24 21:57:17
 ///
 
#include "TcpConnection.h"
#include <string.h>
#include <iostream>
#include <sstream>

namespace wd
{
TcpConnection::TcpConnection(int fd)
: _sock(fd)
, _sockIO(fd)
, _localAddr(Socket::getLocalAddr(fd))
, _peerAddr(Socket::getPeerAddr(fd))
, _isShutdownWrite(false)
{

}

TcpConnection::~TcpConnection()
{
	if(!_isShutdownWrite)
	{
		shutdown();
	}
}

std::string TcpConnection::receive()
{
	std::cout << "TcpConnection::recvive" << std::endl;
	char buff[100];
	memset(buff, 0, 100);
	_sockIO.readline(buff, 100);
	return std::string(buff);
}

void TcpConnection::send(const std::string & msg)
{
	std::cout << "TcpConnection::send" << std::endl;
	_sockIO.writen(msg.c_str(), msg.size());
}

void TcpConnection::shutdown()
{
	if(!_isShutdownWrite)
	{
		_isShutdownWrite = true;
		_sock.shutdownWrite();
	}

}	

std::string TcpConnection::toString() const
{
	std::ostringstream oss;
	oss << _localAddr.ip() << " : " << _localAddr.port()
		<< "---->"
		<< _peerAddr.ip() << " : " << _peerAddr.port()
		<< " ";
	return oss.str();
}


void TcpConnection::setConnectionCallback(TcpConnectionCallback cb)
{
	_onConnectionCb = cb;
}

void TcpConnection::setMessageCallback(TcpConnectionCallback cb)
{
	_onMessageCb = cb;
}

void TcpConnection::setCloseCallback(TcpConnectionCallback cb)
{
	_onCloseCb = cb;
}

void TcpConnection::handleConnectionCallback()
{
	if(_onConnectionCb)
		_onConnectionCb(shared_from_this());
}

void TcpConnection::handleMessageCallback()
{
	if(_onMessageCb)
		_onMessageCb(shared_from_this());
}


void TcpConnection::handleCloseCallback()
{
	if(_onCloseCb)
		_onCloseCb(shared_from_this());
}



}
