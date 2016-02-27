 ///
 /// @file    namespace2.cc
 /// @author  zzseven
 /// @date    2016-02-25 19:43:48
 ///
 
#include <iostream>

using std::cout;
using std::endl;

namespace A
{
void displayA(){ cout << "This is A" << endl;}
}

namespace B
{
using A::displayA;

void displayB()
{
	displayA();
	cout << "This is B" << endl;
} //End of displayB
}

int main(void)
{
	A::displayA();
	using B::displayB;
	displayB();
}
