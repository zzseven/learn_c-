 ///
 /// @file    WordStatic.cc
 /// @author  zzseven
 /// @date    2016-03-03 21:45:44
 ///
 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;

struct Record
{
	string word;
	int freq;
};

bool recordCompare(const Record & lhs, const Record & rhs)
{
	if(lhs.word < rhs.word)
		return true;
	else
		return false;
}

class WordStatic
{
public:
	WordStatic();
	
	void readFile(const string & filename);
	void writeFile(const string & filename);
private:
	vector<Record> _dict;
};

WordStatic::WordStatic()
{
	_dict.reserve(10000); //预申请空间
}

void WordStatic::readFile(const string & filename)
{
	ifstream ifs(filename.c_str());
	if(!ifs.good())
	{
		cout << "ifstream open error!" << endl;
		return ;
	}

	string word;
	while(ifs >> word)
	{
		vector<Record>::iterator it;
		for(it = _dict.begin(); it != _dict.end(); ++it)
		{
			if(it->word == word)
			{
				++(it->freq);
				break;
			}
		}

		if(it == _dict.end())
		{
			Record record;
			record.word = word;
			record.freq = 1;
			_dict.push_back(record);
		}
	}

	ifs.close();

	std::sort(_dict.begin(), _dict.end(), recordCompare);
}

void WordStatic::writeFile(const string & filename)
{
	ofstream ofs(filename.c_str());
	if(!ofs.good())
	{
		cout << "ofstream open error!" << endl;
		return ;
	}

	for(auto & elem : _dict)
	{
		ofs << elem.word << "  " << elem.freq << endl;
	}
}


int main(void)
{
	WordStatic ws;
	ws.readFile("The_Holy_Bible.txt");
	ws.writeFile("dict.dat");
}


