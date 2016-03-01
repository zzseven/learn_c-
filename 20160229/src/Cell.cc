 ///
 /// @file    Cell.cc
 /// @author  zzseven
 /// @date    2016-02-29 19:47:42
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Cell
{

};

class CellX
{
	int a; //4
	char b; //1
	float c; //4
	double d;//8
	short e[5];//10
	char & f; //8 //64位系统地址8个字节
	double & g; //8
	static int h; //4
};

int main(void)
{
	Cell c1;
	cout << sizeof(Cell) << endl;
	Cell c2;//只为区别c1和c2是不同的对象，所以还是会开辟一字节空间
	cout << "sizeof(CellX) = " << sizeof(CellX) << endl; //显示56是因为对齐
}
