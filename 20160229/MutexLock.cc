 ///
 /// @file    MutexLock.cc
 /// @author  zzseven
 /// @date    2016-02-29 20:19:44
 ///
 
#include <iostream>
#include <pthread.h>
#include <unistd.h>

using std::cout;
using std::endl;

class MutexLock
{
public:
	MutexLock();
	~MutexLock();
	
	void lock();
	void unlock();
	pthread_mutex_t*  getlock()       //获得锁变量,为pthread_cond_wait(pthread_cond_t *, pthread_mutex_t *);传参
	{
		return &_lock;
	}
private:
	//...补充数据成员
	pthread_mutex_t _lock;
};

MutexLock::MutexLock()
{
	pthread_mutex_init(&_lock, NULL); //琐的初始化
}
MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&_lock);    //琐的销毁
}
	
void MutexLock::lock()
{
	pthread_mutex_lock(&_lock);       //加锁
}
void MutexLock::unlock()
{
	pthread_mutex_unlock(&_lock);     //解锁
}

class Condition
{
public:
	Condition();
	~Condition();

	void wait(MutexLock * mutex);
	void signal();
private:
	pthread_cond_t _cond;
};

Condition::Condition()              //构造
{
	pthread_cond_init(&_cond, NULL);//条件变量初始化
}
Condition::~Condition()
{
	pthread_cond_destroy(&_cond);   //条件变量销毁
}

void Condition::wait(MutexLock * mutex)
{
	pthread_cond_wait(&_cond, mutex->getlock()); //获取资源
}
void Condition::signal()
{
	pthread_cond_signal(&_cond);    //释放资源
}



