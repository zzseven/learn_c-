 ///
 /// @file    InetAddress.h
 /// @author  zzseven
 /// @date    2016-03-23 22:38:30
 ///
 
#ifndef __MY_INETADDRESS_H_
#define __MY_INETADDRESS_H_

#include <netinet/in.h>
#include <string>
#include <iostream>

namespace wd
{

class InetAddress
{
public:
	InetAddress(unsigned short port);
	InetAddress(const char * ip, unsigned short port);
	InetAddress(const struct sockaddr_in & addr);


	struct sockaddr_in * getInetAddressPtr();
	
	std::string ip();
	unsigned short port();

private:
	struct sockaddr_in _addr;
};

}//end of namespace wd
#endif
