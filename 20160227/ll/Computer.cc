 ///
 /// @file    Computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-02-27 10:59:22
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
	//static Point _pt1;
};

float Computer::_ftotalPrice = 0.0f;

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
void Computer::print(/*Computer * const this*/)
{// this代表对象本身，它是一个隐藏的参数
	cout << "价格:" << this->_fprice << endl;
	cout << "总价:" << _ftotalPrice << endl;
}


int main(void)
{
	Computer pc1(7000);
	cout << "after buy pc1 " << endl;
	pc1.print();

	Computer pc2(5000);
	cout << "after buy pc2 " << endl;
	pc2.print();


	cout << "pc1的存储空间:" << sizeof(pc1) << endl;
	cout << "Computer的存储空间:" << sizeof(Computer) << endl;

}
