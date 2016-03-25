 ///
 /// @file    Thread.cc
 /// @author  zzseven
 /// @date    2016-03-22 20:05:16
 ///
 
#include "Thread.h"
#include <iostream>


namespace wd
{

Thread::Thread(ThreadCallback cb)
: _cb(cb)
, _pId(0)
, _isRunning(false)
{ }

Thread::~Thread()
{
	if(_isRunning)
		pthread_detach(_pId);
}

void Thread::start()
{
	pthread_create(&_pId, NULL, &Thread::threadFunc, this);
	_isRunning = true;
}

void Thread::join()
{
	if(_isRunning)
		pthread_join(_pId, NULL);
}

void* Thread::threadFunc(void * arg)
{
	Thread * pThread = static_cast<Thread *>(arg);
	if(pThread)
		pThread->_cb();
}
	
}
