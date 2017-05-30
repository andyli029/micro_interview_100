#include<iostream>
#include<string>
#include<cmath>
#include<stdio.h>
using namespace std;

void FindContinuousSequence(int n)
{
    int half = (int)(sqrt(2*n));
    for(int k = 2;k <= half;++k)
    {
        //找到因子k
        if((2*n) % k == 0)
        {
            int temp1 = 2 * n - k*k + k;
            int temp2 = 2 * n + k*k - k;

            //开始数start，结束数end都为整数
            if(temp1 % (2*k) == 0 && temp2 % (2*k) == 0)
            {
                int start = temp1 / (2*k);
                int end = temp2 / (2*k);

                //打印从start到end之间的所有数
                for(int i = start;i <= end;++i)
                    cout<<i<<"\t";
                
                cout<<endl;
            }
        }
    }
}

// 便于理解
/*
假设 a + (a+1) + ... + b = n 是一个答案，则根据求和公式就是 (a + b) * (b - a

+ 1) / 2 = n, 则 (a+b)和 (b-a+1)分别是2N
的一个因子，枚举其中一个，就可以判断求出第二个，

然后求出a和b了。时间复杂度是O(sqrt(n)).2n的因子范围肯定在[2,sqrt(2n)]之间。

   具体步骤：假设（b-a+1)是其中一个因子，可以通过2n%i == 0找到一个因子i,
然后根据上面的

（a+b)*(b-a+1)/2 = n的公式可以推导出 2*a*i = 2n - i^2 + i, 因此只要判断a
存在正整数解，就

可以知道满足上面条件的2n的另一个因子也是存在的

*/
void ContinuousSequenceSum_2(int n)
{
	int nMax = (int)sqrt(2*n) + 1;
	int start,end,i;
	for(i = 2; i < nMax; i++)
	{
		if(2*n % i == 0)
		{   
			int tmp = 2*n - i*i + i;
			if(tmp % (2*i) == 0)
			{
				start = tmp / (2*i);
				end = start + i -1;
				//printf("start = %d, end = %d.\n", start, end);

                for(int i = start;i <= end;++i)
                    cout<<i<<" ";
                cout<<endl;
			}
		}
	}
}

int main() {
    cout<<"Enter your Number:"<<endl;
    int number = 0;
    cin >>number;

    cout<<"the sum equals your number is:"<<endl;
    ContinuousSequenceSum_2(number);

    return 0;
}
