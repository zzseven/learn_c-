 ///
 /// @file    String.cc
 /// @author  zzseven
 /// @date    2016-02-29 16:51:06
 ///
 
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class String
{
public:
	String();  //构造函数的返回值是void,不写
	String(const char * pstr);
	String(const String & rhs);
	String & operator = (const String & ths); // String & 是返回值，别搞错了

	~String();

	void print();
private:
	char * pstr_;
};

String::String()
//: pstr_(NULL)  //默认的别在初始化列表中定义NULL，这样做在后面又要判断，不统一，麻烦。
{
	cout << "String()" << endl;
	pstr_ = new char[1]; //申请一个字节空间，放个'\0';
	pstr_[0] = '\0';

}

String::String(const char * pstr)
{
	cout << "String(const char *)" << endl;
	pstr_ = new char[strlen(pstr) + 1];
	strcpy(pstr_, pstr);
}

String::String(const String & rhs)
{
	cout << "String(Const String &)" << endl;
	pstr_ = new char[strlen(rhs.pstr_) + 1];
	strcpy(pstr_, rhs.pstr_);
}

String & String::operator = (const String & rhs)
{
	if(this == &rhs)  //1.自复制
	{
		return *this;  //赋值运算符函数 别忘了 自复制
	}
	delete [] pstr_; //2.释放现有已申请的堆空间

	pstr_ = new char[strlen(rhs.pstr_) + 1]; //申请空间进行复制
	strcpy(pstr_, rhs.pstr_);
	return * this;
}


String::~String()
{
	delete [] pstr_; //如果默认函数，定义为空的话，这就要判断，不然程序会down掉
}

void String::print()
{
	cout << pstr_ << endl;
}

int main(void)
{
	String s1;
	s1.print();

	String s2 = "Hello, world";
	String s3 = "wangdao";
	s2.print();  
	s3.print();
	s2 = s3;  //复制构造函数
	s2.print();

	String s4 = s3; //赋值运算符函数
	s4.print();
}

