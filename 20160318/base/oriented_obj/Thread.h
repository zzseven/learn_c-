 ///
 /// @file    Thread.h
 /// @author  zzseven
 /// @date    2016-03-21 14:51:24
 ///
 

#ifndef _MY_THREAD_H_
#define _MY_THREAD_H_

#include "Noncopyable.h"
#include <pthread.h>


namespace wd
{
class Thread : private Noncopyable //实现继承 == public:接口继承
{
public:
	Thread();
	~Thread();

	void start();
	void join();
private:
	virtual void run() = 0;  //纯虚函数
	static void * threadFunc(void *);
	pthread_t _pthId;
	bool _isRunning;
};

}//end of namespace wd

#endif
