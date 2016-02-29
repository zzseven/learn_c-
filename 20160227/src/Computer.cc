 ///
 /// @file    Computer.cc
 /// @author  zzseven
 /// @date    2016-02-28 12:03:46
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Computer
{
public:
	Computer(float fprice);
	~Computer();
	void print();
private:
	float _fprice;
	static float _ftotalPrice;
};


float Computer::_ftotalPrice = 0.0f; //静态变量要在外面初始化
//没有初始化会编译不通过
Computer::Computer(float fprice)
: _fprice(fprice)
{
	cout << "Computer(float)" << endl;
	_ftotalPrice += _fprice;
}

Computer::~Computer()
{
	_ftotalPrice -= _fprice;
}

void Computer::print(/*computer * const this */)  
{
	_fprice = 1000;
	cout << "价格:" << this->_fprice << endl;
	cout << "总价:" << _ftotalPrice << endl;
}


int main(void)
{
	Computer pc1(7001);
	cout << "after buy pc1" << endl;
	pc1.print();
	
	Computer pc2(6000);
	cout << "after buy pc2 " << endl;
	pc2.print();

	cout << "pc1的存储空间:" << sizeof(pc1) << endl;
	cout << "computer的存储空间:" << sizeof(Computer) << endl;

	return 0;
}
