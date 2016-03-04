 ///
 /// @file    testmylog.cc
 // @author  zzseven
 /// @date    2016-03-04 19:31:54
 ///
 

#define _MYLOG4CPP_

#include "Mylog.h"
#include <string>
#include <sstream>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(void)
{
	cout << __FILE__ << endl;
	cout << __LINE__ << endl;
	cout << __func__ << endl;
	cout << endl;

	cout << "hello,"" world" << endl;

	LOG_FATAL("system core dump");
	LOG_ERROR("system error");
	LOG_INFO("ststem info");
	LOG_DEBUG("system debug");

	return 0;
}
