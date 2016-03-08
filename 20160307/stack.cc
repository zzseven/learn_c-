 ///
 /// @file    stack.cc
 /// @author  zzseven
 /// @date    2016-03-07 19:14:27
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Stack
{
public:
	Stack(int size)
	: _top(-1)
	, _size(size)
	, _arr(new int[_size])
	{
		cout << "Stack(int)" << endl;
	}

	~Stack()
	{
		cout << "~Stack" << endl;
		delete [] _arr;
	}

	bool empty()
	{
		return _top == -1;
	}

	bool full()
	{
		return _top == (_size -1);
	}
	
	int top()
	{
		return _arr[_top];
	}

	bool push(const int & num)
	{
		if(!full())
		{
			_arr[++_top] = num;
			return true;
		}
		else
			return false;
	}

	bool pop()
	{
		if(empty())
		{
			return false;
		}else
		{
			--_top;
			return true;
		}
	}
private:
	int _top;
	int _size;
	int * _arr;
};

int main(void)
{
	Stack st(10);
	cout << "st is empty?  " << st.empty() << endl;
	st.push(5);
	cout << "st is empty?  " << st.empty() << endl;

	for(int idx = 0; idx < 10; ++idx)
	{
		st.push(idx);
	}

	cout << "st is full?   " << st.full() << endl;

	while(!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;

	return 0;
}




