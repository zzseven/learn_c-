 ///
 /// @file    Safefile.cc
 /// @author  zzseven
 /// @date    2016-03-11 21:03:29
 ///

#include <stdio.h>
#include <iostream>


using std::cout;
using std::endl;

class SafeFile
{
public:
	SafeFile(const char * filename)
	: _fileHandler(fopen(filename, "w+"))
	{
		cout << "SafeFile(const char *)" << endl;
		if(_fileHandler == NULL)
		{
			cout << "fileopen error!" << endl;
			return;
		}
	}

	void write(const char * str)
	{
		if(fputs(str, _fileHandler)==EOF)
		{
			cout << "to the file end" << endl;
			return;
		}
	}
	
	~SafeFile()
	{
		cout << "~SafeFile()" << endl;
		if(_fileHandler)
		{
			fclose(_fileHandler);
		}
	}
private:
	SafeFile(const SafeFile & rhs);
	SafeFile & operator=(const SafeFile & rhs);
private:
	FILE * _fileHandler;
};


int main(void)
{
	SafeFile sf("foo.test");
	sf.write("Hello RAII\n");
	return 0;
}
