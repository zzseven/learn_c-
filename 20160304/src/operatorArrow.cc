 ///
 /// @file    operatorArrow.cc
 /// @author  zzseven
 /// @date    2016-03-04 23:26:25
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Data
{
public:
	int getlen()
	{
		return 5;
	}

};

class DataPtr
{
public:
	DataPtr()
	: _pData(new Data)
	{
		cout << "DataPtr()" << endl;
	}

	~DataPtr()
	{
		cout << "~DataPtr()" << endl;
		delete _pData;
	}

	Data * operator->()
	{
		cout << "operator->()" << endl;
		return _pData;
	}
private:
	Data * _pData;
};


int main(void)
{
	DataPtr dp;
	cout << dp->getlen() << endl;
	cout << (dp.operator->())->getlen() << endl;
	
	return 0;
}
