// need to think and verify

#include <iostream>
#include <string>
#include <malloc.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
using namespace std;

#define ERROR	0

struct _linkList	//hash�����ṹ��
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
	_linkList* list[350];	//���ݹ�ϣ��ַ��������ʽ��ϣ��  
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

//��ϣ���������ַ������ַ���90ȡģ��ȡģֵΪż����Ȩ��2������ֵ�����Ϊ��ϣ��ַ 
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

			while (head->next != NULL)	//������ϣ������ 
			{
				head = head->next;
				if (strcmp(tempstr, head->strValue) == 0)
				{
					cout<<head->strValue<<" "<<str<<endl;	
                    //���������ַ�����ת�����������ַ�����ȣ������ 
					isRight = true;//��־λ���ַ����Ѵ����˴���־λ�Ĵ���Ҫ�ú�ѧϰһ�£�
					break;
				}
			}
			//���������ַ�����ת�����������ַ�������ȣ����½����뵽������
			if (!isRight)  
			{
				_linkList* newNode = (_linkList*)malloc(sizeof(_linkList));
				newNode->strValue = new char[10];
				strcpy(newNode->strValue, str);
				//֮ǰ��newNode->setValue = str;�������Ǿ͹���һ����ַ���´�ѭ��ʱ������str��ֵ�ͻὫԭ����strValue���ǵ���
				//�ַ����ĸ�ֵһ��Ҫ��strcpy��
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