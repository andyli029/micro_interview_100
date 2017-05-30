#include<iostream>
#include<string>
#include <string.h>
using namespace std;

//�������� �� ��һ���ַ���ĳ���������ַ���ȫ����
//�������� �� pStrΪ�ַ�����begin��end��ʾ����
//����ֵ ��   ��
void Permutation_Solution1(char *pStr, int begin, int end)
{
	if(begin == end - 1) //ֻʣһ��Ԫ��
	{
		for(int i = 0; i < end; i++) //��ӡ
			cout << pStr[i];
		cout << endl;
	}
	else
	{
		for(int k = begin; k < end; k++)
		{
			swap(pStr[k], pStr[begin]); //���������ַ�
			Permutation_Solution1(pStr, begin + 1, end);
			swap(pStr[k], pStr[begin]);  //�ָ�
		}
	}
}

//�������� �� ��һ���ַ���ĳ���������ַ���ȫ����
//�������� �� pStrΪ�ַ�����pBeginΪ��ʼλ��
//����ֵ ��   ��
void Permutation_Solution2(char *pStr, char *pBegin)
{
	if(*pBegin == '\0')
	{
		cout << pStr << endl;
	}
	else
	{
		char *pCh = pBegin;
		while(*pCh != '\0')
		{
			swap(*pBegin, *pCh);
			Permutation_Solution2(pStr, pBegin + 1);
			swap(*pBegin, *pCh);
			pCh++;
		}
	}
}

//�ṩ�Ĺ����ӿ�
void Permutation(char *pStr)
{
	Permutation_Solution1(pStr, 0, strlen(pStr));
	//Permutation_Solution2(pStr, pStr);
}

int main()
{
    char str[] = "abc";
        
    Permutation(str);

    return 0;
}
