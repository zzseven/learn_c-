 ///
 /// @file    InetAddress.cc
 /// @author  zzseven
 /// @date    2016-03-23 22:47:02
 ///
 
#include "InetAddress.h"

#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

namespace wd
{

InetAddress::InetAddress(unsigned short port)
{
	memset(&_addr, 0, sizeof(struct sockaddr_in));
	_addr.sin_family = AF_INET;
	_addr.sin_port = htons(port);
	_addr.sin_addr.s_addr = INADDR_ANY;
}

InetAddress::InetAddress(const char * ip, unsigned short port)
{
	memset(&_addr, 0, sizeof(struct sockaddr_in));
	_addr.sin_family = AF_INET;
	_addr.sin_port = htons(port);
	_addr.sin_addr.s_addr = inet_addr(ip);
}

InetAddress::InetAddress(const struct sockaddr_in & addr)
: _addr(addr)
{}

struct sockaddr_in * InetAddress::getInetAddressPtr()
{
	return &_addr;
}

std::string InetAddress::ip()
{
	return std::string(inet_ntoa(_addr.sin_addr));
}

unsigned short InetAddress::port()
{
	return ntohs(_addr.sin_port);
}


}// end of namespace wd

