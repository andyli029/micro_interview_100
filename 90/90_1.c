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
		if(shuru[i] != shanchu)//������Ϊ����ȡ������
			shuru[j++] = shuru[i];
		i++;
	}
    //����ǳ���Ҫ ��Ϊ��while()ѭ������ �����һ��\0�ַ���ʱ�����˳�ѭ���� 
    //��˻ᶪʧ���ַ����Ľ�����־ ֮���ӡ��һֱ��ӡ��ԭ�ַ����Ľ����ط�
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