 ///
 /// @file    Timer.h
 /// @author  zzseven
 /// @date    2016-03-22 23:39:04
 ///


#ifndef __MY_TIME_H_
#define __MY_TIME_H_
#include "Noncopyable.h"
#include <iostream>
#include <functional>

namespace wd
{

class Timer: Noncopyable
{
public:
	typedef std::function<void()> TimerCallback;
	Timer(TimerCallback cb, int int_sec, int interval_sec);
	~Timer();

	void start();
	void stop();

private:
	int _fd;
	TimerCallback _cb;
	bool _isStarted;
};

}
 

#endif
