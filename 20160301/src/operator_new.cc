 ///
 /// @file    operator_new.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-01 10:13:07
 ///
 
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

//只能生成栈对象，不能生成堆对象：
//	 把operator new函数放入private区域

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
private:
	static void * operator new(size_t);
	static void operator delete(void *);
#if 0
	static void * operator new(size_t sz)
	{
		cout << "operator new()" << endl;
		void * pRet = malloc(sz);
		return pRet;
	}

	static void operator delete(void * pRet)
	{
		cout << "operator delete()" << endl;
		free(pRet);
	}
#endif

private:
	int _iId;
	char _name[20];
};

int main(void)
{
	//Student * pStu = new Student;
	//delete pStu;
	Student stu;

	return 0;
}
