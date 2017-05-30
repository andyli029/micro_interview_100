#include<iostream>
#include<string>
#include<cmath>
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

int main() {
    cout<<"Enter your Number:"<<endl;
    int number = 0;
    cin >>number;

    cout<<"the sum equals your number is:"<<endl;
    FindContinuousSequence(number);

    return 0;
}
