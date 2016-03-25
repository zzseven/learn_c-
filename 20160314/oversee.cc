 ///
 /// @file    oversee.cc
 /// @author  zzseven
 /// @date    2016-03-14 20:42:40
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Base
{
public:
	int func(int i)
	{
		cout << "Base::func(int)" << endl;
		return _ix;
	}

protected:
	int _ix;
};


class Derived : public Base
{
public:
	int func()
	{
		cout << "Derived::func()" << endl;
		_ix = 9;
		Base::_ix = 22;
		return _ix;
	}
private:
	int _ix;
};

int main(void)
{
	Derived d;
	cout << d.func() << endl;
	d.func();
	cout << d.Base::func(3) << endl;
}
