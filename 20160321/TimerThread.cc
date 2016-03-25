 ///
 /// @file    TimerThread.cc
 /// @author  zzseven
 /// @date    2016-03-23 19:18:02
 ///
 
#include "TimerThread.h"

namespace wd
{

TimerThread::TimerThread(TimerThreadCallback cb, int init_sec, int interval_sec)
: _timer(cb, init_sec, interval_sec)
, _thread(std::bind(&Timer::start, &_timer))
{

}

void TimerThread::start()
{
	_thread.start();
}

void TimerThread::stop()
{
	_timer.stop();
}

}
