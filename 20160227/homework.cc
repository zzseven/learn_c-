 //
 /// @file    homework.cc
 /// @author  zzseven
 /// @date    2016-02-28 14:13:24
 ///
 
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class String
{
public:
	String();
	String(const char *pstr);
	String(const String & rhs);
	String & operator=(const String & rhs);
	~String();
	void print();

private:
	char *pStr_;
};


/*********************/
String::String()
{
	pStr_ = NULL;
}

String::String(const char * pStr)
{
	pStr_ = new char[strlen(pStr) + 1];
	strcpy(pStr_, pStr);
}

String::String(const String & rhs)
{
	
	pStr_ = new char[strlen(rhs.pStr_)+1];
	strcpy(pStr_, rhs.pStr_);
}

String & String::operator=(const String & rhs)
{
	if(pStr_)
	{
		delete [] pStr_;
	}
	pStr_ = new char[strlen(rhs.pStr_)+1];
	strcpy(pStr_, rhs.pStr_);
	
	return * this;
}

String::~String()
{
	if(pStr_)
	{
		delete [] pStr_;
	}
}

void String::print()
{
	if(pStr_ == NULL)
	{
		cout << "NULL" << endl;
	}else
	{
		cout << pStr_ << endl;
	}

}

/*********************/

int main(void)
{
	String str1;
	String str2 = "Hello,world";
	String str3 = "wangdao";
	str2 = str3;
	String str4 = str3;
	
	str1.print();
	str2.print();
	str3.print();
	str4.print();
}
