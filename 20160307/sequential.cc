 ///
 /// @file    sequential.cc
 /// @author  zzseven
 /// @date    2016-03-09 19:10:21
 ///
 
#include <iostream>
#include <vector>
#include <list>
#include <deque>

using std::cout;
using std::endl;
using std::list;
using std::deque;

int main(void)
{
	double darr[5] = {1, 2, 3, 4, 5};
	deque<double> doubleDeque(darr, darr + 5);
	//迭代器的范围是一个 左闭右开区间[)
	
	for(int idx = 0; idx != doubleDeque.size(); ++idx)
	{
		cout << doubleDeque[idx] << " "; //随机访问迭代器
	}

	cout << endl << endl;

	deque<double>::iterator it;
	for(it = doubleDeque.begin(); it != doubleDeque.end(); ++it)
	{
		cout << *it << " "; //双向访问迭代器
	}
	cout << endl << endl;

	list<float> first(3, 5);
	list<float>::iterator lit;
	for(lit = first.begin(); lit != first.end(); ++lit)
	{
	//	(*lit) += 2;
		cout << *lit << " ";
	}

	cout << endl;

	list<float> second(4, 9);
	second.swap(first);

	for(lit = first.begin(); lit != first.end(); ++lit)
	{
		cout << *lit << " ";
	}
	cout << endl << endl;

	return 0;
	
}
