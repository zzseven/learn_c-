 ///
 /// @file    vector.cc
 /// @author  zzseven
 /// @date    2016-03-01 21:17:23
 ///
 
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;


void printVector(std::vector<int> & vecInt)
{
	cout << "vecInt's size  : " << vecInt.size() << endl;
	cout << "vecInt's capacity: " << vecInt.capacity() << endl;
}

int main(void)
{
	std::vector<int> vecInt;//存储空间是动态增长，每次都是*2
	vecInt.reserve(100); //先开好一定固定数量的空间
	printVector(vecInt);

	vecInt.push_back(1);
	printVector(vecInt);

	vecInt.push_back(2);
	printVector(vecInt);

	vecInt.push_back(3);
	printVector(vecInt);

	vecInt.push_back(4);
	printVector(vecInt);

	std::vector<int>::iterator it = vecInt.begin();
	for(; it!= vecInt.end(); ++it)
	{
		cout << *it << endl;
	}

	for(int idx = 0; idx != vecInt.size(); ++idx)
	{
		cout << vecInt[idx] << endl;
	}
	//c++11的方式
	for(auto elem: vecInt)
	{
		cout << elem << endl;
	}
}
