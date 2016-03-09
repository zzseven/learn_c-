 ///
 /// @file    istream_iterator.cc
 /// @author  zzseven
 /// @date    2016-03-08 20:31:39
 ///
 
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


int main(void)
{
	vector<int> vecInt;

	std::istream_iterator<int, char> isi(std::cin);

	copy(isi, std::istream_iterator<int, char>(), std::back_inserter(vecInt));

	for(auto & elem : vecInt)
	{
		cout << elem << " ";
	}

	cout << endl << endl;
}
