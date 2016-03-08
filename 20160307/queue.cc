 ///
 /// @file    queue.cc
 /// @author  zzseven
 /// @date    2016-03-07 20:05:17
 ///
 
#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::string;

template <typename T, int NUM>
class Queue   //循环队列
{
public:
	Queue()
	: _front(0)
	, _rear(0)
	{
		cout << "Queue()" << endl;
	}

	~Queue()
	{
		cout << "~Queue()" << endl;
	}

	bool empty();

	bool full();

	T get();

	bool dele();

	bool insert(const T & obj);

//	bool display();

private:
	int _front;
	int _rear;
	T _arr[NUM];
};


template <typename T, int NUM>
bool Queue<T, NUM>::empty()
{
	return (_front == _rear ?  1: 0);
}

template <typename T, int NUM>
bool Queue<T, NUM>::full()
{
	return (_rear+1)%NUM == _front;
}

template <typename T, int NUM>
T Queue<T, NUM>::get()
{
	return _arr[_front];
}

template <typename T, int NUM>
bool Queue<T, NUM>::dele()
{
	if(!empty())
	{
		_front = (_front+1)%NUM;
		return true;
	}else
		return false;
}

template <typename T, int NUM>
bool Queue<T, NUM>::insert(const T & obj)
{
	if(!full())
	{
		_arr[_rear] = obj;
		_rear = (_rear + 1)%NUM;
		return true;
	}else
		return false;
}


int main()
{
	Queue<int , 10> que1;
	cout << "que is empty? " << que1.empty() << endl;
	que1.insert(9);
	cout << "que is empty? " << que1.empty() << endl;
	
	for(int idx = 1; idx < 10; ++idx)
	{
		que1.insert(idx);
	}

	cout << "que is full? " << que1.full() << endl;
	
	while(!que1.empty())
	{
		cout << que1.get() << "  ";
		que1.dele();
	}

	cout << endl << endl;

	Queue<string, 12> que2;
	cout << "que is empty? " << que2.empty() << endl;
	que2.insert("hi!");
	cout << "que is empty? " << que2.empty() << endl;
	
	for(int idx = 1; idx < 20; ++idx)
	{
		std::ostringstream oss;
		oss << "idx:" << idx;
		que2.insert(oss.str());
	}

	cout << "que is full? " << que2.full() << endl;
	
	while(!que2.empty())
	{
		cout << que2.get() << endl;
		que2.dele();
	}
	cout << endl << endl;

	for(int idx = 10; idx < 20; ++idx)
	{
		std::ostringstream oss;
		oss << "idx:" << idx;
		que2.insert(oss.str());
	}
	while(!que2.empty())
	{
		cout << que2.get() << endl;
		que2.dele();
	}
	return 0;

}
