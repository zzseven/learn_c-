 ///
 /// @file    test_threadpool.cc
 /// @author  zzseven
 /// @date    2016-03-21 20:40:55
 ///
 
#include "Threadpool.h"
#include "Task.h"
#include <unistd.h>

int main(void)
{
	wd::Task *ptask = new wd::MyTask;

	wd::Threadpool threadpool(4, 10);
	threadpool.start();
	int cnt = 20;
	while(cnt--)
	{
		threadpool.addTask(ptask);
	}

	threadpool.stop();

	sleep(10);
	return 0;
}
