 ///
 /// @file    stack.cc
 /// @author  zzseven
 /// @date    2016-03-09 20:55:59
 ///
 
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::stack;
using std::vector;
using std::string;

int main(void)
{
	stack<int, vector<int> > stackInt;
	for(int idx = 0; idx != 20; ++idx)
	{
		stackInt.push(idx);
	}

	cout << stackInt.size() << endl;

	while(stackInt.size())
	{
		int x = stackInt.top();
		cout << x << " ";
		stackInt.pop();
	}
	cout << endl;

	stack<string, vector<string> > stackStr;
	for(char c = 'A'; c <= 'Z'; ++c)
	{
		string s(2, c);
		stackStr.push(s);
	}
	while(stackStr.size())
	{
		cout << stackStr.top() << endl;
		stackStr.pop();
	}

	cout << endl;
}
