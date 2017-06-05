//char *strstr(char *haystack, char *needle);        
//功能：从字符串haystack中寻找needle第一次出现的位置（不比较结束符NULL)。
//说明：返回指向第一次出现needle位置的指针，如果没找到则返回NULL。
// 2次循环搞定 
 
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