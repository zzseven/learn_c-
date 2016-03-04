 ///
 /// @file    block.cc
 /// @author  zzseven
 /// @date    2016-03-03 17:25:24
 ///
 
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	void Work(int, int);
	Work(5, 6);
	return 0;
}

void Work(int a, int b)
{
	class point
	{
	private:
		int x, y;
	public:
		point(int xp = 0, int yp = 0)
		{
			x = xp;
			y = yp;
		}
		void print()
		{
			cout << x << ", " << y << endl;
		}
	};

	point pt(a, b);
	pt.print();
}
