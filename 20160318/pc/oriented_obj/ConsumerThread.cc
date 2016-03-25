 ///
 /// @file    ConsumerThread.cc
 /// @author  zzseven
 /// @date    2016-03-21 17:02:13
 ///
 
#include "ConsumerThread.h"
#include "Buffer.h"
#include <stdio.h>
#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;

namespace wd
{
ConsumerThread::ConsumerThread(Buffer & buff)
: _buff(buff)
{}

void ConsumerThread::run()
{
	cout << "hi" << endl;
	while(true)
	{	cout << "2" << endl;
		//flockfile(stdout);
		printf("consumer num: %d\n", _buff.pop());
		//funlockfile(stdout);
		sleep(2);
	}
}

}// end of namespace wd
