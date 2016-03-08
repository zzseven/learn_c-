 ///
 /// @file    siglation_template.cc
 /// @author  zzseven
 /// @date    2016-03-08 17:11:56
 ///
 
#include <stdlib.h>
#include <pthread.h>
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
public:
	static T * getInstance();
	static void init();
	static void destroy();

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
	static pthread_once_t _once;
};


template <typename T>
T * Singleton<T>::_pInstance = NULL;

template <typename T>
pthread_once_t Singleton<T>::_once = PTHREAD_ONCE_INIT;

template <typename T>
void Singleton<T>::init()
{
	//atexit 函数注册的函数在main退出的时候会被自动调用
	atexit(destroy);
	if(_pInstance == NULL)
		_pInstance = new T;
}


template <typename T>
T * Singleton<T>::getInstance()
{
	//pthread_once函数能保证其注册的函数在多线程环境中
	//只被执行一次
	pthread_once(&_once, init);
	return _pInstance;
}

template <typename T>
void Singleton<T>::destroy()
{
	if(_pInstance)
		delete _pInstance;
}


int main(void)
{
	MyClass * p1 = Singleton<MyClass>::getInstance();
	MyClass * p2 = Singleton<MyClass>::getInstance();

	cout << "p1 = " << std::hex << p1 << endl;
	cout << "p2 = " << std::hex << p2 << endl;
}
