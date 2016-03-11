 ///
 /// @file    String.cc
 /// @author  zzseven
 /// @date    2016-03-11 09:57:35
 ///
 
#include <string.h>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class String
{
public:
	String()
	{
		cout << "String()" << endl;
		_pstr = new char[1];
	}
	String(const char * pstr)
	{
		cout << "String(const char *)" << endl;
		_pstr = new char[strlen(pstr)+1];
		strcpy(_pstr, pstr);
	}
	String(const String & rhs) //复制构造函数
	{
		cout << "String(const & rhs)" << endl;
		_pstr = new char(strlen(rhs._pstr)+1);
		strcpy(_pstr, rhs._pstr);
	}
	String(String && rhs)//移动构造函数
	: _pstr(rhs._pstr)
	{
		cout << "String(String && rhs)" << endl;
		rhs._pstr = NULL;
	}


	String & operator=(const String & rhs)
	{
		cout << "operator-(const String & rhs)" << endl;;
		if(this != &rhs)
		{
			delete [] _pstr;
			_pstr = new char[strlen(rhs._pstr)+1];
			strcpy(_pstr, rhs._pstr);
		}
		return *this;
	}

	String & operator=(String && rhs) //移动赋值构造函数
	{
		cout << "operator=(String && rhs)" << endl;
		if(this != &rhs)
		{
			delete [] _pstr;
			_pstr = rhs._pstr;
			rhs._pstr = NULL;
		}
		return * this;
	}

	String & operator+=(const String & rhs)
	{
		cout << "operator +=  rhs" << endl;
		char * ptmp = new char[strlen(_pstr) + strlen(rhs._pstr) + 1];
		strcat(ptmp, rhs._pstr);
		_pstr = ptmp;
		return *this;
	}

	~String()
	{
		cout << "~Sring()" << endl;
		delete [] _pstr;
	}
	friend std::ostream & operator<<(std::ostream & os, const String & rhs);

private:
	char * _pstr;

};

std::ostream & operator<<(std::ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}

String operator+(const String &lhs, const String &rhs)
{
	cout << "lhs + rhs" << endl;
	String tmp(lhs);
	tmp += rhs;
	return tmp;
}

int main(void)
{
#if 0
	vector<String> vecStr;
	vecStr.push_back("hello world!");
#endif

	String s1 = "hello";
	String s2 = "world";
	String s3;
	s3 = s1 + s2;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;

	s3 = s1;
	cout << "s3 = " << s3 << endl;
	cout << "s1 = " << s1 << endl;
	cout << endl << endl;
	s3 = "hello";
	s3 = std::move(s1);//一旦使用std::move库函数是，就表示在以后不再使用s1,s1的内容已经被转移了。
	cout << "s3 = " << s3 << endl;
	s1 = "hi,zz!";
	cout << "s1 = " << s1 << endl;//s1输出不了
	cout << "hello world" << endl;
	return 0;
}
