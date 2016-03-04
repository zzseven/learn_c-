 ///
 /// @file    Mylog.h
 /// @author  zzseven
 /// @date    2016-03-04 17:04:38
 ///
 
#ifndef __MYLOG_H__
#define __MYLOG_H__
#include <log4cpp/Category.hh>
#include <sstream>
#include <string>
#include <iostream>

using std::string;

//将数字转换成字符串
inline string int2Str(int num) //inline meams?
{
	std::ostringstream oss;    //std::ostringstream 输出流
	oss << num;
	return oss.str();
}

class Mylog
{
public:
	static Mylog * getInstance();

	void fatal(const char * msg);
	void error(const char * msg);
	void info(const char * msg);
	void debug(const char * msg);

private:
	Mylog();

private:
	log4cpp::Category & _cat;
	static Mylog * _pInstance;  //单例模式，只能存在一个这样的对象
};

#ifdef _MYLOG4CPP_
Mylog * plog = Mylog::getInstance();
#else
extern Mylog * plog;
#endif

//宏定义的完美使用
#define postfix(msg)  string(msg).append(" { ").append(__FILE__)\
								 .append("_").append(__func__)\
								 .append("_").append(int2Str(__LINE__))\
								 .append(" } ").c_str()

#define LOG_FATAL(msg)  plog->fatal(postfix(msg))
#define LOG_ERROR(msg)  plog->error(postfix(msg))
#define LOG_INFO(msg)   plog->info(postfix(msg))
#define LOG_DEBUG(msg)  plog->debug(postfix(msg))

#endif
