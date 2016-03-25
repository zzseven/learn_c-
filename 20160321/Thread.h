 ///
 /// @file    Thread.h
 /// @author  zzseven
 /// @date    2016-03-22 19:59:46
 ///

#ifndef __MY_THREAD_H_
#define __MY_THREAD_H_

#include "Noncopyable.h"
#include <pthread.h>
#include <functional>

namespace wd
{

class Thread : Noncopyable
{
public:
	typedef std::function<void()> ThreadCallback;
	Thread(ThreadCallback cb);
	~Thread();

	void start();
	void join();
	static void* threadFunc(void *);

private:
	pthread_t _pId;
	bool _isRunning;
	ThreadCallback _cb;
};

}

#endif
