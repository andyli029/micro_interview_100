// need to think
#include <stdio.h>

//�������� �� �ҳ�����������ֻ����һ�ε�����
//�������� �� arrΪԴ���飬lenΪ����Ԫ�ظ�����result������Ž�� 
//����ֵ ��   ��
void FindIsolateTwo(int *arr, int len, int *result)
{
	int i, all = 0, flag = 1;

	for(i = 0; i < len; i++) //���������
		all ^= arr[i];
#if 1
	while(!(all & flag))  //Ѱ�ҹ���λ
		flag <<= 1;
#endif
	result[0] = result[1] = 0;

	for(i = 0; i < len; i++) //���ù���λ����
	{
		if(flag & arr[i])
			result[0] ^= arr[i];
		else
			result[1] ^= arr[i];
	}
}

int main()
{
    int array[] = {2, 1, 3, 4, 5, 6, 6, 4, 3, 2};
    int len = 10;
    int res[2];
    
    FindIsolateTwo(array, len, res);
    printf("the result is: %d, %d.\n", res[0], res[1]);
}

