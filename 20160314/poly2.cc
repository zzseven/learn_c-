 ///
 /// @file    poly1.cc
 /// @author  zzseven
 /// @date    2016-03-14 22:12:05
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
};


class Child2 : public Base
{
public:
	void display()
	{
		cout << "Child2::display()" << endl;
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
	cout << "sizeof(Base) = " << sizeof(Base) << endl;
	cout << "sizeof(child1)= " << sizeof(Child1) << endl;

	Base * pBase = NULL;
	Child1 child1;
	child1.display();
	pBase = &child1;
	pBase->display();

	Child2 child2;
	pBase = &child2;
	pBase->display();

	return 0;
}



int main1(void)
{
	Base * pBase = NULL;
	Base base1;
	base1.display();

	pBase = &base1;
	pBase->display();

	Child1 * pChild1 = NULL;
	Child1 child1;
	pChild1 = &child1;
	pChild1->display();

	
	Child2 * pChild2 = NULL;
	Child2 child2;
	pChild2 = &child2;
	pChild2->display();
	cout << endl << endl;

	pBase->display();
	pBase = &child1;
	pBase->display();
	pBase = &child2;
	pBase->display();

	display(&base1);
	display(&child1);
	display(&child2);


}

