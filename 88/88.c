#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 类似快慢指针，从后往前
int fun(char array[], const char c)
{
	int length = strlen(array);
	int i, j, count;
	char temp;

	for(i = j = length - 1, count = 0; i >= 0; )
	{
		if(array[i] != c)
		{
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			i--;
			j--;
		}
		else
		{
			i--;
			count++;
		}		
	}	
	return count;
}

int main()
{
	char a1[] = "ab**cd**e*12";

	printf("%d\n", fun(a1, '*'));
	puts(a1);
	return 0;
}