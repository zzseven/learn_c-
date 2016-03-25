 ///
 /// @file    SocketIO.h
 /// @author  zzseven
 /// @date    2016-03-24 20:56:58
 ///
 
#ifndef _SOCKETIO_H_
#define _SOCKETIO_H_

#include "Noncopyable.h"
#include <unistd.h>

namespace wd
{
class SocketIO : Noncopyable
{
public:	
	SocketIO(int fd);

	ssize_t readn(char * buff, size_t count);
	ssize_t writen(const char * buff, size_t count);
	ssize_t readline(char * buff, size_t max);
private:
	ssize_t readPeek(char * buff, size_t count);
private:
	int _fd;

};


}

#endif
