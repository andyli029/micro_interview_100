// need to think and verify

#include <iostream>
#include <string>
#include <malloc.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
using namespace std;

#define ERROR	0

struct _linkList	//hash拉链结构。
{
	char* strValue;
	_linkList* next;
};

void reverse(char* str, int len)
{
	int start, end;
	start = 0;
	end = len - 1;
	while(start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

class CHash
{
	_linkList* list[350];	//根据哈希地址构造拉链式哈希表  
public:
	CHash();
	~CHash();
	int HashFunc(char* str);
	void InitHash();
};

CHash::CHash()
{
	int i;
	for (i = 0; i < 350; i++)
	{
		list[i] = (_linkList*)malloc(sizeof(_linkList));
		if (!list[i])
		{
			exit(ERROR);
		}
		list[i]->next = NULL;
	//	list[i]->strValue = new char[10];
	}
}

CHash::~CHash()
{
	int i;
	for (i = 0; i < 350; i++)
	{
	//	free(list[i]->strValue);
		free(list[i]);
	}
}

//哈希函数，将字符串各字符对90取模，取模值为偶数乘权重2，将各值相加作为哈希地址 
int CHash::HashFunc(char str[])	
{
	char* p = str;
	int sum = 0;
	while(*p != '\0')
	{
		int mod = (int)(*p)%90;
		if (mod % 2 == 0)
		{
			mod *= 2;
		}
		sum += mod;
		p++;
	}

	sum = sum % 350;
	return sum;
}


void CHash::InitHash()
{
	ifstream fin;
	ofstream fout;
	char str[1000];
	char tempstr[1000];
	fin.open("data.txt");
	
	if (fin.is_open())
	{
		while (fin >> str)
		{
			int addr = HashFunc(str);

			bool isRight = false;
			_linkList *head;
			head = list[addr];

			strcpy(tempstr, str);
			reverse(tempstr, strlen(tempstr));

			while (head->next != NULL)	//遍历哈希表拉链 
			{
				head = head->next;
				if (strcmp(tempstr, head->strValue) == 0)
				{
					cout<<head->strValue<<" "<<str<<endl;	
                    //如果读入的字符串反转后与链表中字符串相等，则输出 
					isRight = true;//标志位，字符串已处理。此处标志位的处理要好好学习一下！
					break;
				}
			}
			//如果读入的字符串反转后与链表中字符串不相等，则将新结点插入到链表中
			if (!isRight)  
			{
				_linkList* newNode = (_linkList*)malloc(sizeof(_linkList));
				newNode->strValue = new char[10];
				strcpy(newNode->strValue, str);
				//之前用newNode->setValue = str;这样它们就共用一个地址，下次循环时，传入str的值就会将原来的strValue覆盖掉。
				//字符串的赋值一般要用strcpy！
				newNode->next = NULL;
				head->next = newNode;
				//head = newNode;
			}
		}
	}
	fin.clear();
	fin.close();
}

int main()
{
	CHash CH = CHash();
	CH.InitHash();

	return 0;
}