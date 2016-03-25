总结：

这个小程序总共涉及到3个类：Timer, TimerThread, Thread

TimerThread 使用了Timer, Thread

Thread::run是Timer的start方法，也就是说吧Timer的start函数设为线程的运行函数,达到一个线程定时器的效果
TimerThread的start方法则调用Thread的start方法
TimerThread的stop方法则调用Timer的stop方法

比较巧妙的实现了这个定时器。
