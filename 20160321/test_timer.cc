 ///
 /// @file    test_timer.cc
 /// @author  zzseven
 /// @date    2016-03-23 20:51:21
 ///
 
#include "TimerThread.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>


struct Product
{
void produce()
{
	srand(time(NULL));
	int num = rand() % 100;
	printf("porduce a num: %d\n", num);
}

};



int main(void)
{
	Product product;
	wd::TimerThread timer(std::bind(&Product::produce, &product), 3, 6);
	timer.start();
	sleep(20);
	timer.stop();
	return 0;
}
