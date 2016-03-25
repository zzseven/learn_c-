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

	Derived(int i, int j) : Base(j)
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
	Derived d1(3, 2);
	cout << d1._ix << endl;
}
