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
        //�ҵ�����k
        if((2*n) % k == 0)
        {
            int temp1 = 2 * n - k*k + k;
            int temp2 = 2 * n + k*k - k;

            //��ʼ��start��������end��Ϊ����
            if(temp1 % (2*k) == 0 && temp2 % (2*k) == 0)
            {
                int start = temp1 / (2*k);
                int end = temp2 / (2*k);

                //��ӡ��start��end֮���������
                for(int i = start;i <= end;++i)
                    cout<<i<<"\t";
                
                cout<<endl;
            }
        }
    }
}

// �������
/*
���� a + (a+1) + ... + b = n ��һ���𰸣��������͹�ʽ���� (a + b) * (b - a

+ 1) / 2 = n, �� (a+b)�� (b-a+1)�ֱ���2N
��һ�����ӣ�ö������һ�����Ϳ����ж�����ڶ�����

Ȼ�����a��b�ˡ�ʱ�临�Ӷ���O(sqrt(n)).2n�����ӷ�Χ�϶���[2,sqrt(2n)]֮�䡣

   ���岽�裺���裨b-a+1)������һ�����ӣ�����ͨ��2n%i == 0�ҵ�һ������i,
Ȼ����������

��a+b)*(b-a+1)/2 = n�Ĺ�ʽ�����Ƶ��� 2*a*i = 2n - i^2 + i, ���ֻҪ�ж�a
�����������⣬��

����֪����������������2n����һ������Ҳ�Ǵ��ڵ�

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
