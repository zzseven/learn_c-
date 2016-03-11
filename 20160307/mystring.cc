 ///
 /// @file    mystring.cc
 /// @author  zzseven
 /// @date    2016-03-10 09:56:01
 ///
 
#include <iostream>
#include <stdio.h>
#include <string.h>

using std::cout;
using std::endl;

class String
{
private:
	class CharProxy
	{
	public:
		CharProxy(String & theString, int idx);

		char & operator=(const char & ch);

		operator char()
		{
			cout << "CharProxy::operator char()" << endl;
			return _theString._pstr[_idx];
		}
	private:
		String & _theString;
		int _idx;
	};
public:
	String();
	String(const char * pstr);
	String(const String & rhs);
	~String();
	String & operator = (const String & rhs);
	
	CharProxy operator[](int idx);
	//char & operator[](int idx);
	const char & operator[](int idx) const;

	int size();

	int use_count();

	const char * c_str() const
	{
		return _pstr;
	}

	void print() const
	{
		cout << _pstr << endl;
	}

private:
	char * _pstr;
};


String::String()
: _pstr(new char [2])
{
	cout << "string()" << endl;
	_pstr[1] = 1; //引用计数初值为1
}

String::String(const char * pstr)
{
	cout << "String(const char * pstr)" << endl;
	int len = strlen(pstr);
	_pstr = new char[len + 2];
	strcpy(_pstr, pstr);
	cout << _pstr[len + 1] << "  " << _pstr[len + 2];
	_pstr[len + 1] = 1;
}


String::String(const String & rhs)
: _pstr(rhs._pstr)
{
	cout << "String(const String & rhs)" << endl;
	++_pstr[size() + 1];
}

String & String::operator=(const String & rhs)
{
	cout << "String & operator=(const String &)" << endl;
	if(this == & rhs)
	{
		return *this;
	}

	if(-- _pstr[size() + 1] == 0)
		delete [] _pstr;

	_pstr = rhs._pstr;
	++_pstr[size() + 1];

	return * this;
}

String::~String()
{
	if(-- _pstr[size() + 1] == 0)
	{
		delete [] _pstr;
		cout << "~String()" << endl;
	}
}

String::CharProxy::CharProxy(String & theString, int idx)
: _theString(theString)
, _idx(idx)
{
	cout << "CharProxy()" << endl;
}
const char & String::operator[](int idx) const
{
	cout << "const operator[]()" << endl;
	return _pstr[idx];
}


String::CharProxy String::operator[](int idx)
{
	return CharProxy(*this, idx);
}


char & String::CharProxy::operator=(const char & ch)
{
	cout << "CharProxy & operator = (const char &)" << endl;
	if(_idx >= 0 && _idx < _theString.size())
	{
		if(_theString._pstr[_theString.size() +1 ] == 1)
		{
			_theString._pstr[_idx] = ch;
			return _theString._pstr[_idx];
		}
		else
		{
			--_theString._pstr[_theString.size() + 1];
			char * ptmp = _theString._pstr;
			_theString._pstr = new char[_theString.size() + 2];
			strcpy(_theString._pstr, ptmp);
			_theString._pstr[_theString.size() + 1] = 1;
			_theString._pstr[_idx] = ch;
			return _theString._pstr[_idx];
		}
	}
	else
	{
		static char nullchar = '\0';
		cout << "下标越界" << endl;
		return nullchar;
	}

}


int String::size()
{
	return strlen(_pstr);
}

int String::use_count()
{
	return _pstr[size() + 1];
}


int main()
{
	String s1 = "hello world";
	String s2 = s1;
	String s3;
	s3 = s2;
	cout << "s1's use_count = " << s1.use_count() << endl;
	cout << "s2's use_count = " << s2.use_count() << endl;
	cout << "s3's use_count = " << s3.use_count() << endl;
	printf("s1's address = %p\n", s1.c_str());
	printf("s2's address = %p\n", s2.c_str());
	printf("s3's address = %p\n", s3.c_str());

	s1.print();
	s2.print();
	s3.print();

	s3[0] = 'G';
	cout << endl;
	cout << "s3修改之后" << endl;
	cout << "s1's use_count = " << s1.use_count() << endl;
	cout << "s2's use_count = " << s2.use_count() << endl;
	printf("s1's address = %p\n", s1.c_str());
	printf("s2's address = %p\n", s2.c_str());
	printf("s3's address = %p\n", s3.c_str());

	s1.print();
	s2.print();
	s3.print();

	cout << endl << "执行读操作" << endl;
	cout << s1[0] << endl;
	
	cout << "s1's use_count = " << s1.use_count() << endl;
	cout << "s1's use_count = " << s1.use_count() << endl;
	printf("s1's address = %p\n", s1.c_str());
	printf("s2's address = %p\n", s2.c_str());
	printf("s3's address = %p\n", s3.c_str());

	s1.print();
	s2.print();
	s3.print();

	cout << endl << endl;
	const String s4 = "wangdao";
	cout << s4[0] << endl;
}







