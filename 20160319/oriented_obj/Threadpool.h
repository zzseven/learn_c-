 ///
 /// @file    Threadpool.h
 /// @author  zzseven
 /// @date    2016-03-21 20:13:57
 ///
 
#ifndef _MY_THREADPOOL_H_
#define _MY_THREADPOOL_H_
#include "Buffer.h"
#include <vector>

using std::vector;

namespace wd
{
class Task;
class Thread;
class Threadpool
{
public:
	Threadpool(int threadNum, int bufSize);
	~Threadpool();

	void start();
	void stop();

	void addTask(Task * ptask);

	void threadFunc();
private:
	Task * getTask();
private:
	int _threadNum;
	vector<Thread *> _vecThreads;
	int _bufSize;
	Buffer _buf;
	bool _isExit;
};

} //end of namesapce wd

#endif
