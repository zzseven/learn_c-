 ///
 /// @file    associative_container3.cc
 /// @author  zzseven
 /// @date    2016-03-08 19:03:58
 ///
 
#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;

int main1(void)
{
	pair<int, string> p1(600036, "招商银行");
	cout << p1.first << " --> " << p1.second << endl;

	pair<int, string> pairArr[4] = {
		pair<int, string>(9, "Asia"),
		pair<int, string>(4, "Africa"),
		pair<int, string>(1, "Euro"),
		pair<int, string>(4, "America")
	};

	map<int, string> mapIntstr(pairArr, pairArr + 4);
	cout << mapIntstr.size() << endl;

	map<int, string>::iterator it;
	for(it = mapIntstr.begin(); it != mapIntstr.end(); ++it)
	{
		cout << it->first << "-->"
			 << it->second << endl;
	}

	cout << endl;
	cout << mapIntstr[4] << endl;
}

int main(void)
{
	pair<string, string>pairArr[4] = {
		pair<string, string>("9", "Asia"),
		pair<string, string>("4", "Africa"),
		pair<string, string>("1", "Euro"),
		pair<string, string>("4", "America")
	};

	map<string, string> mapIntstr(pairArr, pairArr + 4);
	cout << mapIntstr.size() << endl;

	map<string, string>::iterator it;
	for(it = mapIntstr.begin(); it != mapIntstr.end(); ++it)
	{
		cout << it->first << "-->"
			 << it->second << endl;
	}

	cout << endl;
	cout << mapIntstr["1"] << endl;
	mapIntstr["1"] = "China";
	cout << mapIntstr["1"] << endl;
}
