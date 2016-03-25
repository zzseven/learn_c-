 //
 /// @file    Thread.h
 /// @author  zzseven
 /// @date    2016-03-20 13:34:24
 ///
 
#ifndef _MY_THREAD_H_
#define _MY_THREAD_H_

#include "Noncopyable.h"
#include <pthread.h>
#include <functional>



//namespace wd
//{

//class Noncopyable
//{
//protected:
//	Noncopyable(){}
//
//private:
//	Noncopyable(const Noncopyable & rhs);
//	Noncopyable & operator=(const Noncopyable &rhs);
//};


namespace wd
{
class Thread : private Noncopyable//实现继承== public:接口继承
{
public:
	typedef std::function<void()> ThreadCallback;
	Thread(ThreadCallback cb);
	~Thread();

	void start();
	void join();
	static void * threadFunc(void *);
private:
	pthread_t _pthId;
	bool _isRunning;
	ThreadCallback _cb;
};


} //end of namespace wd

#endif
