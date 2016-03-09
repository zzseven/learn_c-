 ///
 /// @file    sort.cc
 /// @author  zzseven
 /// @date    2016-03-09 20:50:55
 ///
 
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

int main(void)
{
	int arr[10] = {2, 4, 6, 7, 9, 3, 10, 1, 8, 0};
	vector<int> vecInt(arr, arr + 10);

	for(auto & elem : vecInt)
	{
		cout << elem << " ";
	}
	cout << endl;

	sort(vecInt.begin(), vecInt.end());
	for(auto & elem : vecInt)
	{
		cout << elem << " ";
	}

	cout << endl;
}
