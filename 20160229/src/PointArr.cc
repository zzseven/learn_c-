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
	Point()
	{
		cout << "Point()" << endl;
	}

	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int, int)" << endl;
		static int iCount = 0;
		++iCount; //效率更高
		cout << "调用" << iCount << "次构造函数" << endl;
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
	//Point ptArr1[2];
	Point pt1(1, 2);

	Point ptArr2[2] = {Point(1, 2), Point(3, 4)}; //匿名对象
	Point ptArr3[] = {Point(1, 2), Point(3, 4)};
	Point ptArr4[5] = {Point(1, 2), Point(3, 4)};

}
