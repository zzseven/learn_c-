 ///
 /// @file    Computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-02-27 10:59:22
 ///
 
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;


class Computer
{
public:
	Computer(const char * brand, float fprice);
	~Computer();
	//静态成员函数不含this指针，可以直接通过类名进行调用
	//并且不能使用非静态成员数据
	static void print(Computer &com);
	static void print_total();
private:
	char * _brand;
	float _fprice;
	static float _ftotalPrice;
	//static Point _pt1;
};

float Computer::_ftotalPrice = 0.0f;

Computer::Computer(const char * brand, float fprice)
: _fprice(fprice)
{
	cout << "Computer(float)" << endl;
	_brand = new char[strlen(brand) + 1];
	strcpy(_brand, brand);
	_ftotalPrice += _fprice;	
}

Computer::~Computer()
{
	if(_brand)
		delete [] _brand;
	_ftotalPrice -= _fprice;
	cout << "~Computer()" << endl;
}
void Computer::print(Computer & com)
{
	cout << "价格:" << com._fprice << endl;
	cout << "总价:" << com._ftotalPrice << endl;
}

void Computer::print_total()
{
	//cout << _fprice << endl;//不能使用
	cout << "总价:" << _ftotalPrice << endl;
}


int main(void)
{
	Computer pc1("IBM", 7000);
	Computer::print(pc1);
	Computer::print_total();
	cout << endl;

	Computer pc2("ASUS", 5000);
	pc2.print(pc2);
	pc2.print_total();

	pc2.~Computer();
	pc2.print_total();

}
