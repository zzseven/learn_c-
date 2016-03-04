 ///
 /// @file    class_in.cc
 /// @author  zzseven
 /// @date    2016-03-03 17:17:21
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class line
{
public:
	class point
	{
	private:
		int x;
		int y;
	public:
		point(int xp = 0, int yp = 0)
		{
			x = xp;
			y = yp;
		}
		void printpoint();
	};
private:
	point p1, p2;

public:
	line(int x1, int y1, int x2, int y2)
	: p1(x1, y1)
	, p2(x2, y2)
	{
	
	}

	void printline()
	{
		p1.printpoint();
		cout << "--->";
		p2.printpoint();
		cout << endl;
	}
};

void line::point::printpoint()
{
	cout << "("
		 << x
		 << ","
		 << y
		 << ")";
}

int main(void)
{
	line line1(1, 2, 3, 4);
	line1.printline();
	
	line::point pt(1, 3);
	pt.printpoint();

	cout << endl;
	return 0;
}
