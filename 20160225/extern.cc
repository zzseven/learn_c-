 ///
 /// @file    extern.cc
 /// @author  zzseven
 /// @date    2016-02-25 21:54:15
 ///
 
#include <iostream>

using std::cout;
using std::endl;

#ifdef __cplusplus
extern "C"  //他提供了一种用C和C++进行混合编程的方式
{
#endif

int add(int a, int b)
{
	return a + b;
}

#ifdef __cplusplus
} //end of extern C
#endif

int add(int a, int b, int c)
{
	return a + b + c;
}

double add(double a, int b)
{
	return a + b;
}

int main(void)
{
	int a =3, b = 4, c = 5;
	cout << "a + b = " << add(3, 4) << endl;
	cout << "a + b + c = " << add(3, 4, 5) << endl;
	return 0;
}



