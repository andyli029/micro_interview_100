#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

//abcd1234abd346894abc
//abcd1234abd346894
//abcd1
// 1dfa
//abcd1234a
bool isNumber(char c)
{
	return ('0' <= c && c <= '9');
}
int LIS(char *str, int *index)
{
	int i = 0,j = 0,max = 0,len = strlen(str);
	char ch;

	while( i < len )
	{
		while(i < len && !isNumber(str[i]))
			++i;
			
		j = i;
		ch = str[i];
		while(j < len && isNumber(str[j]) && ch <= str[j])
		{
			ch = str[j];
			++j;
		}

		if( j - i > max)
		{
			max = j - i;
			cout << "the index:" << i <<endl;
			*index = i;
		}	

		i = j;
	}

	return max;
}
int main()
{
	char str[100];
	int index = -1;
    int len = -1;
    
	while(gets(str) != NULL)
	{
	    len = LIS(str, &index);
	    cout << len <<":"<< index << endl;
	}

	return 0;
}