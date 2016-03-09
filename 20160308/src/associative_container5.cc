 ///
 /// @file    associative_container5.cc
 /// @author  zzseven
 /// @date    2016-03-08 19:45:01
 ///
 
#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::map;
using std::multimap;
using std::string;
using std::pair;

int main(void)
{
	pair<int, string> pairArr[2] = {
		pair<int, string>(1, "A"),
		pair<int, string>(2, "B")
	};

	map<int, string>mapIntstr(pairArr, pairArr+2);

	pair<int, string>t(2, "X");
	map<int, string>::iterator mit = mapIntstr.begin();

	pair<map<int, string>::iterator, bool>   //这个用法有点奇怪那
		pairRet = mapIntstr.insert(t);

	//cout << pairRet.first << endl;

	if(pairRet.second)
	{
		cout << "Data insert success" << endl;
		cout << pairRet.first->first  << "--->"
			 << pairRet.first->second << endl;
	}
	else
	{
		cout << "map exists the same key: " 
			 << pairRet.first->first << "-->"
			 << pairRet.first->second << endl;
	}

	cout << endl;

	multimap<int, string> mmapInstr(pairArr, pairArr+2);
	multimap<int , string>::iterator mmit;
	mmit = mmapInstr.insert(t);
	cout << mmit->first << "-->"
		 << mmit->second << endl;


}
