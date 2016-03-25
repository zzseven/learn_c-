 ///
 /// @file    test_socket.cc
 /// @author  zzseven
 /// @date    2016-03-24 14:56:39
 ///
 
#include "Socket.h"
#include "InetAddress.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

using namespace wd;

int main(void)
{
	Socket sock;
	InetAddress addr(8888);
	sock.ready(addr);


	int peerfd = sock.accept();
	printf("%s:%d --> %s:%d \n", Socket::getLocalAddr(peerfd).ip().c_str(),
								 Socket::getLocalAddr(peerfd).port(),
								 Socket::getPeerAddr(peerfd).ip().c_str(),
								 Socket::getPeerAddr(peerfd).port());
	char buff[1024] = "welcome to server.";

	int ret = write(peerfd, buff, strlen(buff));
	while(true)
	{
		memset(buff, 0, sizeof(buff));
		read(peerfd, buff, 1024);
		write(peerfd, buff, strlen(buff));
	}

	return 0;

}
