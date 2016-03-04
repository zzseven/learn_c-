 ///
 /// @file    Complex4.cc
 /// @author  zzseven
 /// @date    2016-03-03 21:33:41
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Complex
{
public:
	Complex(double dreal = 0, double dimag = 0)
	: _dreal(dreal)
	, _dimag(dimag)
	{
		cout << "Complex()" << endl;	
	}

	Complex & operator += (const Complex & rhs)
	{
		this->_dreal += rhs._dreal;
		this->_dimag += rhs._dimag;
		return * this;
	}

	Complex & operator ++() //前置++，自身引用效率高
	{
		this->_dreal += 1;
		this->_dimag += 1;
		return * this;
	}

	Complex operator ++(int)//int只是标识，代表这是后置++重载形式
	{
		Complex tmp(this->_dreal, this->_dimag);
		this->_dreal += 1;
		this->_dimag += 1;
		return tmp;
	}

private:
	double _dreal;
	double _dimag;
};

int main(void)
{
	int a = 3;
	cout << ++a << endl;
	cout << "prefix -> a = " << a << endl;

	cout << a++ << endl;
	cout << "post -> a = " << a << endl;
}
