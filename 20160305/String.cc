 ///
 /// @file    String.cc
 /// @author  zzseven
 /// @date    2016-03-10 09:49:45
 ///
 
#include <iostream>
#include <stdio.h>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(void)
{
	string s1 = "hello world";
	string s2 = s1;
	string s3 = "wangdao";

	string s4 = s2;

	cout << "s1's size = " << sizeof(s1) << endl;
	printf("s1's address = %p\n", s1.c_str());

	cout << "s2's size = " << sizeof(s2) << endl;
	printf("s2's address = %p\n", s2.c_str());

	cout << "s3's size = " << sizeof(s3) << endl;
	printf("s3's address = %p\n", s3.c_str());

	cout << "s4's size = " << sizeof(s4) << endl;
	printf("s4's address = %p\n", s4.c_str());

	s4[0] = 'H';
	cout << "s4's size = " << sizeof(s4) << endl;
	printf("s4's address = %p\n", s4.c_str());
}
