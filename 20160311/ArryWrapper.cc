 ///
 /// @file    ArryWrapper.cc
 /// @author  zzseven
 /// @date    2016-03-11 19:38:06
 ///
 
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class MetaData
{
public:
	MetaData(int size, const string & name)
	: _name(name)
	, _size(size)
	{
		cout << "MetaData(int, const string &)"	<< endl;
	}

	MetaData(const MetaData & rhs)
	: _name(rhs._name)
	, _size(rhs._size)
	{
		cout << "MetaData(const MetaData & rhs)" << endl;
	}

	MetaData(MetaData && rhs)
	: _name(std::move(rhs._name))
	//: name(rhs.name)//调用复制构造函数
	, _size(rhs._size)
	{
		cout << "MetaData(MetaData)" << endl;
	}

	string getName()const
	{
		return _name;
	}

	int getsize()const
	{
		return _size;
	}
private:
	string _name;
	int _size;
};

class ArrayWrapper
{
public:
	ArrayWrapper()
	: _pVal(new int [64])
	, _metadata(64, "ArrayWrapper")
	{
		cout << "ArrayWrapper()" << endl;
	}

	ArrayWrapper(int n)
	: _pVal(new int[n])
	, _metadata(n, "ArrayWrapper")
	{
		cout << "ArrayWrapper(int n)" << endl; 	
	}

	ArrayWrapper(const ArrayWrapper & rhs)
	: _pVal(new int [rhs._metadata.getsize()])
	, _metadata(rhs._metadata)
	{
		cout << "ArrayWrapper(const ArrayWrapper & rhs)" << endl;
		for(int idx = 0; idx != rhs._metadata.getsize(); ++idx)
		{
			_pVal[idx] = rhs._pVal[idx];
		}
	}

	ArrayWrapper(ArrayWrapper && rhs)
	: _pVal(rhs._pVal)
	, _metadata(std::move(rhs._metadata))
	{
		cout << "ArrayWrapper(ArrayWrapper && rhs)" << endl;
		rhs._pVal = NULL;
	}

private:
	int * _pVal;
	MetaData _metadata;
};


int main(void)
{
	ArrayWrapper aw1;
	ArrayWrapper aw2(128);
	ArrayWrapper aw3(std::move(aw2));
}
