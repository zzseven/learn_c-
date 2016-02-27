 ///
 /// @file    test.c
 /// @author  zzseven
 /// @date    2016-02-26 19:27:47
 ///
 
//#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char s[] = "abc";
	char *p1 = "abc";
	char *p3 = "abcdef";
	char *p4 = "abcdef";

	printf("s = %x\n", &s[1]);
	printf("p1 = %x\n", &p1);
	printf("p3 = %x\n", p3);
	printf("p4 = %x\n", p4);

	return 0;
}
