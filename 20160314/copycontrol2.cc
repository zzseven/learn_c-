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
	Base()
	{
		_pstr1 = new char[1];
	}

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
		cout << "Base:" << _pstr1 << ",";
	}

private:
	char * _pstr1;
};

class Derived : public Base
{
public:
	Derived(const char * pstr1, const char * pstr2)
	: Base(pstr1)
	{
		cout << "Derived(const char *)" << endl;
		_pstr2 = new char [strlen(pstr2) + 1];
		strcpy(_pstr2, pstr2);
	}
	
	Derived(const Derived & rhs)
	: Base(rhs)
	{
		cout << "Derived(const Derived &)" << endl;
		_pstr2 = new char[strlen(rhs._pstr2) + 1];
		strcpy(_pstr2, rhs._pstr2);
	}

	Derived & operator=(const Derived & rhs)
	{
		Base::operator=(rhs);
		cout << "Derived & operator=(const Derived &)" << endl;
		if(this != &rhs)
		{
			delete [] _pstr2;
			_pstr2 = new char[strlen(rhs._pstr2) + 1];
			strcpy(_pstr2, rhs._pstr2);

		}
		return * this;
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
	}

	void printDerived()
	{
		printBase();
		cout << "Derived:" << _pstr2 << endl;
	}

private:
	char * _pstr2;

};

int main(void)
{
	Derived d1("hello", "world");
	d1.printDerived();
	Derived d2(d1);
	d2.printDerived();
	Derived d3("xxxx", "yyyy");
	d3.printDerived();
	cout << endl << endl;
	d2 = d3;
	d2.printDerived();

	return 0;
}

