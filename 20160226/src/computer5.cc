 ///
 /// @file    computer5.cc
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
	{
		int len = strlen(rhs._brand);
		_brand = new char[len + 1];
		strcpy(_brand, rhs._brand);
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

	Computer pc2 = pc1;
	pc2.print();

	return 0;
}
