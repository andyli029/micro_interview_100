#include<iostream>
#include<string>
#include <string.h>
using namespace std;

//函数功能 ： 求一个字符串某个区间内字符的全排列
//函数参数 ： pStr为字符串，begin和end表示区间
//返回值 ：   无
void Permutation_Solution1(char *pStr, int begin, int end)
{
	if(begin == end - 1) //只剩一个元素
	{
		for(int i = 0; i < end; i++) //打印
			cout << pStr[i];
		cout << endl;
	}
	else
	{
		for(int k = begin; k < end; k++)
		{
			swap(pStr[k], pStr[begin]); //交换两个字符
			Permutation_Solution1(pStr, begin + 1, end);
			swap(pStr[k], pStr[begin]);  //恢复
		}
	}
}

//函数功能 ： 求一个字符串某个区间内字符的全排列
//函数参数 ： pStr为字符串，pBegin为开始位置
//返回值 ：   无
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

//提供的公共接口
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
