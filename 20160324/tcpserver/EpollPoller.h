 ///
 /// @file    EpollPoller.h
 /// @author  zzseven
 /// @date    2016-03-24 22:49:09
 ///
 
#ifndef __EPOLLPOLLER_H_
#define __EPOLLPOLLER_H_
#include "Noncopyable.h"
#include "TcpConnection.h"
#include <sys/epoll.h>
#include <vector>
#include <map>
#include <functional>


using std::vector;
using std::map;

namespace wd
{
class EpollPoller : Noncopyable
{

public:
	typedef std::function<void(TcpConnectionPtr)> EpollPollerCallback;
	EpollPoller(int listenfd);

	void loop();
	void unloop();

	void setConnectionCallback(EpollPollerCallback cb);
	void setMessageCallback(EpollPollerCallback cb);
	void setCloseCallback(EpollPollerCallback cb);
private:
	void waitEpollfd();
	void handleConnection();
	void handleMessage(int fd);

private:
	int _epollfd;
	int _listenfd;
	bool _isLooping;

	vector<struct epoll_event> _eventList;
	map<int, TcpConnectionPtr> _connMap;

	EpollPollerCallback _onConnection;
	EpollPollerCallback _onMessage;
	EpollPollerCallback _onClose;

};


}


#endif
