 ///
 /// @file    static_cast.cc
 /// @author  zzseven
 /// @date    2016-02-25 22:07:16
 ///
 
#include <iostream>

using std::cout;
using std::endl;

int func(int * pa) //int * pa = &b;
{
	return *pa;
}

int main(void)
{
	int a = 3;
	double d1 = double(a); //c
	double d2 = static_cast<double>(a); //c++ 的强制转换类型

	cout << "d1 = " << d1 << endl;
	cout << "d2 = " << d2 << endl;

	const int b = 10;
	int * pc = const_cast<int *>(&b); //?????????????
	*pc = 11;
	cout << "*pc = " << *pc << endl;
	cout << "b = " << b << endl;

	func(const_cast<int *>(&b)); //用于函数传参

	return 0;
}
