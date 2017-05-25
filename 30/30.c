
#include <stdio.h>

int countOf1s(int n) {
  int prefix[10], suffix[10], digit[10]; //10 is enough for 32bit integers
  int i = 0;
  int j = 0;
  int base = 1;

  while (base < n)
  {
    suffix[i] = n % base;
    digit[i]  = (n % (base * 10)) - suffix[i];
    prefix[i] = (n - suffix[i] - digit[i] * base) / 10;
    i++;
    base *=10;
  }

  int count = 0;
  base = 1;

  for (j = 0; j < i; j++)
  {
    if (digit[j] < 1) count += prefix[j];
    else if (digit[j] == 1) count += prefix[j] + suffix[j] + 1;
    else count += prefix[j] + base;
    base *= 10;
  }

  return count;
}

long long int count(long long int n)
{  
    long long int count = 0;
 
    while(n)
    {  
        count += (n % 10 == 1) ? 1 : 0;  
        n = n / 10;  
    }

    return count;  
}

long long int counts(long long int n)
{
    int i = 0;
    int c = 0;

    for(i = 1; i <= n; i++)
    {  
        c += count(i);  
    }
    
    return c;
}

long long int counts2(long long int n)
{  
    // 1�ĸ���  
    long long int count = 0;
    // ��ǰλ
    long long int Factor = 1;
    // ��λ����
    long long int LowerNum = 0;
    // ��ǰλ���� 
    long long int CurrNum = 0;
    // ��λ����
    long long int HigherNum = 0;

    if(n <= 0)
    {
        return 0;
    }

    while((n / Factor) != 0)
    {
        //��λ����
        LowerNum = n - (n / Factor) * Factor;
        //��ǰλ����
        CurrNum = (n / Factor) % 10;
        //��λ����
        HigherNum = n / (Factor * 10);

        //���Ϊ0,����1�Ĵ����ɸ�λ����
        if(CurrNum == 0)
        {
            //���ڸ�λ���� * ��ǰλ��
            count += HigherNum * Factor;
        }
        //���Ϊ1,����1�Ĵ����ɸ�λ�͵�λ���� 
        else if(CurrNum == 1)
        {
            //��λ���� * ��ǰλ�� + ��λ���� + 1
            count += HigherNum * Factor + LowerNum + 1;
        }
        //�������1,����1�Ĵ����ɸ�λ����
        else
        {  
            //����λ����+1��* ��ǰλ��
            count += (HigherNum + 1) * Factor;
        }

        //ǰ��һλ
        Factor *= 10;
    }

    return count;
}

int main()
{
    int n = 0;

    printf("num:");
    scanf("%d", &n);

    printf("the num of one is: %d.\n", counts2(n));

    return 0;
}

