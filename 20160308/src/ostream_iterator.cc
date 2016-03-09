 ///
 /// @file    ostream_iterator.cc
 /// @author  zzseven
 /// @date    2016-03-08 20:27:40
 ///
 
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(void)
{
	int arr[6] = {1, 2, 3, 4, 5 , 6};
	vector<int> vecInt(arr, arr + 6);

	std::ostream_iterator<int, char> osi(cout, " ");
	std::copy(vecInt.begin(), vecInt.end(), osi);

	cout << endl;
	return 0;
}
