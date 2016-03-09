 ///
 /// @file    associative_container4.cc
 /// @author  zzseven
 /// @date    2016-03-08 19:03:58
 ///
 
#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::multimap;
using std::pair;
using std::string;

int main(void)
{
	pair<int, string> p1(600036, "招商银行");
	cout << p1.first << " --> " << p1.second << endl;

	pair<int, string> pairArr[4] = {
		pair<int, string>(9, "Asia"),
		pair<int, string>(4, "Africa"),
		pair<int, string>(1, "Euro"),
		pair<int, string>(4, "America")
	};

	multimap<int, string> mapIntstr(pairArr, pairArr + 4);
	cout << mapIntstr.size() << endl;

	multimap<int, string>::iterator it;
	for(it = mapIntstr.begin(); it != mapIntstr.end(); ++it)
	{
		cout << it->first << "-->"
			 << it->second << endl;
	}

	cout << endl;
	//cout << mapIntstr[4] << endl;  //前方高能： multimap是不能使用下标访问运算符的
}

