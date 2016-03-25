 ///
 /// @file    test.c
 /// @author  zzseven
 /// @date    2016-03-15 11:30:49
 ///
 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX = 1000000;

int main()
{
	char name[MAX];
	long StartTime, EndTime, TimeForPrintf, TimeForPutchar;
	for(int i=0; i<MAX; ++i)
	{
		name[i] = 'a';
	}

	StartTime = clock();
	for(int i=0; i<MAX; ++i)
	{
		printf("%c", name[i]);
	}
	EndTime = clock();

	TimeForPrintf = EndTime - StartTime;

	StartTime = clock();
	for(int i=0; i<MAX; ++i)
	{
		putchar(name[i]);
	}
	EndTime = clock();
	
	TimeForPutchar = EndTime - StartTime;
	
	putchar('\n');
	putchar('\n');

	printf("TimeForPrintf = %ld ms\n", TimeForPrintf);
	printf("TimeForPutchar = %ld ms\n", TimeForPutchar);

	return 0;
}
