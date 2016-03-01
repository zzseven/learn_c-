 ///
 /// @file    Point.cc
 /// @author  zzseven
 /// @date    2016-02-29 17:31:36
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
		cout << "Point(int, int)" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

	void setX(int ix)
	{
		_ix = ix;
	}

	void setY(int iy)
	{
		_iy = iy;
	}
	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	void print() const  //常量函数
	{
		cout << "const->(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}
private:
	int _ix;
	int _iy;
};

int main(void)
{
	Point pt(3, 4);
	pt.setX(5);
	pt.setY(6);
	pt.print(); //非const对象可以调用const成员函数,不过
				//当有非const成员的函数时，会先考虑非const成员函数

	cout << endl;

	const int a = 0;
	const Point pt2(1, 2);
	pt2.print(); //const对象无法调用非const成员函数
				 //只能调用const成员函数
}
