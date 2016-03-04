 ///
 /// @file    MutexLock.h
 /// @author  zzseven
 /// @date    2016-03-03 22:53:10
 ///
 
#ifndef __MUTEX_LOCK_H__
#define __MUTEX_LOCK_H__

#include <iostream>

class MutexLock
{
public:
	MutexLock();
	~MutexLock();
	void lock();
	void unlock();

	pthread_mutex_t * getMutexptr();
private:
	pthread_mutex_t _mutex;
}

#endif
