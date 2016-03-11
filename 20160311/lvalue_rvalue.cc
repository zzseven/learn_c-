///
 /// @file    lvalue_rvalue.cc
 /// @author  zzseven
 /// @date    2016-03-11 10:10:32
 ///
 
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;


int main(void)
{
	int a = 10;
	int b = 120;
	int *pflag  =  &a;
	vector<int> vectmp;
	vectmp.push_back(1);
	std::string str1 = "hello";
	std::string str2 = "world";
	const int & m = 1;

	&a;
	&b;
//	&(a + b);//a+b  右值
	&(++a);  //++a  左值
//	&(a++);  //a++  右值
	&pflag;
	&(*pflag);
	&vectmp[0];
	//&100;
	//std::string("hello"); //右值
	&str1;
	//&(str1 + str2);  右值
	&m;

}
