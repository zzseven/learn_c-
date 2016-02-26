 ///
 /// @file    const.cc
 /// @author  zzseven
 /// @date    2016-02-25 20:33:09
 ///
 
#include <iostream>

using std::cout;
using std::endl;

#define MAX 100	//简单的一个字符串替换，发生在预处理时期，不进行类型检查

int test0(void)
{
	const int a = 3;
	cout << MAX <<endl;
	cout << "a = " << a << endl;

	//a = 10 //常量的值是不能进行修改的
	//const int b; //常量必须进行初始化
	int const c = 4; //能放在类型的前后

}


int main(void)
{
	int a = 3;
	int * pa = &a;
	*pa = 4;
	int * pp;
	int b = 5;

	const int * pb = &a; //常量指针（pointer to const） 这个指针定义好了就不能指向别处了
//	*pb = 5; //通过指针不能修改原变量的值
	cout << "s *pb = " << *pb << endl;
	pb = &b;
	cout << "l *pb = " << *pb << endl;

	int * const pc = &a; //指针常量(const pointer);
	cout << "s *pc = " << *pc << endl;
	*pc = 6;
	cout << "l *pc = " << *pc << endl;

	int d = 10;
	// pc = &d;

}

