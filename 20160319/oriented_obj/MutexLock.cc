 ///
 /// @file    MutexLock.cc
 /// @author  zzseven
 /// @date    2016-03-21 15:46:40
 ///
 
#include "MutexLock.h"
#include <iostream>

namespace wd
{
MutexLock::MutexLock()
: _isLocking(false)
{
	pthread_mutex_init(&_mutex, NULL);
}

MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&_mutex);
}

void MutexLock::lock()
{
	pthread_mutex_lock(&_mutex);
	_isLocking = true;
}

void MutexLock::unlock()
{
	pthread_mutex_unlock(&_mutex);
	_isLocking = false;
}

pthread_mutex_t * MutexLock::getMutexLockPtr()
{
	return &_mutex;
}


}// end of namespace wd
