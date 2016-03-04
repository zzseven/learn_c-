 ///
 /// @file    oprator[].cc
 /// @author  zzseven
 /// @date    2016-03-04 21:34:57
 ///
 
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class CharArr
{
public:
	CharArr(int sz);
	~CharArr();

	int length();

	char & operator[](int idx);  //这里返回的是引用，所以后面可以直接赋值
private:
	int _ilen;
	char * _pstr;
};

CharArr::CharArr(int sz)
: _ilen(sz)
, _pstr(new char[_ilen])
{
	cout << "CharArr()" << endl;
}

CharArr::~CharArr()
{
	delete [] _pstr;
	cout << "~CharArr()" << endl;
}

int CharArr::length()
{  return _ilen;  }

char & CharArr::operator[](int idx)  //注意返回的是引用
{
	static char nullchar = '\0';
	if(idx < _ilen && idx >= 0)
	{
		return _pstr[idx];
	}
	else
	{
		cout << "下标越界" << endl; //链式编程
		return nullchar;
	}
}

int main(void)
{
	char * pstr = "hello, world";
	CharArr ca(strlen(pstr)+1);
#if 1
	for(int idx = 0; idx != (strlen(pstr)+1); ++idx)
	{
		ca[idx] = pstr[idx];
	}
#endif
	for(int idx = 0; idx != ca.length(); ++idx)
	{
		cout << ca[idx] << ' ';
	}
	cout << endl;
	
	
	
}
