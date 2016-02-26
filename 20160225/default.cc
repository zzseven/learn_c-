 ///
 /// @file    default.cc
 /// @author  zzseven
 /// @date    2016-02-25 22:00:02
 ///
 
#include <iostream>

using std::cout;
using std::endl;

int add(int a, int b = 0) //缺省参数/默认参数
{
	return a + b;
}

#if 0
int add(int a, int b, int c = 0) //注意默认参数产生的二义性
{
	return a + b + c;
}
#endif

//缺省参数的设置必须要从右到左进行


double add(double a, double b = 0, double c = 0)
{
	return a + b + c;
}

int main(void)
{
	cout << "a + b = " << add(3) << endl;
	cout << "a + b = " << add(3, 4) << endl;
	cout << "a + b + c = " << add(3.1, 3.2) << endl;
	return 0;

}
