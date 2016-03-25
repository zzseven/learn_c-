 ///
 /// @file    virtual_multi_inherit.cc
 /// @author  zzseven
 /// @date    2016-03-15 14:40:01
 ///
 
#include <iostream>

using std::cout;
using std::endl;


class A
{
public:
	virtual void a()
	{
		cout << "A::a()" << endl;
	}
	virtual void b()
	{
		cout << "A::b()" << endl;
	}
	virtual void c()
	{
		cout << "A::c()" << endl;
	}
};


class B
{
public:
	virtual void a()
	{
		cout << "B::a()" << endl;
	}
	virtual void b()
	{
		cout << "B::b()" << endl;
	}

	void c()
	{
		cout << "B::c()" << endl;
	}
	void d()
	{
		cout << "B::d()" << endl;
	}

};

class C : public A, public B
{
public:
	virtual void a()
	{
		cout << "C::a()" << endl;
	}

	void c()
	{
		cout << "C::c()" << endl;
	}
	void d()
	{
		cout << "C::d()" << endl;
	}

};


int main()
{
	C c;
	cout << "C's size = " << sizeof(c) << endl;
	cout << endl;

	A * pa = &c;
	pa->a();
	pa->b();
	pa->c();
	cout << endl;

	B * pb = &c;
	pb->a(); //C::a()
	pb->b(); //B::b()   虚函数
	pb->c(); //B::c() 非虚函数
	pb->d(); //B::d() 非虚函数
	cout << endl;

	C * pc = &c;
	pc->a();
//	pc->b();
	pc->c();
}
