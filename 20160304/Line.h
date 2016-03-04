 ///
 /// @file    line.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-04 15:25:35
 ///
 
#ifndef __LINE_H__
#define __LINE_H__

class Line
{
class LineImpl;
public:
	Line(int, int, int, int);
	~Line();
	void printLine();
private:
	LineImpl * _pImp;
};

#endif
