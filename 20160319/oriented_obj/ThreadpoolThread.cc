 ///
 /// @file    ThreadpoolThread.cc
 /// @author  zzseven
 /// @date    2016-03-21 20:09:50
 ///
 
#include "ThreadpoolThread.h"
#include "Threadpool.h"

namespace wd
{
ThreadpoolThread::ThreadpoolThread(Threadpool & threadpool)
: _threadpool(threadpool)
{}

void ThreadpoolThread::run()
{
	_threadpool.threadFunc();
}

}// end of namespace wd
