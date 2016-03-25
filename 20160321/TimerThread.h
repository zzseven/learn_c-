 ///
 /// @file    TimerThread.h
 /// @author  zzseven
 /// @date    2016-03-22 23:33:33
 ///
 
#ifndef __TIMERTHREAD_H_
#define __TIMERTHREAD_H_

#include "Thread.h"
#include "Timer.h"
#include <functional>

namespace wd
{

class TimerThread
{
public:
	typedef std::function<void()> TimerThreadCallback;
	TimerThread(TimerThreadCallback cb, int init_sec, int interval_sec);
	void start();
	void stop();
private:
	Timer _timer;
	Thread _thread;
};

}

#endif
