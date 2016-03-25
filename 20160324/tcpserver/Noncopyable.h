 ///
 /// @file    Noncopyable.h
 /// @author  zzseven
 /// @date    2016-03-24 20:52:21
 ///
 
#ifndef _NONCOPYABLE_H_
#define _NONCOPYABLE_H_

namespace wd
{
class Noncopyable
{
protected:
	Noncopyable(){}

private:
	Noncopyable(const Noncopyable & rhs);
	Noncopyable & operator=(const Noncopyable & rhs);

};


}//end of namespace wd

#endif
