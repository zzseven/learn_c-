 ///
 /// @file    derived1.cc
 /// @author  zzseven
 /// @date    2016-03-14 19:27:11
 ///
 
#include <iostream>

using std::cout;
using std::endl;


class Base
{
public:
#if 1
	Base()
	: _ix(0)
	{
		cout << "Base()" << endl;
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
	Derived()
	{
		cout << "Derived()" << endl;
	}
	Derived(int ix)
	{
		cout << "Derived(int)" << endl;
	}
	~Derived()
	{
		cout << "~Derived()" << endl;
	}
};

int main(void)
{
	Derived d1(3);
	cout << d1._ix << endl;
}
