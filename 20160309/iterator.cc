 ///
 /// @file    iterator.cc
 /// @author  zzseven
 /// @date    2016-03-09 21:40:30
 ///
 
#include <iostream>
#include <iterator>
#include <vector>
#include <list>

using std::cout;
using std::endl;
using std::vector;
using std::list;

template <typename container>
void printElements(container c)
{
	typename container::const_iterator cit = c.begin();
	for(; cit != c.end(); ++cit)
	{
		cout << *cit << " ";
	}
	cout << endl;
}

int main(void)
{
	vector<int> vecSrc;
	list<int> listDest;
	for(int idx = 0; idx != 3; ++idx)
	{
		vecSrc.push_back(idx);
	}

	copy(vecSrc.begin(), vecSrc.end(), std::back_insert_iterator<list<int> >(listDest));
	printElements(listDest);
}
