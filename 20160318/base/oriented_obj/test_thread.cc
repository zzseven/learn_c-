 ///
 /// @file    test_thread.cc
 /// @author  zzseven
 /// @date    2016-03-21 15:02:24
 ///
 
#include "TestThread.h"
#include <iostream>

int main(void)
{
	wd::Thread * pThread = new wd::TestThread;
	pThread->start();
	pThread->join();

	return 0;
}
