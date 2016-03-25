 ///
 /// @file    Socket.h
 /// @author  zzseven
 /// @date    2016-03-24 14:18:20
 ///
 
#ifndef __SOCKET_H_
#define __SOCKET_H_

namespace wd
{
class InetAddress;

class Socket
{
public:
	Socket();
	Socket(int);
	int accept();
	int fd();
	void ready(InetAddress & addr);

	void shutdownWrite();

	static InetAddress getLocalAddr(int fd);
	static InetAddress getPeerAddr(int fd);

private:
	void setReuseAddr(bool flag);
	void setReusePort(bool flag);
	void bind(InetAddress & adr);
	void listen();

private:
	int _fd;
};
}



#endif

