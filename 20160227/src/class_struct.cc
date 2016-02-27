 ///
 /// @file    class_struct.cc
 /// @author  zzseven
 /// @date    2016-02-27 09:49:24
 ///
 
#include <iostream>

class A
{
	int _ia; //默认的访问权限是private
};

struct B //默认的访问权限是public
{
	int _ia;
};

int main(void)
{
	A a;
	//a._ia;// buxing	
	B b;
	b._ia = 10;
}
