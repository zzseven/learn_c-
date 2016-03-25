 ///
 /// @file    Noncopyable.h
 /// @author  zzseven
 /// @date    2016-03-20 13:31:04
 ///
 
#ifndef _MY_NONCOPYABLE_H_
#define _MY_NONCOPYABLE_H_

namespace wd
{

class Noncopyable
{
protected:
	Noncopyable(){}

private:
	Noncopyable(const Noncopyable & rhs);
	Noncopyable & operator=(const Noncopyable &rhs);
};

}

#endif
