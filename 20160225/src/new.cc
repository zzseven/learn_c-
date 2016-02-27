 ///
 /// @file    new.cc
 /// @author  zzseven
 /// @date    2016-02-25 20:50:27
 ///
 
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

//malloc与new的差别是：new能够进行初始化，malloc 只是开辟了空间

int test0(void)
{
	int * pa = (int *)malloc(sizeof(int));
	*pa = 3;
	free(pa);

	return 0;
}

int main(void)
{
	int *pa = new int(3);
	*pa = 10;
	cout << *pa << endl;
	delete pa;

	int *pb = new int[10]; // The default initialized
	for(int i = 0; i !=10; ++i)
	{
		cout << pb[i] << endl;
	}

	delete [] pb;
	return 0;
}
