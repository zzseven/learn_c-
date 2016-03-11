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
	String(const String & rhs)
	{
		cout << "String(const & rhs)" << endl;
		_pstr = new char(strlen(rhs._pstr)+1);
		strcpy(_pstr, rhs._pstr);
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
	~String()
	{
		cout << "~Sring()" << endl;
		delete [] _pstr;
	}
private:
	char * _pstr;

};


int main(void)
{

	vector<String> vecStr;
	vecStr.push_back("hello world!");
	return 0;
}
