 ///
 /// @file    Singleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-02-29 14:57:01
 ///
 
#include <stdio.h>
#include <iostream>
//单例模式的对象：
//1. 不能是栈对象
//2. 应该是一个堆对象
//3. 不能直接通过new的方式去创建堆对象
//4. 需要把构造函数放入private区域
//5. 用静态成员函数来创建对象
//6. 创建好的对象需要使用静态数据成员进行保存

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

	static void destroy()
	{
		delete _pInstance;
		//~Singleton();
	}

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
	static Singleton * _pInstance;

};

Singleton * Singleton::_pInstance = NULL;

int main(void)
{
	//Singleton * p1 = new Singleton;//希望该语句不能正常执行
	//Singleton * p2 = new Singleton;
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	Singleton * p3 = Singleton::getInstance();
	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);
	printf("p3 = %p\n", p3);

	Singleton::destroy();

	return 0;
}
