 ///
 /// @file    computer3.cc
 /// @author  zzseven
 /// @date    2016-02-26 20:01:25
 ///
 
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Computer
{
public://对外提供接口
	
	//构造函数可以进行重载
	Computer(); //声明
#if 0
	Computer()  //默认构造函数
	{
		cout << "Computer()" << endl;
		strcpy(_brand, "lenovo");
		_fprice = 4000;
	}
#endif
	//当只提供有参构造函数是，系统不会再为我们提供默认的构造函数
	Computer(const char * brand, float fprice)
	{//有参构造函数
		strcpy(_brand, brand);
		_fprice = fprice;
	}
	~Computer();
	void setBrand(char * brand);
	void setPrice(float fprice);
	void print();
private:
	char _brand[20];
	//char * _brand;
	float _fprice;
};

Computer::Computer()
{
	cout << "Computer()" << endl;
	//int len = strlen("lenovo");
	//_brand = new char[len + 1];
	strcpy(_brand, "lenovo");
	_fprice = 4000;
}
Computer::~Computer()
{
//	delete [] _brand;
	cout << "~Computer()" << endl;
}

//类之外实现成员函数
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
	cout << "jia ge: " << _fprice << endl;
}

Computer pc;

int test1(void)
{
	int a;
	Computer pc1;
	pc1.setPrice(5000);
	pc1.setBrand("DELL");
	pc1.print();

	return 0;
}

int main(void)
{


	Computer * pCom = new Computer;
	pCom->print();
//	pCom->~Computer();//析构函数时可以显示调用的
	cout << "fdsf" << endl;
	delete pCom;

	return 0;
}
