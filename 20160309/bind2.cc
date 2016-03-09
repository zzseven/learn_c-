 ///
 /// @file    bind2.cc
 /// @author  zzseven
 /// @date    2016-03-09 22:03:04
 ///
 
#include <iostream>
#include <functional>

using std::cout;
using std::endl;

void f(int n1, int n2, int n3, const int & n4, int n5)
{
	cout << n1 << " " << n2 << " " << n3 << " "
		 << n4 << " " << n5 << endl;

}

int g(int n1)
{
	return n1;
}

struct Foo
{
	void print_sum(int n1, int n2)
	{
		cout << n1 + n2 << "\n";
	}
	int data = 10;
};


int main(void)
{
	using namespace std::placeholders;
	
	int n = 7;
	//bind绑定参数时，采用的是值传递
	auto f1 = std::bind(f, _2, _1, 42, std::cref(n), n);
	n = 10;
	f1(1, 2, 1001, 123, 1231); //第三个之后的参数都是无用参数


	Foo foo;
	foo.data = 3;
	auto f2 = std::bind(&Foo::print_sum, &foo, 95, _2);
	f2(1, 5, 11, 22, 23);
	
	auto f4 = std::bind(&Foo::data, _1);
	cout << f4(foo) << endl;
}
