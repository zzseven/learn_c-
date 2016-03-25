 ///
 /// @file    poly4.cc
 /// @author  zzseven
 /// @date    2016-03-14 22:39:04
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	virtual void display()
	{
		cout << "Base::display()" << endl;
	}

	void call_base1()
	{
		this->display();
	}

	void call_base2()
	{
		Base::display();
	}
};


class Child : public Base
{
public:
	void display()
	{
		cout << "Child::display()" << endl;
	}

	void call_child1()
	{
		display();
	}

	void call_base1()
	{
		cout << "Child::call_base1()" << endl;
		display();
	}

	void call_base2()
	{
		cout << "Child::call_base2()" << endl;
		Base::display();
	}
};


int main()
{
	Base base;
	Child child;
	base.call_base1();
	child.call_child1();
	cout << endl;

	Base * pbase = & base;
	pbase->call_base1();
	pbase->call_base2();
	cout << endl;

	pbase = &child;
	pbase->call_base1();
	pbase->call_base2();
}
