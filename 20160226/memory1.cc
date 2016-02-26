 ///
 /// @file    memory1.cc
 /// @author  zzseven
 /// @date    2016-02-26 10:24:08
 ///
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
int a = 0;
char * p1;

int main(void)
{
	int b;
	char s[] = "123456";
	char * p2;
	char * p3 = "123456";
	static int c = 0;
	p1 = new char[10];
	strcpy(p1, "123456");

	printf("&a = %x\n", &a);
	printf("&p1 = %x\n", &p1);
	printf("p1 = %x\n", p1);
	printf("&b = %x\n", &b);
	printf("s = %x\n", s);
	printf("&p2 = %x\n", &p2);
	printf("&p3 = %x\n", &p3);
	printf("p3 = %x\n", p3);
	printf("c = %x\n", c);
	return 0;
}
