 ///
 /// @file    TestThread.cc
 /// @author  zzseven
 /// @date    2016-03-21 15:08:15
 ///
 
#include "TestThread.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <iostream>


using std::cout;
using std::endl;

namespace wd
{
void TestThread::run()
{
	srand(time(NULL));
	while(true)
	{
		int num = rand() % 100;
		cout << "num = " << num << endl;
		sleep(1);
	}
}


}// end of namespace wd
