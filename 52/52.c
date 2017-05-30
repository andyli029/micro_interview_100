#include<iostream>
#include<string>
#include<cmath>
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

int main() {
    cout<<"Enter your Number:"<<endl;
    int number = 0;
    cin >>number;

    cout<<"the sum equals your number is:"<<endl;
    FindContinuousSequence(number);

    return 0;
}
