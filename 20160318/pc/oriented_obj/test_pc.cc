 ///
 /// @file    test_pc.cc
 /// @author  zzseven
 /// @date    2016-03-21 16:28:42
 ///
 
#include "Buffer.h"
#include "ProductThread.h"
#include "ConsumerThread.h"

#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	wd::Buffer buffer(10);
	cout << 1 << endl;
	wd::Thread *pProduct = new wd::ProductThread(buffer);
	cout << 1 << endl;
	wd::Thread *pConsume = new wd::ConsumerThread(buffer);
	cout << 1 << endl;

	pProduct->start();
	cout << 1 << endl;
	pConsume->start();
	cout << 1 << endl;
	pProduct->join();
	pConsume->join();

	return 0;
}
