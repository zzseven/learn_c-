 ///
 /// @file    computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-02-25 19:05:13
 ///
 
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class Computer
{
public://对外提供接口

	Computer();//声明
	Computer(const char * brand, float fprice)
	{// 有参构造函数
		int len = strlen(brand);
		_brand = new char[len + 1];
		strcpy(_brand, brand);
		_fprice = fprice;
		cout << "Computer(const char *, float)" << endl;
	}

	// 默认复制构造函数的实现
	Computer(const Computer & rhs)
	: _brand(rhs._brand) // 浅拷贝
	, _fprice(rhs._fprice)
	{
		cout << "Computer(const Computer&)" << endl;
	}

#if 0
	Computer(const Computer & rhs)
	: _fprice(rhs._fprice)
	{
		cout << "Computer(const Computer&)" << endl;
		int len = strlen(rhs._brand);
		_brand = new char[len + 1];
		strcpy(_brand, rhs._brand);// 深拷贝
	}
#endif

	//如果不显式定义，系统会自动提供一个赋值运算符函数
	//赋值运算符函数的返回值是引用 
	//如果换成对象，则会调用复制构造函数，相当于多做了一次
	//冗余的操作，降低了效率
	Computer & operator = (const Computer & rhs)
	{
		cout << "Computer & operator=(const Computer &)" << endl;
		if(this == &rhs)
		{	return *this;	}//1. 自复制

		//_brand = rhs._brand;
		delete [] _brand;//2. 先释放掉原来_brand所指的空间

		int len = strlen(rhs._brand);
		_brand = new char[len + 1];//3. 创建新的空间
		strcpy(_brand, rhs._brand);
		_fprice = rhs._fprice;
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

Computer::~Computer()
{
	delete [] _brand;
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
	cout << "品牌：" << _brand << endl;
	cout << "价格: " << _fprice << endl;
}

//Computer pc;

int test0(void)
{
	int a;
	Computer pc1;//类的实例化
	//pc1._fprice = 10;//信息隐藏
	pc1.setPrice(5000);
	pc1.setBrand("Thinkpad");
	pc1.print();
	return 0;
}

int test1(void)
{
	cout << "enter main()" << endl;
	{
		Computer com;
		com.print();
		cout << endl << endl;
	}
	int a;
	Computer pc1;// 会调用默认构造函数 default constructor
	pc1.print();

	cout << endl;
	Computer pc2("DELL", 6000);
	pc2.print();

	cout << "exit main()" << endl;
	return 0;
}

int test2(void)
{
	Computer * pCom = new Computer;
	pCom->print();
	pCom->~Computer();//析构函数是可以显式调用的，但是一般不这样做

	delete pCom;

	return 0;
}

int test3(void)
{
	Computer pc1;
	pc1.print();

	Computer pc2 = pc1;
	pc2.print();

	return 0;
}

int main(void)
{
	int a = 3;
	int b;
	b = a;

	Computer pc1;

	Computer pc2("Mac", 10000);
	pc1.print();
	
	//pc1 = pc1;//自复制
	


	pc2 = pc1;
	pc2.print();



	return 0;
}
