 ///
 /// @file    test_socket.cc
 /// @author  zzseven
 /// @date    2016-03-25 00:15:55
 ///
 
#include "Socket.h"
#include "InetAddress.h"
#include "TcpConnection.h"
#include "EpollPoller.h"
#include "TcpServer.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <iostream>


using namespace wd;
using std::cout;
using std::endl;

void onConnection(TcpConnectionPtr conn)
{
	cout << conn->toString() << "has connected!" << endl;
	cout << "hihihihihihih!" << endl;
	conn->send("welcome to server.\n");
}

void onMessage(TcpConnectionPtr conn)
{
	std::string msg =  conn->receive();
	cout << "messmess" << endl;
	cout << msg << endl;
	conn->send(msg);
}


void onClose(TcpConnectionPtr conn)
{
	cout << conn->toString() << "hase close." << endl;
}


int main(void)
{
#if 0
	Socket sock;
	InetAddress addr(8888);
	sock.ready(addr);
	EpollPoller epollPoller(sock.fd());
	epollPoller.setConnectionCallback(onConnection);
	epollPoller.setMessageCallback(onMessage);
	epollPoller.setCloseCallback(onClose);
	epollPoller.loop();
#endif

	TcpServer tcpserver(8888);
	tcpserver.setConnectionCallback(onConnection);
	tcpserver.setMessageCallback(onMessage);
	tcpserver.setCloseCallback(onClose);
	
	tcpserver.start();


	return 0;
}
