 ///
 /// @file    friend2.cc
 /// @author  zzseven
 /// @date    2016-03-03 20:31:47
 ///
 
#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

class Point; //类前声明

class Line
{
public:
	float distance(const Point & lhs, const Point & rhs);
};

class Point
{
	//一个类的成员函数为另一个类的友元函数
	friend float Line::distance(const Point & lhs, const Point & rhs);
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point()" << endl;
	}

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")";
	}
private:
	int _ix;
	int _iy;
};

float Line::distance(const Point & lhs, const Point & rhs)
{
	return sqrt((lhs._ix - rhs._ix) * (lhs._ix - rhs._ix) + 
			    (lhs._iy - rhs._iy) * (lhs._iy - rhs._iy));
}

int main(void)
{
	Line line;
	Point pt1(1, 2);
	Point pt2(4, 5);

	pt1.print();
	cout << endl;
	pt2.print();
	cout << endl;

	cout << "The distance from pt1 to pt2: ";
	cout << line.distance(pt1, pt2) << endl;
}
