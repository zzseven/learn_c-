 ///
 /// @file    ThreadpoolThread.h
 /// @author  zzseven
 /// @date    2016-03-21 20:06:40
 ///
 
#ifndef _MY_THREADPOOLTHREAD_H_
#define _MY_THREADPOOLTHREAD_H_
#include "Thread.h"
#include <iostream>

namespace wd
{
class Threadpool;
class ThreadpoolThread : public Thread
{
public:
	ThreadpoolThread(Threadpool & threadpool);
	void run();
private:
	Threadpool & _threadpool;
};


}//end of namespace wd

#endif
