// need to think
#include <iostream>
#include <math.h>
using namespace std;

const int FACE_NUM = 6; //骰子的面数

//函数功能 ： n个骰子的点数
//函数参数 ： number为骰子数
//返回值 ：   无
void PrintSumProbabilityOfDices(int number)
{
	if(number <= 0)
		return;

	int *pSum = new int[number * FACE_NUM + 1]; //和的种类
	double total = pow(6.0, number);  //<cmath>
	int size = number * FACE_NUM;
	int i, j, k;

	//初始化
	pSum[0] = 0;
	for(i = 1; i <= FACE_NUM; i++)
		pSum[i] = 1;
	for(; i <= size; i++)
		pSum[i] = 0;

	for(i = 2; i <= number; i++) //骰子个数从2到n
	{
		for(j = i * FACE_NUM; j >= i; j--) //第i个骰子的和的范围为 [i, i*FACE_NUM]
		{
			pSum[j] = 0;
//其实展开就是 F(i, j) = F(i-1, j-6) + F(i-1, j-5) + F(i-1, j-4) + F(i-1, j-3) + F(i-1, j-2) + F(i-1, j-1) 
			for(k = 1; k <= 6 && j >= k; k++) 
			{
                if (j == number * FACE_NUM)
                {
                    cout << j << endl;
                }
				pSum[j] += pSum[j - k]; 
			}
		}
		//不可能的情况，即i个骰子的和不可能小于i
		for(j = i - 1; j >= 0; j--)
			pSum[j] = 0;
	}

	//打印结果
	for(i = 0; i <= size; i++)
		cout<<"sum = "<<i<<", p = "<<pSum[i] / total<<endl;
}

int main()
{
    PrintSumProbabilityOfDices(2);
    return 0;
}