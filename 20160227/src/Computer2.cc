 ///
 /// @file    Computer.cc
 /// @author  zzseven
 /// @date    2016-02-28 12:03:46
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
	static void print(Computer & com);
	static void print_total();
	
private:
	char * _brand;
	float _fprice;
	static float _ftotalPrice;
};


float Computer::_ftotalPrice = 0.0f; //静态变量要在外面初始化
//没有初始化会编译不通过
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
	{
		delete [] _brand;
	}
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
	cout << "总价:" << _ftotalPrice << endl;
}


int main(void)
{
	Computer pc1("Apple", 12000);
	Computer::print(pc1);
	Computer::print_total();
	cout << endl;

	Computer pc2("DELL",7001);
	pc2.print(pc2);
	pc2.print_total();
//	pc1.print(pc1);

	pc2.~Computer();
//	pc1.~Computer();
	Computer::print_total();
///	pc1.~Computer(); //为什么要将pc1的也手动删除，才不会出现内存错误呢？

	Computer::print_total();
	return 0;
}
