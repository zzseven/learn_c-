 ///
 /// @file    nestedclass.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-04 15:15:51
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Line
{
public:
	class Point
	{
	public:
		Point(int ix = 0, int iy = 0)
		: _ix(ix)
		, _iy(iy)
		{
			cout << "Point(int,int)" << endl;
		}

		void printPoint();
	private:
		int _ix;
		int _iy;
	};

public:
	Line(int x1, int y1, int x2, int y2)
	: _pt1(x1, y1)
	, _pt2(x2, y2)
	{
		cout << "Line(int,int,int,int)" << endl;
	}

	void printLine()
	{
		_pt1.printPoint();
		cout << "--->";
		_pt2.printPoint();
		cout << endl;
	}
private:
	Point _pt1;
	Point _pt2;
};

void Line::Point::printPoint()
{
	cout << "(" << _ix << "," << _iy << ")";
}


int main(void)
{
	Line line(1, 2, 3, 4);
	line.printLine();

	Line::Point pt(10, 11);
	pt.printPoint();
	cout << endl;
}
