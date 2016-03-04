 ///
 /// @file    operator_new.cc
 /// @author  zzseven
 /// @date    2016-03-01 20:14:27
 ///
 
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

class Student
{
public:
	Student()
	{
		cout << "Student()" << endl;
	}
	~Student()
	{
		cout << "~Student()" << endl;
	}
#if 1 //只能生成栈对象,operator只能放在private区域，只能 通过new生成堆对象则相反
private:   
#endif
	static void * operator new(size_t sz)
	{
		cout << "operator new()" << endl;
		void * pRet = malloc(sz);
		return pRet;
	}
	static void  operator delete(void * pRet)
	{
		cout << "operator delete()" << endl;
		free(pRet);
	}
	//static void * operator new(size_t sz);// 用的时候放个声明就行了。
	//static void  operator delete(void * pRet);
private:
	int _iId;
	char _name[20];
};

int main(void)
{
	//Student * pStu = new Student;
	//delete pStu;
	Student pStu;

	return 0;
}



