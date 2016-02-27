 ///
 /// @file    string.cc
 /// @author  zzseven
 /// @date    2016-02-25 22:24:20
 ///
 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using std::cout;
using std::endl;
using std::string;

int test0(void)
{
	char strarr[] = "hello,world!";
	char arr2[10] = "shenzhen";

	printf("%s\n", arr2);

	int len1 = strlen(strarr);
	int len2 = strlen(arr2);
	cout << "len1 = " << len1 << endl
		 << "len2 = " << len2 << endl;

	char * pstr = (char *)malloc(len1 + len2 + 1);
	strcpy(pstr, strarr);
	strcat(pstr, arr2);
	printf("%s\n", pstr);

	free(pstr);
	pstr = NULL;

	char arr3[8];
	char * p1 = strstr(strarr, "llo,wor");
	strncpy(arr3, p1, 7);
	printf("%s\n", arr3);
	
	return 0;
}

int test1(void)
{
	string s1 = "hello,world";
	string s2 = "shenzhen";
	s1 += s2;
	cout << s1 << endl;

	s2 += 'a';
	cout << s2 << endl;

	string s3 = s1 + s2;
	cout << "s3 = " << s3 << endl;

	string s4 = "hello";
	s4.append("world"); // const char *;
	cout << "s4 = " << s4 << endl;

	//----
	cout << "do substr" << endl;
	string s5 = "hello, world";
	string sub = s5.substr(2, 7);
	cout << sub << endl;

	int lenth1 = sub.size();
	int lenth2 = sub.length();
	cout << "lenth1 = " << lenth1 << ","
		 << "lenth2 = " << lenth2 << endl;
	
	return 0;
}

void func1(const char * pstr)
{
	cout << pstr << endl;
}

int main(void)
{
	string s1 = "hello,world";
	func1(s1.c_str());

	for(int idx = 0; idx != s1.size(); ++idx)
	{
		cout << s1[idx] << endl;
	}

	s1[0] = 'X';
	cout << s1 << endl;
	return 0;
}


