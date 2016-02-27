 ///
 /// @file    Point1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-02-27 10:08:52
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix, int iy);

	Point(const Point & rhs);

	void print();

private:
	const int _ix;//常量的初始化必须放在初始化列表里面进行
	const int _iy;
};


Point::Point(int ix, int iy)
: _ix(ix)
, _iy(iy)
{
	//_ix = ix;//赋值语句
	//_iy = iy;
	cout << "Point(int,int)" << endl;
}

Point::Point(const Point & rhs)
: _ix(rhs._ix)
, _iy(rhs._iy)
{
	cout << "Point(const Point &)" << endl;	
}

void Point::print()
{
	cout << "(" << _ix 
		 << "," << _iy
		 << ")" << endl;
}

int main(void)
{
	Point pt1(3, 4);
	pt1.print();

	return 0;
}

