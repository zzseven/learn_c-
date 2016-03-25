 ///
 /// @file    MutexLock.h
 /// @author  zzseven
 /// @date    2016-03-21 15:38:52
 ///
 
#ifndef __MY_MUTEXLOCK_H_
#define __MY_MUTEXLOCK_H_

#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{
class MutexLock : Noncopyable
{
public:
	MutexLock();
	~MutexLock();

	void lock();
	void unlock();
	pthread_mutex_t * getMutexLockPtr();
private:
	pthread_mutex_t _mutex;
	bool _isLocking;
};

class MutexLockGuard
{
public:
	MutexLockGuard(MutexLock & mutex)
	: _mutex(mutex)
	{
		_mutex.lock();
	}

	~MutexLockGuard()
	{
		_mutex.unlock();
	}
private:
	MutexLock & _mutex;
};

}//end of namespace wd


#endif
