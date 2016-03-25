 ///
 /// @file    Noncopyable.h
 /// @author  zzseven
 /// @date    2016-03-22 19:55:59
 ///
 
#ifndef __NONCOPYABLE_H_
#define __NONCOPYABLE_H_

namespace wd
{
class Noncopyable
{
protected:
	Noncopyable(){}
private:
	Noncopyable(const Noncopyable &rhs);
	Noncopyable & operator =(const Noncopyable &rhs);
};


}//end of namespace wd


#endif
