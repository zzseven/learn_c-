 ///
 /// @file    Point3.cc
 /// @author  zzseven
 /// @date    2016-02-26 23:20:17
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

	Point(int ix, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int, int)" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}
	
	void print()
	{
		cout << "(" << _ix << ", " << _iy << ")" << endl;
	}

private:
	int _ix;
	int _iy;

};

int main(void)
{
	Point pt1;
	pt1.print();

	cout << endl;

	Point pt2 = 3; // 隐式转换，通过相应的构造函数出创建一个临时对象
				   // 再将这个临时对象通过复制构造函数来初始的pt2;

	pt2.print();

	return 0;
}

