 ///
 /// @file    add.c
 /// @author  zzseven
 /// @date    2016-03-07 18:27:28
 ///
 
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;


template <typename T>    //template:声明 <xxx>:放的参数列表，可以放两种: 1.class T or typename T 2. int xxx
T add(const T & a, const T & b) // T:返回值类型 add:函数名    a, b: 参数
{
	return a + b;	
}

//模板特化
template <>
const char * add<const char *>(const char * const & a, const char * const & b)
{
	cout << "template <> add(char*, char *)" << endl;
	char * ptmp = new char [strlen(a) + strlen(b) + 1];
	strcpy(ptmp, a);
	strcat(ptmp, b);
	return ptmp;
}

template <typename T, int NUM>   //可以支持重载
T fun(T a)
{
	return a * NUM;
}

int main(void)
{
	cout << add(10, 20) << endl; //隐式实例化
	cout << add<int>(10, 20) << endl;

	cout << add<double>(10.1, 20.2) << endl;

	const char * p1 = "hello";
	const char * p2 = "world";
	const char * p3 = add(p1, p2);
	cout << p3 << endl;

	cout << fun<int, 10>(10) << endl;

	return 0;
}
