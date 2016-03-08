 ///
 /// @file    siglation_template.cc
 /// @author  zzseven
 /// @date    2016-03-08 17:11:56
 ///
 

#include <iostream>

using std::cout;
using std::endl;


class MyClass
{
public:
	MyClass()
	{
		cout << "MyClass()" << endl;
	}
	~MyClass()
	{
		cout << "~MyClass()" << endl;
	}


};

template <typename T>
class Singleton
{
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
			cout << "~AutoRelease()" << endl;
			if(_pInstance)
				delete _pInstance;
		}
	};

public:
	static T * getInstance();

private:
	Singleton()
	{
		cout << "Singleton()" << endl;
	}

	~Singleton()
	{
		cout << "~Singleton()" << endl;
	}
private:
	static T * _pInstance;
	static AutoRelease _autoRelease;
};

template <typename T>
T * Singleton<T>::_pInstance = NULL;

template <typename T>
typename Singleton<T>::AutoRelease Singleton<T>::_autoRelease;


template <typename T>
T * Singleton<T>::getInstance()
{
	_autoRelease;
	if(_pInstance == NULL)
		_pInstance = new T;
	return _pInstance;
}


int main(void)
{
	MyClass * p1 = Singleton<MyClass>::getInstance();
	MyClass * p2 = Singleton<MyClass>::getInstance();

	cout << "p1 = " << std::hex << p1 << endl;
	cout << "p2 = " << std::hex << p2 << endl;
}
