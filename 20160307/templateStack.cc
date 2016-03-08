 ///
 /// @file    templateStack.cc
 /// @author  zzseven
 /// @date    2016-03-07 19:30:03
 ///
 
#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::string;

//类模板可以设置默认的模板参数

template <typename T, int NUM = 10>
class Stack
{
public:
	Stack()
	: _top(-1)
	{
		cout << "Stack(int)" << endl;
	}

	~Stack()
	{
		cout << "~Stack()" << endl;
	}

	bool empty();

	bool full();

	T top();

	bool push(const T & obj);

	bool pop();

private:
	int _top;
	T _arr[NUM];
};


template <typename T, int NUM>
bool Stack<T, NUM>::empty()
{
	return _top == -1;
}

template <typename T, int NUM>
bool Stack<T, NUM>::full()
{
	return _top == (NUM -1);
}

template <typename T, int NUM>
T Stack<T, NUM>::top()
{
	return _arr[_top];
}

template <typename T, int NUM>
bool Stack<T, NUM>::push(const T & obj)
{
	if(!full())
	{
		_arr[++_top] = obj;
		return true;
	}else
		return false;
}

template <typename T, int NUM>
bool Stack<T, NUM>::pop()
{
	if(!empty())
	{
		--_top;
		return true;
	}else
		return false;
}

int main(void)
{
#if 0
	Stack<string> st;

	cout << "st is empty?  " << st.empty() << endl;
	st.push("hello");
	cout << "st is empty?  " << st.empty() << endl;

	for(int idx = 1; idx < 10; ++idx)
	{
		std::ostringstream oss;
		oss << "idx:" << idx;
		st.push(oss.str());
	}

	cout << "st is full?   " << st.full() << endl;

	while(!st.empty())
	{
		cout << st.top() << endl;;
		st.pop();
	}
	cout << endl;
#endif
	//return 0;

	Stack<int, 15> st;
	cout << "st is empty?  " << st.empty() << endl;
	st.push(6);
	cout << "st is empty?  " << st.empty() << endl;

	for(int idx = 1; idx < 20; ++idx)
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
