 ///
 /// @file    nesteTemplate.cc
 /// @author  zzseven
 /// @date    2016-03-07 22:18:20
 ///
 
#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class Outside
{
public:
	template <class R>
	class Inside(R x)
	{
	public:
		Inside()
		: _r(x)
		{
			cout << "Inside()" << endl;
		}
		void display();
	private:
		R _r;
			
	};

public:
	Outside(T x)
	: _t(x)
	{
		cout << "outside()" << endl;
	}

	void display()
	{
		cout << "Outside: ";
		_t.display();
	}

private:
	Inside<T> t;
};


