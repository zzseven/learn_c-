 ///
 /// @file    TextQuery.cc
 /// @author  zzseven
 /// @date    2016-03-08 21:06:24
 ///
 
#include <sstream>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::set;
using std::map;
using std::vector;
using std::stringstream;

typedef vector<string>::size_type line_no;    

class TextQuery
{
public:
	
	TextQuery();
	void read_file(ifstream &is);                  //1.加载文件,建立vector  2.对每一行单词进行拆分,建立map
	set<line_no> & run_query(const string &);      //在map中查找单词,返回该单词行号的set
	string text_line(line_no) const;               //输出文本指定行的字符串

private:
	void stroe_file(ifstream &is);                 //加载文件，建立vector
	void build_map();							   //分析vector中元素，建立map
	vector<string> _lines_of_text;                 //一个元素存储文本中的一行数据     
	map<string, set<line_no> > word_map;
};

TextQuery::TextQuery()
: _lines_of_text(10000)
{
	_lines_of_text.clear();
}

void TextQuery::read_file(ifstream & is)
{
	stroe_file(is);
	build_map();
}

set<line_no> & TextQuery::run_query(const string & str)
{
	map<string, set<line_no>>::iterator found; //map 迭代器
	found = word_map.find(str);                //找str
	if(found != word_map.end())
		return found->second;
	else
	{
		cout << "Can't find "<< str <<" !" << endl;
		exit(0);
	}
}

string TextQuery::text_line(line_no num) const
{	
	return _lines_of_text[num];
}


void TextQuery::stroe_file(ifstream & is)
{
	string line;
	while(getline(is, line))
	{
		_lines_of_text.push_back(line);
	}
}

void TextQuery::build_map()
{
	string word;
	int num = 0;
	set<line_no> sa;
	vector<string>::iterator line;  //vector 迭代器
	map<string, set<line_no> >::iterator found; //map 迭代器

	for(line = _lines_of_text.begin(); line != _lines_of_text.end(); ++ line)
	{
		//一行一行进行处理
		stringstream ss(*line);     //将字符串放入字符流ss
		sa.clear();                 //清空set<line_no> sa
		sa.insert(num);
		while(ss >> word )           //分词 每个单词进行查找
		{
			found = word_map.find(word); //查找key
			if(found != word_map.end())
			{
				found->second.insert(num); //单词存在，set中添加行号
			}else
			{
				word_map.insert(make_pair(word,sa));//不存在，则新建
			}
		}
		++num;
	}
}



int main(int argc, char * argv[])
{
	if(argc != 3)
	{
		cout << "Input error!" << endl;
		return -1;
	}

	ifstream ifs(argv[1]);
	if(!ifs.good())
	{
		cout << "ifstream open error!" << endl;
		return -1;
	}

	TextQuery TQ;
	TQ.read_file(ifs);
	set<line_no> lss;
	lss = TQ.run_query(argv[2]);
	
	cout << endl << argv[2] << " occurs " << lss.size() << " times" << endl;
	std::set<line_no>::iterator it;
	for(it = lss.begin(); it != lss.end(); ++it)
	{
		cout <<"  (line "<< *it + 1 <<") ";
		cout <<	TQ.text_line(*it) << endl;

	}
	return 0;	
}
