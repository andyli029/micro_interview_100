// need to think
#include <stdio.h>

//函数功能 ： 找出数组中两个只出现一次的数字
//函数参数 ： arr为源数组，len为数组元素个数，result用来存放结果 
//返回值 ：   无
void FindIsolateTwo(int *arr, int len, int *result)
{
	int i, all = 0, flag = 1;

	for(i = 0; i < len; i++) //所有数异或
		all ^= arr[i];
#if 1
	while(!(all & flag))  //寻找过滤位
		flag <<= 1;
#endif
	result[0] = result[1] = 0;

	for(i = 0; i < len; i++) //利用过滤位区分
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

