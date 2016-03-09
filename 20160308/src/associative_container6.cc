 ///
 /// @file    associative_container6.cc
 /// @author  zzseven
 /// @date    2016-03-08 20:08:05
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
	pair<int, string> pairArr[4] = {
		pair<int, string>(4, "G"),
		pair<int, string>(3, "J"),
		pair<int, string>(5, "A"),
		pair<int, string>(7, "S")
	};

	pair<int, string> pairArr2[4] = {
		pair<int, string>(1, "B"),
		pair<int, string>(3, "Y"),
		pair<int, string>(7, "Q"),
		pair<int, string>(6, "S")
	};

	map<int, string> mapIntstr(pairArr, pairArr + 4);
	mapIntstr.insert(pairArr2, pairArr2+4);

	map<int, string>::iterator mit;
	for(mit = mapIntstr.begin(); mit != mapIntstr.end(); ++mit)
	{
		cout << (*mit).first << "--->"
			 << (*mit).second << endl;
	}

	cout << endl << endl;

	multimap<int, string> mmapIntstr(pairArr, pairArr + 4);
	mmapIntstr.insert(pairArr2, pairArr2 + 4);


	multimap<int, string>::iterator mit1;
	for(mit1 = mmapIntstr.begin(); mit1 != mmapIntstr.end(); ++mit1)
	{
		cout << (*mit1).first << "-->"
			 << (*mit1).second << endl;
	}
}
