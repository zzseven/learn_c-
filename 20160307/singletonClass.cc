 ///
 /// @file    singletonClass.cc
 /// @author  zzseven
 /// @date    2016-03-07 21:00:27
 ///
 
#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class Sigletion
{
public:
	static Sigletion * getInstance();
	void destroy()
	{
		_pInstance = NULL;
	}
private:
	Sigletion()
	{
		cout << "Sigletion()" << endl;
	}
private:
	static  Sigletion * _pInstance;
};


template <typename T> 
Sigletion<T> * Sigletion<T>::_pInstance = 0;


template <typename T> 
Sigletion<T> * Sigletion<T>::getInstance()
{
	if(NULL == _pInstance)
	{
		_pInstance = new Sigletion;
	}
	return _pInstance;
}


int main(void)
{
	Sigletion<char> * p1 = Sigletion<char>::getInstance();	
	Sigletion<char> * p2 = Sigletion<char>::getInstance();	
	p1->destroy();

	Sigletion<char> * p3 = Sigletion<char>::getInstance();	
}

