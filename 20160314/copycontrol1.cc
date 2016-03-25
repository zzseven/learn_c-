 ///
 /// @file    copycontrol1.cc
 /// @author  zzseven
 /// @date    2016-03-14 21:43:05
 ///
 
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class Base
{
public:
	Base(const char * pstr)
	{
		cout << "Base(const char *)" << endl;
		_pstr1 = new char[strlen(pstr) + 1];
		strcpy(_pstr1, pstr);
	}

	Base(const Base & rhs)
	{
		cout << "Base(const Base &)" << endl;

		_pstr1 = new char[strlen(rhs._pstr1) + 1];
		strcpy(_pstr1, rhs._pstr1);
	}

	Base & operator=(const Base & rhs)
	{
		cout << "operator=(const Base&)" << endl;
		if(this != &rhs)
		{
			delete [] _pstr1;
			_pstr1 = new char[strlen(rhs._pstr1) + 1];
			strcpy(_pstr1, rhs._pstr1);
		}
		return *this;
	}

	~Base()
	{
		cout << "~Base()" << endl;
		delete [] _pstr1;
	}

	void printBase()
	{
		cout << _pstr1;
	}

private:
	char * _pstr1;
};

class Derived : public Base
{
public:
	Derived(const char * pstr)
	: Base(pstr)
	{
		cout << "Derived(const char *)" << endl;
	}
	~Derived()
	{
		cout << "~Derived()" << endl;
	}

	void printDerived()
	{
		printBase();
		cout << endl;
	}

};

int main(void)
{
	Derived d1("hello");
	d1.printDerived();
	Derived d2("world");
	cout << endl << endl;
	d2 = d1;
	d2.printDerived();

	return 0;
}

