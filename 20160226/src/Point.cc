 ///
 /// @file    Point.cc
 /// @author  zzseven
 /// @date    2016-02-26 23:12:30
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
	Point()
	: _ix(0)
	, _iy(0)
	{
		cout << "Point()" << endl;
	}

	void print()
	{
		cout << "(" << _ix << ", " << _iy << endl;
	}
private:
	int _ix;
	int _iy;
};


int main(void)
{
	Point pt1;
	pt1.print();

	return 0;
}
