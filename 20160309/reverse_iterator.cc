 ///
 /// @file    reverse_iterator.cc
 /// @author  zzseven
 /// @date    2016-03-09 21:34:06
 ///
 
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(void)
{
	int arr[5] = {1, 2, 3, 4, 5};
	vector<int> vecInt(arr, arr + 5);
	vector<int>::reverse_iterator rit;
	for(rit = vecInt.rbegin(); rit != vecInt.rend(); ++rit)
	{
		cout << *rit << " ";
	}
	
	cout << endl;	
	cout << endl;
}
