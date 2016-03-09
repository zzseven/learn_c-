 ///
 /// @file    not1.cc
 /// @author  zzseven
 /// @date    2016-03-09 22:13:15
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5,6};
	vector<int> vecInt(arr, arr + 6);
	std::less<int> lt;

	replace_if(vecInt.begin(), vecInt.end(), not1(bind2nd(lt, 3)), 7);
	for(auto & elem : vecInt)
	{
		cout << elem << " ";
	}

	cout << endl;
}
