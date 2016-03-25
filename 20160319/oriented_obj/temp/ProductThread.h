 ///
 /// @file    ProductThread.h
 /// @author  zzseven
 /// @date    2016-03-21 17:13:46
 ///
 
#ifndef __MY_PRODUCTTHREAD_H_
#define __MY_PRODUCTTHREAD_H_
#include "Thread.h"

namespace wd
{
class Buffer;

class ProductThread : public Thread
{
public:
	ProductThread(Buffer & buff);
	void run();
private:
	Buffer & _buff;
};


}// end of namespace wd

#endif
