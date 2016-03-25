 ///
 /// @file    Condition.h
 /// @author  zzseven
 /// @date    2016-03-21 15:43:17
 ///
 
#ifndef __MY_CONDITION_H_
#define __MY_CONDITION_h_

#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{

class MutexLock;

class Condition : Noncopyable
{
public:
	Condition(MutexLock & mutex);
	~Condition();

	void wait();
	void notify();
	void notifyAll();
private:
	pthread_cond_t _cond;
	MutexLock & _mutex;
};


}// end of namespace wd

#endif
