 ///
 /// @file    friend3.cc
 /// @author  zzseven
 /// @date    2016-03-03 19:57:37
 ///
 
#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

class Point
{
	friend class Line; //友元类
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
			 << ")" << endl;
	}
private:
	int _ix;
	int _iy;
};

class Line
{
public:
	float distance(const Point & lhs, const Point & rhs)
	{
		return sqrt((lhs._ix - rhs._ix) * (lhs._ix - rhs._ix) +
				    (lhs._iy - rhs._iy) * (lhs._iy - rhs._iy));
	}
	
	void setPoint(Point & pt, int ix, int iy)
	{
		pt._ix = ix;
		pt._iy = iy;
	}
};



int main(void)
{
	Line line;
	Point pt1(1, 3);
	Point pt2(4, 5);

	pt1.print();
	cout << endl;
	pt2.print();

	cout << "The distandce from pt1 to pt2: " ;
	cout << line.distance(pt1, pt2) << endl;
	line.setPoint(pt1, 10, 11);
	pt1.print();
}


