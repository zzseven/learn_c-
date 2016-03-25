 ///
 /// @file    destructor.cc
 /// @author  zzseven
 /// @date    2016-03-14 20:01:26
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class A
{
public:
	A(int ia = 0)
	: _ia(ia)
	{
		cout << "A()" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _ia;

};

class B
{
public:
	B()
	{
		cout << "B()" << endl;
	}

	~B()
	{
		cout << "~B()" << endl;
	}

};

class C : public A
{
public:
	C(int x, int y)
	: A(x)
	, b()
	, _ic(y)
	{
		cout << "C(int, int)" << endl;
	}

	~C()
	{
		cout << "~C()" << endl;
	}
private:
	int _ic;
	B b;
};

int main(void)
{
	C c1(1, 2);

	return 0;
}
