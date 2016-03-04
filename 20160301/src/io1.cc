 ///
 /// @file    io1.cc
 /// @author  zzseven
 /// @date    2016-03-01 20:47:37
 ///

#include <limits>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

void printCin()
{
	cout << "bad = " << cin.bad() << endl;
	cout << "fail = " << cin.fail() << endl;
	cout << "eof = " << cin.eof() << endl;
	cout << "good = " << cin.good() << endl;
}

int test(void)
{
	printCin();

	int inum;
	while(cin >> inum)
	{
		cout << inum << endl;
	}
	printCin();
	cin.clear();
	cout << "重置流的状态" << endl;
	
	printCin();

//	cin.ignore(1024,'\n');//清空缓冲区(最多跳过1024个字节，如果在之前遇到'\n'，则前面的不要了，从'\n'后读取数据。
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
	std::string s;
	cin >> s; //标准输入流有个缓冲区.
	cout << s << endl;

	return 0;
}

int main(void)
{
	int ival;
	while(cin >> ival, !cin.eof())
	{
		if(cin.bad())
		{
			cout << "IO stream corrupted!" << endl;
			return -1;
		}
		else if(cin.fail())
		{
			cout << "data illegal, please try again!" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
			continue;
		}
		cout << "ival = " << ival << endl;
	}

	return 0;

}
