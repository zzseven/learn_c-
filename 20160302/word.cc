 ///
 /// @file    word.cc
 /// @author  zzseven
 /// @date    2016-03-02 19:35:02
 ///

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::string;



typedef struct wordnode   //单词节点
{
	long count;           //该单词数目
	string wd;            //单词     //这个分配内存我懵逼了
}word;

typedef struct node       //单词链表节点
{
	char head;            //首字母用于检索
	word c;               //单词结构体
	struct node * next;   //下一个字母节点
	struct node * right;  //以当前首字母的下一个单词节点
}word_node;

typedef word_node * wordlist;

class WordStatic
{
public:
	int  _word_count;      //单词总数目
	WordStatic();
    void read_file(string filename);
    void write_file(string filename);
	void destroy();
private:
	wordlist _wlist;       //链表指针
	//int  _line_count;    //总行数
	void creatlist();      //初始化链表
};

WordStatic::WordStatic()                     //构造函数，并初始化
: _word_count(0)
{
	creatlist();
}

void WordStatic::read_file(string filename)  //读文件并进行处理
{
	ifstream ifs(filename.c_str());          //打开文件并判断是否出错
	if(!ifs.good())
	{
		cout << "ifstream open error!" << endl;
	}

	string str;
	wordlist head, p, pr, ppre, node;
	head=_wlist;
	int ret;
	while(ifs >> str)                        //这里开始可以便利每个单词
	{
		p = head->next;
		while(p)                             //对首字母遍历，找到子链表
		{
			if(str[0] == p->head)
			{
				ppre = p;
				pr = p->right;
				while(pr)
				{
					ret = str.compare((pr->c).wd);
					if(ret == 0)
					{
						(pr->c).count++;
						break;               //找到该单词，计数+1
					}else if(ret < 0)
					{
						node = (wordlist)malloc(sizeof(word_node));
						node->head = str[0];
						node->next = NULL;
						(node->c).count = 1;
						(node->c).wd = str;      //将该单词放到链表结点中
						ppre->right = node;
						node->right = pr;
						++ _word_count;
						break;
					}else
					{
						ppre = pr;
						pr = pr->right;
					}
				}

				if(pr==NULL)
				{
					node = (wordlist)malloc(sizeof(word_node));
					node->head = str[0];
					node->next = NULL;
					node->right = NULL;
					(node->c).count = 1;
					(node->c).wd = str;      //将该单词放到链表结点中
					ppre->right = node;
					node ->right = pr;
					++ _word_count;
				}
				break;
			}else
			{
				p = p->next;                     //跳到下一个首字母结点
			}
#if 0
				while(pr)                    //在子链中判断单词是否已经存在
				{
					if(!str.compare((pr->c).wd))
					{
						flag = 0;
						(pr->c).count++;
						break;               //找到该单词，计数+1
					}
					ppre = pr;
					pr = pr->right;
				}
				if(flag)                     //单词不存在，创建单词结点
				{
					node = (wordlist)malloc(sizeof(word_node));
					node->head = str[0];
					node->next = NULL;
					node->right = NULL;
					(node->c).count = 1;
					(node->c).wd = str;      //将该单词放到链表结点中
											 //将node结点插入到子链表节点中
					ppre = p;
					pr = ppre->right;
					while(pr && (((node->c).wd).compare((pr->c).wd) > 0))
					{
						ppre = pr;
						pr = pr->right;
					}
					ppre->right = node;
					node->right = pr;
					++_word_count;           //单词数+1
				}
#endif 
		}
	}
	cout << "read_file done!" << endl;
}
void WordStatic::write_file(string filename) //将处理结果写到文件中
{
	ofstream ofs(filename.c_str());
	wordlist p, pr;
	p = _wlist->next;

	while(p)                                 //依次遍历链表的结点并写到文件中
	{	
		if(p->right != NULL)
		{
			pr = p->right;
			while(pr)
			{
				ofs << (pr->c).wd << "  " << (pr->c).count << endl;
				pr = pr->right;
			}
		}
		p = p->next;
	}
	cout << "write_file done!" << endl;
}
void WordStatic::destroy()
{
	wordlist p, pre, pr, ppr;
	pre = _wlist->next;
	p = pre->next;
	while(p)                                 //依次遍历链表的结点释放内存
	{	
		free(pre);
		if(p->right != NULL)
		{
			pr = p->right;
			ppr = pr ->right;
			while(ppr)
			{
				free(pr);
				pr = ppr;
				ppr = ppr ->right;
			}
			free(pr);
		}
		pre = p;
		p = p->next;
	}
	free(pre);
	cout << "destroy memory done!" << endl;
}

void WordStatic::creatlist()                 //建立26个字母首节点
{
	wordlist head, p, pre;
	head = p = (wordlist)malloc(sizeof(word_node));
	char ch = 'a';
	for(int i = 0; i<26; ++i)
	{
		pre = (wordlist)malloc(sizeof(word_node));
		pre->head = ch;
		pre->next = NULL;
		pre->right = NULL;
		p->next = pre;
		p = pre;
		++ch;
	}
	_wlist = head;
}


int main(int argc, char * argv[])
{
	if(argc != 2)
	{
		cout << "Input error!" << endl;
	}
	WordStatic ws;
	//创建对象，运行函数，结束释放内存
	string filename = argv[1];
	ws.read_file(filename);
	ws.write_file("Word_count.txt");
	ws.destroy();
	cout << "总共：" <<ws._word_count << "个单词" << endl;
}

