 ///
 /// @file    repalce_if.cc
 /// @author  zzseven
 /// @date    2016-03-09 20:44:31
 ///
 
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::bind1st;

int main(void)
{
	int arr[] = {2, 1, 3, 6, 5, 6};
	vector<int> vecInt(arr, arr + 6);
	std::less<int> lt;
	replace_if(vecInt.begin(), vecInt.end(), bind1st(lt, 3), 7);

	for(auto & elem : vecInt)
	{
		cout << elem << " ";
	}

	cout << endl << endl;

	sort(vecInt.begin(), vecInt.end());
	for(auto & elem : vecInt)
	{
		cout << elem << " ";
	}
	cout << endl << endl;
}
