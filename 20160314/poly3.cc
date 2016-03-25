 ///
 /// @file    poly3.cc
 /// @author  zzseven
 /// @date    2016-03-14 22:31:57
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
};

class Child1 : public Base
{
public:
	void display()
	{
		cout << "Child1::display()" << endl;
	}

	void print()
	{
		cout << "Child1::print()" << endl;
	}
};

class Child2 : public Base
{
public:
	void display()
	{
		cout << "Child2::display()" << endl;
	}

	void print()
	{
		cout << "Child2::print()" << endl;
	}
private:
	int _ia;
};


void display(Base * pbase)
{
	pbase->display();
}

int main(void)
{
	Base base;
	Child1 child1;
	Child2 child2;
	child1.display();

	child1.print();
	child1.Base::display();

	Base * pbase = &child2;
	pbase->display();

	Base & ref = child2;
	ref.display();
}
