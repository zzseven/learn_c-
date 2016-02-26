 ///
 /// @file    namespace1.cc
 /// @author  zzseven
 /// @date    2016-02-25 19:40:09
 ///
 
#include <iostream>

using namespace std;

namespace A
{
void displayA(){ cout << "This is A" << endl; }	
}

namespace B
{
void displayB()
{
	A::displayA();
	cout << "This is B" << endl;
}
}

int main(void)
{
	B::displayB();
}
