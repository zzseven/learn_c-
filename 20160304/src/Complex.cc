 ///
 /// @file    Complex.cc
 /// @author  zzseven
 /// @date    2016-03-04 23:03:49
 ///
 
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class Complex
{
	friend std::ostream & operator << (std::ostream &, const Complex & rhs);
	friend std::istream & operator >> (std::istream &, Complex & rhs);
public:
	Complex(double dreal, double dimag)
	: _dreal(dreal)
	, _dimag(dimag)
	{
		cout << "Complex(double, double)" << endl;
	}
private:
	double _dreal;
	double _dimag;
};

//输入输出运算符的重载必须是friend函数的形式重载
//不能使成员函数，因为它们要求第一个参数是流类型
//
//流对象不能进行复制

std::ostream & operator << (std::ostream & os, const Complex & rhs)
{
	os << rhs._dreal;
	if(rhs._dimag > 0)
		os << " + " << rhs._dimag << "i";
	else if(rhs._dimag < 0)
		os << " - " << (-1) * rhs._dimag << "i";
	return os;
}


std::istream & operator >> (std::istream & is, Complex & rhs)
{
	is >> rhs._dreal;
	while(is.get() != '*')
	{
	
	}
	is >> rhs._dimag;
	return is;
}

int main(void)
{
	Complex c1(3, 2);
	Complex c2(4, 5);
	cout << c1 << endl;
	c2 = c1;
	cout << c2 << endl;
	Complex c3(c2);

	cin >> c3;
	cout << c3 << endl;

	return 0;
}
