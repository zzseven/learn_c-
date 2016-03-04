 ///
 /// @file    io2.cc
 /// @author  zzseven
 /// @date    2016-3-2 11:41:17
 ///
 
#include <fstream>
#include <vector>
#include <iostream>
#include <string>


using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::vector;

int main(void)
{
	ifstream ifs("io1.cc");
	if(!ifs.good())
	{
		cout << "ifstream open error!" << endl;
	}
	
	//string s;
#if 0
	while(ifs >> s)  //默认用空格分开
	{
		cout << s << endl;
	}
#endif

	vector<string> vec_str;
	string line;
	while(getline(ifs, line)) //按行分割
	{
		//cout << line << endl;
		vec_str.push_back(line);
	}

	vector<string>::iterator sit = vec_str.begin();
	for(; sit != vec_str.end(); ++ sit) //vec_str.end()末端的后一个
	{
		cout << *sit << endl;
	}
	ifs.close();


	return 0;
}
