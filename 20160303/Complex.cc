 ///
 /// @file    Complex.cc
 /// @author  zzseven
 /// @date    2016-03-03 21:07:35
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
	void display()
	{
		cout << _dreal;
		if(_dimag > 0)
			cout << "+" << _dimag << "i" << endl;
		else if(_dimag == 0)
			cout << endl;
		else
			cout << " - " << -1 * _dimag << "i" << endl;
	}
public:
	double _dreal;
	double _dimag;
};


//以普通函数/全局函数进行重载
Complex operator + (const Complex & lhs, const Complex & rhs)
{
	return Complex(lhs._dreal + rhs._dreal,
				   lhs._dimag + rhs._dimag);
}

int main(void)
{
	Complex c1(1.0, 2.0);
	Complex c2(3.0, -4.0);
	Complex ret = c1 + c2;

	ret.display();
}

