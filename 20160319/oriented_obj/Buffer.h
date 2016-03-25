 ///
 /// @file    Buffer.h
 /// @author  zzseven
 /// @date    2016-03-21 15:34:56
 ///
 

#ifndef __MY_BUFFER_H_
#define __MY_BUFFER_H_


#include "MutexLock.h"
#include "Condition.h"

#include <queue>

namespace wd
{
	
class Task;
class Buffer
{
public:
	Buffer(int size);
	~Buffer();

	void push(Task * ptask);
	Task * pop();

	bool full();
	bool empty();

private:
	int _size;
	std::queue<Task *> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
};


}//end of namespace wd

#endif 
