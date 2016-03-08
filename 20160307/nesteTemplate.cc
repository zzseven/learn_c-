 ///
 /// @file    nesteTemplate.cc
 /// @author  zzseven
 /// @date    2016-03-07 22:18:20
 ///
 
#include <iostream>

template <typename T1>
class Test
{
public:
	template <class T2>
	T1 func(T2 b);
};

template <typename T1>
template <typename T2>
T1 Test<T1>::func(T2 b)
{
	return T1(b);
}


int main(void)
{
	Test<int> test;
	std::cout << test.func(3.14f) << std::endl;
	return 0;
}
