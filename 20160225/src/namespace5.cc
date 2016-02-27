 ///
 /// @file    namespace5.cc
 /// @author  zzseven
 /// @date    2016-02-25 20:07:11
 ///
 
#include <iostream>

using std::cout;
using std::endl;

extern int num = 0;

namespace B
{
int num = 2;

#if 0
void displayB()
{
	A::displayA();
}
#endif
}

namespace A
{
int num = 1;
void displayA()
{
	int num = 3;

	cout << "displayA函数中的num: " << num << endl;
	cout << "A中的num: " << A::num << endl;
	cout << "B中的num: " << B::num << endl;
	cout << "外部的num: " << ::num << endl;
}
}

namespace B
{
void displayB()
{
	A::displayA();
}
}

void display()
{
	cout << "hello, wold!" << endl;
}

int main(void)
{
	A::displayA();
	display();

	return 0;
}


