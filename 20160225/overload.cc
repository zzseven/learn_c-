 ///
 /// @file    overload.cc
 /// @author  zzseven
 /// @date    2016-02-25 21:49:10
 ///
 
#include <iostream>

using std::cout;
using std::endl;

// c++ 支持函数重载，其实现原理是；名字改编
// 同名函数根据其参数的类型，个数，顺序进行改编


int add(int a, int b)
{
	return a + b;
}

int add(int a, int b, int c)
{
	return a + b + c;
}

double add(double a, int b)
{
	return a + b;
}

int main(void)
{
	int a = 3, b = 4, c = 5;
	cout << "a + b =" << add(3, 4) << endl;
	cout << "a + b + c = " << add(3, 4, 5) << endl;
	return 0;
}


