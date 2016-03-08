 ///
 /// @file    template.cc
 /// @author  zzseven
 /// @date    2016-03-07 18:57:51
 ///
 
#include <iostream>

using std::cout;
using std::endl;

//普通函数优先于函数模板的执行

int max(int i1, int i2)
{
	cout << "Nomal max:" << endl;
	return i1 > i2 ? i1 : i2;
}

template <typename T>
T max(T i1, T i2)
{
	cout << "Template max:" << endl;
	return i1 > i2 ? i1 : i2;
}


int main(void)
{
	int i1 = 2, i2 = 9;
	char c1 = 'a';
	char c2 = 'z';
	int iRet = max(i1, i2);
	cout << iRet << endl;
	char cRet = max(c1, c2);
	cout << cRet << endl;

	int iRet2 = max(c1, c2);
	cout << iRet2 << endl;
	char cRet2 = max<char>(i1, i2);
	cout << cRet2 << endl;
}
