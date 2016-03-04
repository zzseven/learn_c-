 ///
 /// @file    friend.cc
 /// @author  zzseven
 /// @date    2016-03-03 20:23:27
 ///
 
#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

class Point
{
	friend float distance(const Point & lhs, const Point & rhs);
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

float distance(const Point & lhs, const Point & rhs)
{
	return sqrt((lhs._ix - rhs._ix) * (lhs._ix - rhs._ix) +
			    (lhs._iy - rhs._iy) * (lhs._iy - rhs._iy));
}

int main(void)
{
	Point pt1(1, 2);
	Point pt2(4, 5);

	pt1.print();
	cout << endl;
	pt2.print();
	cout << endl;

	cout << "The distance from pt1 to pt2: ";
	cout << distance(pt1, pt2) << endl;

}

