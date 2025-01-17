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
	Point(int ix, int iy, double & z);
	Point(const Point &rhs);
	void print();
	void setX(int ix);
private:
	int _ix;
	int _iy;
	int & _ref1; //引用必须要在初始化列表进行初始化
	double & _ref2;

};

Point::Point(int ix, int iy, double & z)
: _ix(ix)
, _iy(iy)
, _ref1(_ix)
, _ref2(z)
{	         //常量成员必须放到初始化列表里来进行初始化
	//_ix = ix;//赋值语句
	//_iy = iy;
	cout << "Point(int , int)" << endl;
}

Point::Point(const Point & rhs)
: _ix(rhs._ix)
, _iy(rhs._iy)
, _ref1(rhs._ref1)
, _ref2(rhs._ref2)
{
	cout << "Point(const Point & rhs)" << endl;
}

void Point::print()
{
	cout << "(" << _ix 
		 << "," << _iy
		 << "," << _ref1
		 << "," << _ref2
		 << ")" << endl;
}

void Point::setX(int ix)
{
	_ix = ix;
}

int main(void)
{
	double d1 = 5.0;
	Point pt1(3, 4, d1);
	pt1.print();

	Point pt2 = pt1;	
//	Point pt2(pt1);
	pt2.print();

	cout << "After pt1._ix = " << endl;
	pt1.setX(7);
	pt1.print();
	pt2.print();

	return 0;
}

