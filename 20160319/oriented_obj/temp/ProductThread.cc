 ///
 /// @file    ProductThread.cc
 /// @author  zzseven
 /// @date    2016-03-21 17:15:55
 ///
 
#include "ProductThread.h"
#include "Buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;

namespace wd
{

ProductThread::ProductThread(Buffer & buff)
: _buff(buff)
{}

void ProductThread::run()
{
	srand(time(NULL));
	cout << "hi" << endl;
	while(true)
	{
		int num = rand() % 100;

	//	flockfile(stdout);
		printf("produce num: %d\n", num);
	//	funlockfile(stdout);
		_buff.push(num);
		sleep(1);

	}
}

}//end of namespace wd
