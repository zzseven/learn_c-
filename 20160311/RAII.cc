 ///
 /// @file    RAII.cc
 /// @author  zzseven
 /// @date    2016-03-11 21:13:32
 ///
 
#include <iostream>

using std::cout;
using std::endl;

template<typename T>
class RAII
{
public:
	RAII(T * p) : _p(p)
	{
		cout << "RAII()" << endl;
	}

	T * get() const
	{
		return _p;
	}

	T & operator *() const
	{
		return *_p;
	}

	void reset(T * p)
	{
		delete _p;
		_p = p;
	}

	~RAII()
	{
		cout << "~RAII()" << endl;
		delete _p;
	}
private:
	RAII(const RAII & rhs);
	RAII & operator=(const RAII & rhs);
private:
	T * _p;
};


class SomeResource
{};

class Example
{
public:
	Example()
	: _p1(new SomeResource)
	, _p2(new SomeResource)
	{
		cout << "Example()" << endl;
	}

	Example(const Example & rhs)
	: _p1(new SomeResource(*rhs._p1))
	, _p2(new SomeResource(*rhs._p2))
	{
		cout << "Example(const Example & rhs)" << endl;	
	}

	Example & operator=(const Example & rhs)
	{
		if(this != &rhs)
		{
			*_p1 = * rhs._p1;
			*_p2 = * rhs._p2;
		}
		return *this;
	}

	~Example()
	{
		cout << "~Example()" << endl;
	}
private:
	RAII<SomeResource> _p1;
	RAII<SomeResource> _p2;
};

int main(void)
{
	Example example;
	int *p1 = new int(5);
	delete p1;
	cout << endl << endl;

	RAII<int> raiiInt(new int(3));
}

