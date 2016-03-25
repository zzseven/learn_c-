 ///
 /// @file    EpollPoller.cc
 /// @author  zzseven
 /// @date    2016-03-24 23:11:26
 ///
 
#include "EpollPoller.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

using namespace std;

const int kInitNumber = 2048;

int createEpollFd()
{
	cout << "createEpollFd" << endl;	
	int fd = ::epoll_create1(0);
	if(-1 == fd)
	{
		perror("epoll_create1");
	}
	return fd;
}

void addEpollFd(int efd, int fd)
{
	cout << "addEpollFd" << endl;	
	struct epoll_event ev;
	cout << "efd = " << efd << "fd = " << fd << endl;
	ev.data.fd = fd;
	ev.events = EPOLLIN;
	int ret = ::epoll_ctl(efd, EPOLL_CTL_ADD, fd, &ev);
	if(-1 == ret)
	{
		perror("epoll_ctl add");
		exit(EXIT_FAILURE);
	}
}

void delEpollFd(int efd, int fd)
{
	struct epoll_event ev;
	ev.data.fd = fd;
	ev.events = EPOLLIN;
	int ret = ::epoll_ctl(efd, EPOLL_CTL_DEL, fd, &ev);
	if(-1 == ret)
	{
		perror("epoll_ctl add");
		exit(EXIT_FAILURE);
	}
}

size_t recvPeek(int sockfd, char * buff, size_t count)
{
	cout << "recvPeek" << endl;	
	int nread;
	do{
		cout << "recvloop" << endl;
		nread = ::recv(sockfd, buff, count, MSG_PEEK);
	}while(-1 == nread && errno == EINTR);
	return nread;
	
}


bool isConnectionClose(int sockfd)
{
	
	cout << "isConnection" << endl;	
	char buff[1024];
	int nread = recvPeek(sockfd, buff, 1024);
	if(-1 == nread)
	{
		perror("recvPeek");
		exit(EXIT_FAILURE);
	}
	return (0 == nread);
	
}


namespace wd
{

EpollPoller::EpollPoller(int listenfd)
: _epollfd(createEpollFd())
, _listenfd(listenfd)
, _isLooping(false)
, _eventList(kInitNumber)
{
	addEpollFd(_epollfd, _listenfd);
}

void EpollPoller::loop()
{
	if(!_isLooping)
	{
		_isLooping = true;
		while(_isLooping)
		{
			cout << "waitEpollfd()" << endl;
			waitEpollfd();
		}
	}
	
}


void EpollPoller::unloop()
{
	if(_isLooping)
	{
		_isLooping = false;
	}
}

void EpollPoller::waitEpollfd()
{
	int nready;
	do{
		nready = epoll_wait(_epollfd, &(*_eventList.begin()), _eventList.size(), 5000);
	
	}while(nready == -1 && errno == EINTR);
	cout << "waitEpofd.nready=" << nready << endl;
	if(-1 == nready)
	{
		perror("epoll_wait");
		exit(EXIT_FAILURE);
	
	}else if(0 == nready)
	{
		printf("epoll_wait timeout!\n");
	}
	else
	{
		if(nready == static_cast<int>(_eventList.size()))
		{
			_eventList.resize(nready * 2);
		}

		for(int idx = 0; idx != nready; ++idx)
		{
			if(_eventList[idx].data.fd == _listenfd)
			{
				if(_eventList[idx].events && EPOLLIN)
				{
					std::cout << "handleConnection" << std::endl;
					handleConnection();
					std::cout << "handleConnection---OUT" << std::endl;
				}
			}else
			{
				if(_eventList[idx].events && EPOLLIN)
				{
					handleMessage(_eventList[idx].data.fd);
				}
			}	
		}
	}
}

void EpollPoller::handleConnection()
{
	int peerfd = ::accept(_listenfd, NULL, NULL);
	if(-1 == peerfd)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}

	addEpollFd(_epollfd, peerfd);

	TcpConnectionPtr pConn(new TcpConnection(peerfd));
	cout << "s1" << endl;
	pConn->setConnectionCallback(_onConnection);
	cout << "22" << endl;
	pConn->setMessageCallback(_onMessage);
	cout << "33" << endl;
	pConn->setCloseCallback(_onClose);
	cout << "44" << endl;
	_connMap[peerfd] = pConn;
	pConn->handleConnectionCallback();
	cout << "55" << endl;
}

void EpollPoller::handleMessage(int fd)
{
	bool isClosed  = isConnectionClose(fd);
	map<int, TcpConnectionPtr>::iterator it = _connMap.find(fd);
	assert(it != _connMap.end());

	if(isClosed)
	{
		it->second->handleCloseCallback();
		delEpollFd(_epollfd, fd);
		_connMap.erase(it);
	}
	else
	{
		it->second->handleMessageCallback();
	}
}


void EpollPoller::setConnectionCallback(EpollPollerCallback cb)
{
	_onConnection = cb;
}

void EpollPoller::setMessageCallback(EpollPollerCallback cb)
{
	_onMessage = cb;
}

void EpollPoller::setCloseCallback(EpollPollerCallback cb)
{
	_onClose = cb;
}





}

