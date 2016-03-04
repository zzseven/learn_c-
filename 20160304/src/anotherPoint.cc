 ///
 /// @file    anotherPoint.cc
 /// @author  zzseven
 /// @date    2016-03-04 23:44:20
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Point;

class AnotherPoint
{
	friend class Point;
public:
	AnotherPoint(double dx = 1.0, double dy = 1.0)
	: _dx(dx)
	, _dy(dy)
	{
		cout << "AnotherPoint(double, double)" << endl;
	}

	friend std::ostream & operator << (std::ostream & os, const AnotherPoint & rhs);
private:
	double _dx;
	double _dy;
};

std::ostream & operator << (std::ostream & os, const AnotherPoint & rhs)
{
	os << "(" << rhs._dx << "," << rhs._dy << ")";
	return os;
}

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		
	}

	Point(AnotherPoint ap)
	: _ix(ap._dx)
	, _iy(ap._dy)
	{
	}

	friend std::ostream & operator << (std::ostream & os, const Point & rhs);
private:
	int _ix;
	int _iy;
};

std::ostream & operator << (std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix << "," << rhs._iy << ")";
	return os;
}


int main(void)
{
	Point p1;
	cout << "5 转换成";
	cout << p1 << endl;

	cout << "double类型转换成";
	double dx = 1.2;
	p1 = dx;
	cout << p1 << endl;

	AnotherPoint ap(12.34, 56.78);
	cout << ap;
	cout << "转换成";
	p1 = ap;
	cout << p1;
}
