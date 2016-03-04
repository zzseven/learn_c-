 ///
 /// @file    Condition.h
 /// @author  zzseven
 /// @date    2016-03-03 22:50:15
 ///

#ifndef __CONDITION_H__
#define __CONDITION_H__


#include <iostream>

class MutexLock; //前向声明

class Condition
{
public:
	Condition(MutexLock & mutex)
	~Condition();

	void wait()
	void notify()
	void notifyAll();
private:
	pthread_cond_t _cond;
	MutexLock & _mutex;
}

#endif
