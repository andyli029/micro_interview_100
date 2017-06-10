// need to fix the name

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

void deletechar(char* shuru, char shanchu)
{
	int i=0, j=0;
	while(shuru[i])
	{
		if(shuru[i] != shanchu)//不等于为想提取的数据
			shuru[j++] = shuru[i];
		i++;
	}
    //这个非常重要 因为在while()循环里面 到最后一个\0字符的时候是退出循环的 
    //因此会丢失掉字符串的结束标志 之后打印会一直打印到原字符串的结束地方
	shuru[j]='\0';
}
int main(void)
{
    
	char shuru1[100]={0},shanchu;
	char *shuru=shuru1;

	gets(shuru);

	scanf("%c",&shanchu);

	deletechar(shuru, shanchu);

	printf("%s\n",shuru);

    return 0;
}