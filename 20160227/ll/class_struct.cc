 ///
 /// @file    class_struct.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-02-27 09:49:02
 ///
 
#include <iostream>

class A
{
	int _ia;//默认情况下的访问权限是private

};

struct B
{//默认情况下的访问权限public
	int _ia;

};

int main(void)
{
	A a;
	//a._ia;
	B b;
	b._ia = 10;

}
