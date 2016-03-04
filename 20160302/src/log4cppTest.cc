 ///
 /// @file    log4cppTest.cc
 /// @author  zzseven
 /// @date    2016-03-03 10:49:09
 ///
 
#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>

int main(void)
{
	//初始化一个appender对象
	log4cpp::Appender * appender = 
		new log4cpp::OstreamAppender("console", &std::cout); 
	//将basiclayout对象附到appender对象上
	appender->setLayout(new log4cpp::BasicLayout());
	//实例化一个category对象
	log4cpp::Category & root = log4cpp::Category::getRoot();
	//设置category的优先级，低于此优先级的日志不被记录
	root.setPriority(log4cpp::Priority::DEBUG);
	//把appender对象附到category对象上
	root.setAppender(appender);

	//记录一些日志
	root.error("root error");
	root.info("root info");
	root.warn("%d + %d = %s", 1, 1, "two");
}
