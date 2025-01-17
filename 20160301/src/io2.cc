 ///
 /// @file    io2.cc
 /// @author  zzseven
 /// @date    2016-03-01 21:08:26
 ///
 
#include <fstream>
#include <iostream>
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
	}
	
	string s;
#if 0
	while(ifs >> s)  //默认用空格分开
	{
		cout << s << endl;
	}
#endif

	while(getline(ifs, s)) //按行分割
	{
		cout << s << endl;
	}
	//cout << "execute" << endl;

	return 0;
}
