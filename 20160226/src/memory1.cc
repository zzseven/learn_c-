 ///
 /// @file    memory1.cc
 /// @author  zzseven
 /// @date    2016-02-26 10:24:08
 ///
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
int a = 0; //全局/静态区
char * p1; //全局/静态区

int main(void)
{
	int b; //栈
	char s[] = "123456";//栈
	char * p2;//栈
	char * p3 = "123456";//p3 在栈上，“123456”在常量区

	static int c = 0; //全局区，静态区
	p1 = new char[10];//p1在全局区，申请的空间在堆区
	strcpy(p1, "123456");

	printf("&a = %x\n", &a);
	printf("&p1 = %x\n", &p1);
	printf("p1 = %x\n", p1);
	printf("&b = %x\n", &b);
	printf("s = %x\n", s);
	printf("&p2 = %x\n", &p2);
	printf("&p3 = %x\n", &p3);
	printf("p3 = %x\n", p3);
	printf("c = %x\n", &c);
	return 0;
}
