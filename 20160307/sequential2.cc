 ///
 /// @file    sequential2.cc
 /// @author  zzseven
 /// @date    2016-03-09 19:21:38
 ///
 
#include <iostream>
#include <vector>
#include <list>
#include <deque>

using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::deque;

void display(vector<int> & vecInt)
{
	vector<int>::iterator it;
	for(it = vecInt.begin(); it != vecInt.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}


int main(void)
{
	vector<int> vecInt(5, 0);
	vector<int>::iterator it = vecInt.end();
	it = vecInt.insert(it, 1);
	display(vecInt);

	vecInt.insert(it, 2, 3);
	display(vecInt);

	it = vecInt.begin();
	int arr[3] = {7, 8, 9};
	vecInt.insert(it, arr, arr + 3);
	display(vecInt);

	return 0;
}
