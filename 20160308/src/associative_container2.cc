 ///
 /// @file    associative_container2.cc
 /// @author  zzseven
 /// @date    2016-03-08 19:03:58
 ///
 
#include <iostream>
#include <set>

using std::cout;
using std::endl;
using std::multiset;

int main(void)
{
	int arr[9] = {1, 2, 3, 4, 5, 6, 3 , 4, 7};
	multiset<int, std::greater<int> > setInt(arr, arr+9);
	cout << setInt.size() << endl;

	multiset<int>::iterator it;
	for(it = setInt.begin(); it != setInt.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	it = setInt.begin();
}
