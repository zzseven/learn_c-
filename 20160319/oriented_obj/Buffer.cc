 ///
 /// @file    Buffer.cc
 /// @author  zzseven
 /// @date    2016-03-21 16:21:29
 ///
 
#include "Buffer.h"

namespace wd
{
Buffer::Buffer(int size)
: _size(size)
, _mutex()
, _notFull(_mutex)
, _notEmpty(_mutex)
{

}

Buffer::~Buffer()
{
}

bool Buffer::full()
{
	return _size == _que.size();
}

bool Buffer::empty()
{
	return 0 == _que.size();
}

void Buffer::push(Task * ptask)
{
	MutexLockGuard mlg(_mutex);
	while(full())    //为了避免被异常唤醒
	{
		_notFull.wait();
	}
	_que.push(ptask);

	_notEmpty.notify();
}

Task * Buffer::pop()
{
	MutexLockGuard mlg(_mutex);
	while(empty())
	{
		_notEmpty.wait();
	}

	Task * ptask = _que.front();
	_que.pop();

	_notFull.notify();
	return ptask;
}

} // end of namespace wd
