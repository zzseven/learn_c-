 ///
 /// @file    io2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-01 11:23:15
 ///
 
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;

int main(void)
{
	ifstream ifs("io1.cc");
	if(!ifs.good())
	{
		cout << "ifstream open error!" << endl;
		return -1;
	}

	
	string s;
#if 0
	while(ifs >> s)
	{
		cout << s << endl;
	}
#endif
	while(getline(ifs, s))
	{
		cout << s << endl;
	}

	//cout << "execute" << endl;
	return 0;
}



