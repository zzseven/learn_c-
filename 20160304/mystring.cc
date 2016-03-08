 ///
 /// @file    mystring.cc
 /// @author  zzseven
 /// @date    2016-03-05 09:07:38
 ///

#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
using std::cin;

class String {
public:
	String();
	String(const char * pstr);
	String(const String& lhs);
	~String();
	String &operator=(const String & lhs);
	String &operator=(const char * pstr);

	String &operator+=(const String & lhs);
	String &operator+=(const char * pstr);

	char &operator[](std::size_t index);
	const char &operator[](std::size_t index) const;

	std::size_t size() const;
	const char* c_str() const;

	friend bool operator==(const String & lhs, const String & rhs);
	friend bool operator!=(const String & lhs, const String & rhs);

	friend bool operator<(const String & lhs, const String & rhs);
	friend bool operator>(const String & lhs, const String & rhs);
	friend bool operator<=(const String & lhs, const String & rhs);
	friend bool operator>=(const String & lhs, const String & rhs);

	friend std::ostream &operator<<(std::ostream &os, const String &s);
	friend std::istream &operator>>(std::istream &is, String &s);

private:
	char *pstr_;
};


String::String()
{
	pstr_ = new char[1]; //申请1字节空间,便于统一delete
	pstr_[0] = '\0';
	cout << "String()" << endl;
}

String::String(const char * pstr)
{
	pstr_ = new char[strlen(pstr)+1];
	strcpy(pstr_, pstr);
	cout << "String(pstr)" << endl;
}

String::String(const String & lhs) //这里是直接指针赋值，还是重新申请内存？
//: pstr_(lhs.pstr_)
{
	pstr_ = new char[strlen(lhs.pstr_)+1];
	strcpy(pstr_, lhs.pstr_);
	cout << "String(String)" << endl;
}

String::~String()
{
	delete [] pstr_;
	cout << "~String()" << endl;
}

String & String::operator=(const String & lhs)
{
	//不加this也应该不会错
	if(this == &lhs)
		return *this;
	delete [] pstr_;
	pstr_ = new char[strlen(lhs.pstr_)+1];
	strcpy(this->pstr_, lhs.pstr_);
	cout << "string = string;" << endl;
	return *this;
}

String & String::operator=(const char * pstr)
{
	String s(pstr);
	*this = s;
	cout << "string = pstr;" << endl;
	return *this;
}

String& String::operator +=(const String & lhs)
{
	int len = strlen(this->pstr_) + strlen(lhs.pstr_);
	char * str = new char[len + 1];
	strcpy(str, this->pstr_);
	strcat(str, lhs.pstr_);
	delete [] this->pstr_;
	this->pstr_ = str;
	str = NULL;
	cout << "string += string"  << endl;
	return *this;
}

String & String::operator +=(const char * pstr)
{
	String s(pstr);
	*this += s;
	cout << "string += char"  << endl;
	return *this;

}

char & String::operator[](std::size_t index)
{
	static char nullchar = '\0';
	if(index < this->size() && index >= 0)
	{
		return pstr_[index];
	}
	else
	{
		cout << "下标越界" << endl;
		return nullchar;
	}
}
const char & String::operator[](std::size_t index) const //有点疑惑！！！！
{
	static  char nullchar = '\0';
	if(index < this->size() && index >= 0)
	{
		return pstr_[index];
	}
	else
	{
		cout << "下标越界" << endl;
		return nullchar;
	}
}

std::size_t String::size() const
{
	return strlen(this->pstr_);	
}
const char* String::c_str() const
{
	return this->pstr_;
}

bool operator==(const String & lhs, const String & rhs)
{
	if(strcmp(lhs.pstr_, rhs.pstr_) == 0)
		return true;
	else
		return false;
}

bool operator!=(const String & lhs, const String & rhs)
{
	if(strcmp(lhs.pstr_, rhs.pstr_) != 0)
		return true;
	else
		return false;
}

bool operator<(const String & lhs, const String & rhs)
{
	if(strcmp(lhs.pstr_, rhs.pstr_) < 0)
		return true;
	else
		return false;
}

bool operator>(const String & lhs, const String & rhs)
{
	if(strcmp(lhs.pstr_, rhs.pstr_) > 0)
		return true;
	else
		return false;
}

bool operator<=(const String & lhs, const String & rhs)
{
	if(strcmp(lhs.pstr_, rhs.pstr_) <= 0)
		return true;
	else
		return false;
}

bool operator>=(const String &lhs, const String & rhs)
{
	if(strcmp(lhs.pstr_, rhs.pstr_) >= 0)
		return true;
	else
		return false;
}

std::ostream &operator<<(std::ostream &os, const String & s)
{
	os << s.pstr_;
	return os;
}

std::istream &operator>>(std::istream &is, String & s)
{
	char buf[100];
	is >> buf;
	s += buf;
	return is;
}


String operator+(const String & lhs, const String & rhs)
{
	String tmp(lhs);
	tmp += rhs;
	return tmp;
}

String operator+(const String & lhs, const char * pstr)
{
	String tmp(lhs);
	tmp += pstr;
	return tmp;
}

String operator+(const char * pstr, const String & rhs) 
{
	String tmp(pstr);
	tmp += rhs;
	return tmp;
}






int main(void)
{


}
