 ///
 /// @file    Singleton.cc
 /// @author  zzseven
 /// @date    2016-02-29 19:55:33
 ///
 
#include <iostream>
#include <stdio.h>

using std::cout;
using std::endl;

class Singleton
{
public:
	static Singleton * getInstance()
	{
		if(NULL == _pInstance)
		{
			_pInstance = new Singleton;
		}
		return _pInstance;
	}

	void destroy()
	{
		cout << "destroy()" << endl;
		_pInstance = NULL;
	}
private:
	Singleton()
	{
		cout << "Singleton()" << endl;
	}
	static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance = NULL;

int main(void)
{
	Singleton * p1 = Singleton::getInstance();
	Singleton * p3 = Singleton::getInstance();
	printf("p1 = %p\n", p1);
	printf("p3 = %p\n", p3);

	p1->destroy();
	p3->destroy();
	Singleton * p2 = Singleton::getInstance();
	printf("p2 = %p\n", p2);
	return 0;
}

