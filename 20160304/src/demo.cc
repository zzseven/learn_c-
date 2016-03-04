 ///
 /// @file    demo.cc
 /// @author  zzseven
 /// @date    2016-03-04 21:23:59
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Demo
{
public:
	double operator()(double x, double y)
	{
		return x > y ? x : y;
	}

	double operator()(double x, double y, double z)
	{
		return (x + y) * z;
	}
};


int main(void)
{
	Demo demo;//重载了函数调用运算符的对象称为函数对象
	cout << demo(3, 4) << endl;
	cout << demo(3, 4, 5) << endl;
	return 0;
}
