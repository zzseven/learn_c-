 ///
 /// @file    namespace4.cc
 /// @author  zzseven
 /// @date    2016-02-25 19:55:48
 ///
 
#include <iostream>

using std::cout;
using std::endl;

namespace
{
	int num = 0; //位于匿名名称空间
}

namespace B
{
	int num = 2;
}

namespace A
{
int num = 1;

void displayA()
{
	int num = 3;

	cout << "displayA 函数中的num: " << num << endl;
	cout << "A中的num: " << A::num << endl;
	cout << "B中的num: " << B::num << endl;
	cout << "外部的num: " << ::num << endl;
}
}

void display()
{
	cout << "hello, world!" << endl;
}

int main(void)
{
	A::displayA();
	display();
	return 0;
}


