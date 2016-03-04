 ///
 /// @file    Mylog.cc
 /// @author  zzseven
 /// @date    2016-03-04 17:30:33
 ///
 
#include "Mylog.h" //定义的头文件要放到第一位
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>
#include <iostream>

Mylog * Mylog::_pInstance = NULL;

Mylog * Mylog::getInstance()
{
	if(_pInstance == NULL)
	{
		_pInstance = new Mylog();
	}
	return _pInstance;
}

Mylog::Mylog()
: _cat(log4cpp::Category::getRoot().getInstance("mycat"))
{
	log4cpp::PatternLayout * ptnLay1 = new log4cpp::PatternLayout();
	ptnLay1->setConversionPattern("%d{%Y-%m-%d %H:%M:%S} : %-5p %c %x: %m%n");

	log4cpp::PatternLayout * ptnLay2 = new log4cpp::PatternLayout();
	ptnLay2->setConversionPattern("%d: %-5p %c %x: %m%n");

	log4cpp::OstreamAppender * appender1 = new log4cpp::OstreamAppender("ostream", &std::cout);
	appender1->setLayout(ptnLay1);

	log4cpp::FileAppender * appender2 = new log4cpp::FileAppender("FileAppender", "mylog.log");
	appender2->setLayout(ptnLay2);

	_cat.addAppender(appender1);
	_cat.addAppender(appender2);

	_cat.setPriority(log4cpp::Priority::DEBUG);
}


void Mylog::fatal(const char * msg)
{
	_cat.fatal(msg);
}

void Mylog::error(const char * msg)
{
	_cat.error(msg);
}

void Mylog::info(const char * msg)
{
	_cat.info(msg);
}

void Mylog::debug(const char * msg)
{
	_cat.debug(msg);
}


