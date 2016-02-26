 ///
 /// @file    namespace3.c
 /// @author  zzseven
 /// @date    2016-02-25 19:49:54
 ///
 
#include <iostream>

using std::cout;
using std::endl;

namespace A
{
int num = 1;

void displayA()
{
	cout << "This is A!" << endl;
}
}

namespace B
{
using A::displayA;

int num = 10;

void displayB()
{
	displayA();
	cout << "This is B" << endl;
}
}

int main(void)
{
	A::num = 110;
	A::displayA();
	using B::displayB;
	displayB();
}
