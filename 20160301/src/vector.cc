 ///
 /// @file    vector.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-01 11:29:48
 ///
 
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;

void printVector(std::vector<int> & vecInt)
{
	cout << "vecInt's size    :" << vecInt.size() << endl;
	cout << "vecInt's capacity:" << vecInt.capacity() << endl;
}

int main(void)
{
	std::vector<int> vecInt;//存储空间是动态增长，每次都是*2
	vecInt.reserve(100);//先开好一个固定数量的空间
	printVector(vecInt);
	vecInt.push_back(1);
	printVector(vecInt);

	vecInt.push_back(2);
	printVector(vecInt);
	vecInt.push_back(3);
	printVector(vecInt);
	vecInt.push_back(4);
	printVector(vecInt);
	vecInt.push_back(5);
	printVector(vecInt);

	std::vector<int>::iterator it = vecInt.begin();
	for(; it != vecInt.end(); ++it)
	{
		cout << *it << endl;
	}
	cout << endl;

	for(int idx = 0; idx != vecInt.size(); ++idx)
	{
		cout << vecInt[idx] << endl;
	}

	//C++11
	for(auto elem : vecInt)
	{
		cout << elem << endl;
	}
}
