 ///
 /// @file    poly5.cc
 /// @author  zzseven
 /// @date    2016-03-14 22:47:12
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base0
{
public:
	Base0()
	{
		cout << "Base0()" << endl;
	}
	virtual void func1()
	{
		cout << "Base0::func1()" << endl;
	}
	virtual void func2()
	{
		cout << "Base0::func2()" << endl;
	}
	~Base0()
	{
		cout << "~Base()" << endl;
	}
};


class Base1 : public Base0
{
public:
	Base1()
	{
		this->func1();
	}

	virtual void func1()
	{
		cout << "Base1::func1()" << endl;
	}

	virtual void func2()
	{
		cout << "Base1::func2()" << endl;
	}

	~Base1()
	{
		cout << "~Base1()" << endl;
		func2();
	}
};

class Sub : public Base1
{
public:
	virtual void func1()
	{
		cout << "Sub::func1()" << endl;
	}

	virtual void func2()
	{
		cout << "Sub::func2()" << endl;
	}

	~Sub()
	{
		cout << "~Sub()" << endl;
	}
	

};


int main(void)
{
	Sub sub;
	return 0;
}
