 ///
 /// @file    virtual_fuc.cc
 /// @author  zzseven
 /// @date    2016-03-16 16:21:54
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Base
{
public:
	virtual void f(){ cout << "Base::f" << endl;}		
	virtual void g(){ cout << "Base::g" << endl;}		
	virtual void h(){ cout << "Base::h" << endl;}		
	
};

typedef void(*Fun)(void);

class Derived : public Base
{
public:
	virtual void f(){ cout << "Derived::f" << endl;}		
	virtual void g1(){ cout << "Derived::g1" << endl;}		
	virtual void h1(){ cout << "Derived::h1" << endl;}		
};


int main(void)
{
	Derived b;

	Fun pFun = NULL;

	cout << "函数表地址：" << (int*)(&b) << endl;
	cout << "虚函数表第一个函数地址：" << (int *)* (int*)(&b) << endl;
	
	pFun = (Fun)* ((int*)* (int*)(&b));
	pFun();

	pFun = (Fun)* ((int*)* (int*)(&b) + 2);
	pFun();

	pFun = (Fun)* ((int*)* (int*)(&b) + 4);
	pFun();

	pFun = (Fun)* ((int*)* (int*)(&b) + 6);
	pFun();

	pFun = (Fun)* ((int*)* (int*)(&b) + 8);
	pFun();

//	pFun = (Fun)* ((int*)* (int*)(&b) + 10);
//	pFun();

	cout << "sizefo(xxx) = " << sizeof((int *)* (int*)(&b)) << endl;
}
