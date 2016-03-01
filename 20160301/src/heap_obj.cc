 ///
 /// @file    operator_new.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-01 10:13:07
 ///
 
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

//只能生成堆对象，不能生成栈对象：
//　　只需要把析构函数放入private区域
//　对于堆对象的销毁，需要再写public的destroy函数

class Student
{
public:
	Student()
	{
		cout << "Student()" << endl;
	}

	void destroy()
	{
		delete this;
	}

private:
	~Student()
	{
		cout << "~Student()" << endl;
	}

private:
	int _iId;
	char _name[20];
};

int main(void)
{
	Student * pStu = new Student;
	pStu->destroy();
	//delete pStu;
	//Student stu;

	return 0;
}
