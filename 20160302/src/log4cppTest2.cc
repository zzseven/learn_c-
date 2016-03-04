 ///
 /// @file    log4cppTest.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-02 15:34:58
 ///

#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>

int main(void)
{
	log4cpp::PatternLayout * ptnLayout = 
		new log4cpp::PatternLayout();
	ptnLayout->setConversionPattern("%d:%p %c %x: %m%n");

	log4cpp::Appender * appender = 
		new log4cpp::OstreamAppender("console", &std::cout);
	
	appender->setLayout(ptnLayout);

	log4cpp::Category & root = log4cpp::Category::getRoot();
	log4cpp::Category & infoCat = root.getInstance("infoCat");
	infoCat.setPriority(log4cpp::Priority::ERROR);
	//infoCat.setPriority(log4cpp::Priority::DEBUG);
	infoCat.setAppender(appender);

	infoCat.error("system error");
	infoCat.info("system is running");
	infoCat.warn("%d + %d = %s", 1, 1, "two");
	infoCat.fatal("sytem has a fatal error, must be shutdown");
	infoCat.info("system shutdown, you can find some information in system log");

	log4cpp::Category::shutdown();
	return 0;
}
