 ///
 /// @file    ConsumerThread.h
 /// @author  zzseven
 /// @date    2016-03-21 16:59:28
 ///
 
#ifndef __MY_CONSUMERTHREAD_H_
#define __MY_CONSUMERTHREAD_H_
#include "Thread.h"

namespace wd
{
class Buffer;
class ConsumerThread : public Thread
{
public:
	ConsumerThread(Buffer & buff);
	void run();
private:
	Buffer & _buff;

};


}// end of namespace wd

#endif
