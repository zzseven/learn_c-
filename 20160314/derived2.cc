 ///
 /// @file    derived2.cc
 /// @author  zzseven
 /// @date    2016-03-14 19:33:16
 ///
 
#include <iostream>

using std::endl;
using std::cout;


//
//
class Base
{
public:
#if 1
	Base()
	{
		cout << "Base()" << endl;
	}
	Base(int ix)
	: _ix(ix)
	{
		cout << "Base(int)" << endl;
	}
	~Base()
	{
		cout << "~Base()" << endl;
	}
#endif
	int _ix;

};

class Derived : public Base
{
public:
	~Derived()
	{
		cout << "~Derived()" << endl;
	}
};

int main(void)
{
	Derived d1;
	cout << d1._ix << endl;
}
