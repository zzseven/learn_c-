 ///
 /// @file    computer.cc
 /// @author  zzseven
 /// @date    2016-02-26 11:05:17
 ///
 
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Computer
{
public:
	void setBrand(char * brand)
	{
		strcpy(_brand, brand);
	}
	void setPrice(float fprice)
	{
		_fprice = fprice;
	}
	void print()
	{
		cout << "pin pai: " << _brand << endl;
		cout << "jia ge: " << _fprice << endl;
	}
private:
	//char m_brand[20];
	//float m_price;
	// char _brand[20];
	// char brand_[20]
	char _brand[20];
	float _fprice;

};


int main(void)
{
	int a;
	Computer pc1; //类的实例化
	//pc1._fprice = 10;
	pc1.setPrice(5000);
	pc1.setBrand("DELL");
	pc1.print();

	return 0;
}
