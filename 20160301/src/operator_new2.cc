 ///
 /// @file    operator_new.cc
 /// @author  zzseven
 /// @date    2016-03-01 20:14:27
 ///
 
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

//只能生成堆对象，不能放入栈对象
//1.只需要把析构函数放入private区域
//2.对于堆对象的销毁，要再写一个public的的destroy的销毁函数
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
	//Student pStu2;

	return 0;
}



