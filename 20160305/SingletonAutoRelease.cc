 ///
 /// @file    SingletonAutoRelease.cc
 /// @author  zzseven
 /// @date    2016-03-10 11:14:27
 ///
 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using std::cout;
using std::endl;

class Singleton
{
public:
	static Singleton * getInstance();
private:
	class AutoRelease
	{
	public:
		AutoRelease()
		{
			cout << "AutoRelease()" << endl;
		}
		~AutoRelease()
		{
			if(_pInstance != NULL)
			{
				delete _pInstance;
				cout << "~AutoRelease()" << endl;
			}
		}
	};

	Singleton();
	~Singleton();
private:
	static Singleton * _pInstance;
	static AutoRelease _autoRelease;
};



Singleton * Singleton::_pInstance = NULL;
Singleton::AutoRelease Singleton::_autoRelease;

Singleton * Singleton::getInstance()
{
	if(_pInstance == NULL)
		_pInstance = new Singleton;
	return _pInstance;
}

Singleton::Singleton()
{
	cout << "Singleton()" << endl;
}

Singleton::~Singleton()
{
	cout << "~Singleton()" << endl;
}

int main(void)
{
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	printf("p1 = %p \n", p1);
	printf("p2 = %p \n", p2);

	return 0;
}
