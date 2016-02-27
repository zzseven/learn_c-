 ///
 /// @file    Point2.cc
 /// @author  zzseven
 /// @date    2016-02-26 23:15:17
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:

	Point()
	: _iy(1)
	, _ix(_iy)
	{
		cout << "Point()" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

	void print()
	{
		cout << "(" << _ix << ", " << _iy << ")" <<endl;
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
