 ///
 /// @file    computer6.cc
 /// @author  zzseven
 /// @date    2016-02-26 21:32:36
 ///
 
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Computer
{
public:
	Computer();
	Computer(const char * brand, float fprice);

#if 0
	Computer(const Computer & rhs)
	: _brand(rhs._brand) //浅拷贝
	, _fprice(rhs._fprice)
	{}
#endif
	
	Computer(const Computer & rhs)
	: _fprice(rhs._fprice)
	{
		int len = strlen(rhs._brand);
		_brand = new char[len + 1];
		strcpy(_brand, rhs._brand);
	}

	//如果不显示定义，系统会自动提供一个赋值运算符函数
	//赋值运算符函数的返回只是引用
	//如果换成对象，则会调用复制构造函数，相当于多做了一次
	//冗余的操作，降低了效率
	Computer  & operator = (const Computer & rhs)
	{
		//_brand = rhs._brand;
		int len = strlen(rhs._brand);
		_brand = new char[len + 1];
		strcpy(_brand, rhs._brand);
		_fprice = rhs._fprice;
		cout << "Computer & operator = (const Computer &)" << endl;

		return *this;
	}

	~Computer();

	void setBrand(char * brand);
	void setPrice(float fprice);
	void print();

private:
	char * _brand;
	float _fprice;

};


Computer::Computer()
{
	cout << "Computer()" << endl;
	int len = strlen("lenovo");
	_brand = new char[len + 1];
	strcpy(_brand, "lenovo");
	_fprice = 4000;
}

Computer::Computer(const char * brand, float fprice)
{
	int len = strlen(brand);
	_brand = new char[len + 1];
	strcpy(_brand, brand);
	_fprice = fprice;
}

Computer::~Computer()
{
	delete [] _brand;
	cout << "~Computer()" << endl;
}

void Computer::setBrand(char * brand)
{
	strcpy(_brand, brand);
}
void Computer::setPrice(float fprice)
{
	_fprice = fprice;
}
void Computer::print()
{
	cout << "pin pai: " << _brand << endl;
	cout << "jia ge" << _fprice << endl;
}

int main(void)
{
	Computer pc1;
	pc1.print();

	Computer pc2("MAC", 10000);
	pc2.print();
	pc2 = pc1;
	pc2.print();



	return 0;
}
