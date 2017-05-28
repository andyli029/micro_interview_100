

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool testShare(int s[],int n,int m,int groupSum,int goal,int aux[],int groupId)
{
	if(goal ==0)
	{
		goal=groupSum;
		if (++groupId == m + 1)	return true;

	}
	for(int i=0;i<n;++i)
	{
		if(aux[i]) continue; //去掉已经选过的
		aux[i]=groupId;
		if(testShare(s,n,m,groupSum,goal-s[i],aux,groupId)) return true;
		aux[i]=0; //还原
	}
	return false;
}
int maxShare(int s[],int len)
{
	//m表示分成几组
	int i,m, sum=0;
	int aux[len];
	for(i=0;i<len;i++) sum+=s[i]; //求总和
	for(m=len;m>=2;--m)
	{
		if(sum%m !=0) continue; //不能被m整除，肯定不能平分
		memset(aux,0,sizeof(int)*len);
		if (testShare(s, len, m, sum / m, sum / m, aux, 1))
		{
			for (i = 0; i < len; i++)
				printf("i:%d, aux[i]:%d.\n", i, aux[i]);
			return m;
		}
	}
	return 1;
}
int main()
{
	//int a[] ={ 5, 4, 2, 2, 1 ,4, 6};
	int a[]={3, 2, 4, 3, 6};
	printf("\n group:%d.\n", maxShare(a, sizeof(a)/sizeof(int)));
}

