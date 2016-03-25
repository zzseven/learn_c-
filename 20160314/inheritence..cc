 ///
 /// @file    inheritence..cc
 /// @author  zzseven
 /// @date    2016-03-14 21:13:35
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Eye
{
public:
	void lookx()
	{
		cout << "eye.look()" << endl;
	}
};

class Nose
{
public:
	void smellx()
	{
		cout << "nose.smell()" << endl;
	}
};

class Mouth
{
public:
	void eatx()
	{
		cout << "mouth.eat()" << endl;
	}

};

class Ear
{
public:
	void listenx()
	{
		cout << "ear.listen()" << endl;
	}
};

class Head
: public Eye
, public Nose
, public Mouth
, public Ear
{
public:
	void look()
	{
		lookx();
	}

	void smell()
	{
		smellx();
	}

	void eat()
	{
		eatx();
	}

	void listen()
	{
		listenx();
	}

};


int main(void)
{
	Head head;
	head.look();
	head.smell();
	head.eat();
	head.listen();

	return 0;
}
