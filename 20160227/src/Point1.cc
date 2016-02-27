 ///
 /// @file    Point1.cc
 /// @author  zzseven
 /// @date    2016-02-27 10:09:04
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix, int iy);
	Point(const Point &rhs);
	void print();
private:
	const int _ix;
	const int _iy;
};

Point::Point(int ix, int iy)
: _ix(ix)
, _iy(iy)
{	         //常量成员必须放到初始化列表里来进行初始化
	//_ix = ix;//赋值语句
	//_iy = iy;
	cout << "Point()" << endl;
}

Point::Point(const Point & rhs)
: _ix(rhs._ix)
, _iy(rhs._iy)
{
	cout << "Point(const Point & rhs)";
}

void Point::print()
{
	cout << "_ix = " << _ix << endl;
	cout << "_iy = " << _ix << endl;
}

int main(void)
{

}

