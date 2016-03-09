 ///
 /// @file    men_fn.cc
 /// @author  zzseven
 /// @date    2016-03-09 22:16:50
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::cout;
using std::endl;
using std::vector;

class NumVal
{
public:
	NumVal()
	: _val(0)
	{}

	NumVal(int val)
	: _val(val)
	{}

	bool display()
	{
		cout << _val << " ";
		return true;
	}

	bool isEven()
	{
		return (bool) !(_val % 2);
	}
	
	bool isPrime()
	{
		for(int idx = 2; idx <= (_val/2); ++idx)
		{
			if(!(_val % idx))
				return false;
		}
		return true;
	}
private:
	int _val;
};

int main(void)
{
	vector<NumVal> vecNum(13);
	for(int idx = 0; idx != 13; ++idx)
	{
		vecNum[idx] = NumVal(idx + 1);
	}

	cout << "vecNum中的原始值为" << endl;
	std::for_each(vecNum.begin(), vecNum.end(), std::mem_fn(&NumVal::display));
	cout << endl << endl;

	auto it = remove_if(vecNum.begin(), vecNum.end(), std::mem_fn(&NumVal::isPrime));
	std::for_each(vecNum.begin(), it, std::mem_fn(&NumVal::display));


	return 0;

}
