//char *strstr(char *haystack, char *needle);        
//���ܣ����ַ���haystack��Ѱ��needle��һ�γ��ֵ�λ�ã����ȽϽ�����NULL)��
//˵��������ָ���һ�γ���needleλ�õ�ָ�룬���û�ҵ��򷵻�NULL��
// 2��ѭ���㶨 
 
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char* myStrstr(char *haystack, char *needle)
{
	char *res = NULL;
	int len1  = strlen(haystack);
	int len2  = strlen(needle);
	int i,j,n;
	
	if(len2 > len1) 
		return res;

	n = len1 - len2;
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j < len2; j++)
		{
			if (haystack[i + j]!=needle[j]) 
				break;
		}
		if (j == len2)
		{
			res = haystack + i;
			break;
		}
	}
	
	return res;
}

int main()
{
	char str1[] = "ababscdsa";
	char str2[] = "bsc";

	cout << myStrstr(str1, str2) <<endl;
	//bscdsa
	return 0;
}