 ///
 /// @file    log4cppTest.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-02 15:34:58
 ///

#include <iostream>
#include <string>
#include <sstream>
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>

int main(void)
{
	log4cpp::PatternLayout * ptnLayout1 = 
		new log4cpp::PatternLayout();
	ptnLayout1->setConversionPattern("%d:%p %c %x: %m%n");

	log4cpp::PatternLayout * ptnLayout2 = 
		new log4cpp::PatternLayout();
	ptnLayout2->setConversionPattern("%d:%p %c %x: %m%n");

	log4cpp::Appender * appender = 
		new log4cpp::FileAppender("fileAppd", "wangdao.log");
	appender->setLayout(ptnLayout1);

	log4cpp::Appender * appender2 = 
		new log4cpp::RollingFileAppender(
				"rollingFileAppd",
				"roll_wangdao.log",
				5 * 1024,
				1);
	appender2->setLayout(ptnLayout2);

	log4cpp::Category & root = log4cpp::Category::getRoot();
	log4cpp::Category & infoCat = root.getInstance("infoCat");
	infoCat.setPriority(log4cpp::Priority::ERROR);
	//infoCat.setPriority(log4cpp::Priority::DEBUG);
	infoCat.addAppender(appender);
	infoCat.addAppender(appender2);

	for(int idx = 0; idx < 100; ++idx)
	{
		std::ostringstream oss;
		oss << idx << ":Root Error Message!";

		std::string strErr = oss.str();
		infoCat.error(strErr);
	}

	log4cpp::Category::shutdown();
	return 0;
}
