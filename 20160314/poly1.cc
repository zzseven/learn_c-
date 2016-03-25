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
	virtual int func(int x)
	{
		cout << "Base::func(int)" << endl;
		return x;
	}
private:

};

class Sub : public Base
{
public:
	virtual int func(int x)
	{
		cout << "Sub::func(int)" << endl;
		float y = x;
		return y;
	}
};


int main(void)
{
	Base base;
	Sub sub;
	Base & ref1 = base;
	ref1.func(5);
	Base & ref2 = sub;
	ref2.func(5);
}
