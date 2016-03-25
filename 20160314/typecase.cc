 ///
 /// @file    typecase.cc
 /// @author  zzseven
 /// @date    2016-03-14 21:27:55
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int, int )" << endl;
	}

	int getx() const
	{
		return _ix;
	}

	int gety() const
	{
		return _iy;
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


class Point3D : public Point
{
public:
	Point3D(int x, int y, int z)
	: Point(x, y)
	, _iz(z)
	{
		cout << "Point3D(int, int, int)" << endl;
	}

	void print3D()
	{
		cout << "(" << getx()
			 << "," << gety()
			 << "," << _iz
			 << ")" << endl;
	}

private:
	int _iz;
};

int main(void)
{
	Point p1(1, 2);
	cout << " p1 = ";
	p1.print();

	Point3D p2(4, 5, 6);
	cout << " p2 = ";
	p2.print3D();

	p1  = p2;
	cout << "p1 = ";
	p1.print();

	Point & ref1 = p2;
	cout << "ref = ";
	ref1.print();

	Point * pt = &p2;
	pt->print();
}
