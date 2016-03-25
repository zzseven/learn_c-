 //
 /// @file    Thread.h
 /// @author  zzseven
 /// @date    2016-03-20 13:34:24
 ///
 
#ifndef _MY_THREAD_H_
#define _MY_THREAD_H_

#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{
class Thread : private Noncopyable//实现继承== public:接口继承
{
public:
	Thread();
	~Thread();

	void start();
	void join();
private:
	virtual void run()=0;
private:
	static void * threadFunc(void *);
private:
	pthread_t _pthId;
	bool _isRunning;
};


} //end of namespace wd

#endif
