 ///
 /// @file    test.cc
 /// @author  zzseven
 /// @date    2016-03-02 20:22:39
 ///
 
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


int main(void)
{
	string s = "abc";
	string s1 = "acd";
	string s2 = "abcd";
	cout << s << endl;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s[0] << endl;
	if(s[0] == '1')
		cout << "fsdfsdf" << endl;

	cout << s.compare(s1) <<endl;
	cout << s.compare(s2) <<endl;
	cout << s1.compare(s) <<endl;
	cout << s1.compare(s2) <<endl;
}
