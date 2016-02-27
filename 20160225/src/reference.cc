 ///
 /// @file    reference.cc
 /// @author  zzseven
 /// @date    2016-02-25 21:02:52
 ///
 
#include <iostream>

using std::cout;
using std::endl;

#if 0
void swap(int a, int b) // send value ->  copy
{
	int tmp = a;
	a = b;
	b = tmp;
}
#endif

void swap(int * pa, int * pb) //transmit address -> transmit value
{
	cout << "1" << endl;
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void swap(int & refa, int & refb) //当进行实参和形参的结合时，引用没有复制的开销，效率是比通过值传递和地址传递都要高
{
	cout << "2" << endl;
	int tmp = refa;
	refa = refb;
	refb = tmp;
}


//引用和指针得异同
//1.引用必须进行初始化，指针没有必要
//2.引用一经绑定之后不会再改变指向，指针没有这个限制
//3.引用作为函数的参数时，它不会带来额外的复制开销

int  test1(void)
{
	int * pa;
	int a = 3;
	int b = 4;
	//swap(a, b);
	
	cout << "a = " << a << ", b = " << b << endl;
	swap(&a, &b);
	cout << "a = " << a << ", b = " << b << endl;

	int & refa = a; // reference is a alias of the variable, it must be initialized;

	cout << "通过引用修改a的值之后:" << endl;
	refa = 10;
	cout << "a = " << a << ", b = " << b << endl;

	cout << "通过引用交换a、b的值之后:" << endl;
	swap(a, b);
	cout << "a = " << a << ", b = " << b << endl;

	return 0;
}


int test2(void)
{
	int a = 3;
	int b = 4;
	int  & refa = a;
	refa = b;  //引用一经绑定之后就不会改变指向，指针没有这个限制
	//refa = 5;
	cout << "a = " << a << ", b = " << b << endl;
	return 0;
}


int arr[5] = {0, 1, 2, 3, 4}; //引用作为函数的返回值

int & func1(int index) //引用作为函数的返回值
{
	return arr[index];
}

int & func2() //不要返回一个局部变量的引
{
	int a = 3;
	return a;
}

int * fun3()
{
	int a = 3;
	return &a;
}

int & func4()   //不要返回一个指向对空间的引用
{
	int *pa = new int(3);
	return *pa;
}

int main(void)
{
	cout << func1(1) << endl;
	func1(1) = 10;

	cout << "arr[1] = " << arr[1] << endl;
	cout << "fun4() = " << func4() << endl;

	int a = 3; int b = 4;
	cout << "a + b + func4() = " << a + b + func4() << endl;

	return 0;
}


















