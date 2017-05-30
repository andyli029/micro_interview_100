#include<iostream>
#include<string>
#include <string.h>
#include <vector>
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

void Combination_m(char *pStr, int m, vector<char> &result)  
{  
    if(pStr == NULL || (*pStr == '\0'&& m != 0))  
        return;  
    if(m == 0) //�ݹ���ֹ����  
    {  
        for(unsigned i = 0; i < result.size(); i++)  
            cout<<result[i];  
        cout<<endl;  
        return;  
    }  
    //ѡ�����Ԫ��  
    result.push_back(*pStr);  
    Combination_m(pStr + 1, m - 1, result);  
    result.pop_back();  
    //��ѡ�����Ԫ��  
    Combination_m(pStr + 1, m, result);  
}  
//�������� �� ��һ���ַ��������  
//�������� �� pStrΪ�ַ���  
//����ֵ ��   ��  
void Combination(char *pStr)  
{  
    if(pStr == NULL || *pStr == '\0')  
        return;  
    int number = strlen(pStr);  
    for(int i = 1; i <= number; i++)  
    {  
        vector<char> result;  
        Combination_m(pStr, i, result);  
    }  
}  

int main()
{
    char str[] = "abc";
        
    //Permutation(str);
    Combination(str);    

    return 0;
}
