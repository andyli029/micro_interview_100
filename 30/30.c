
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
    // 1的个数  
    long long int count = 0;
    // 当前位
    long long int Factor = 1;
    // 低位数字
    long long int LowerNum = 0;
    // 当前位数字 
    long long int CurrNum = 0;
    // 高位数字
    long long int HigherNum = 0;

    if(n <= 0)
    {
        return 0;
    }

    while((n / Factor) != 0)
    {
        //低位数字
        LowerNum = n - (n / Factor) * Factor;
        //当前位数字
        CurrNum = (n / Factor) % 10;
        //高位数字
        HigherNum = n / (Factor * 10);

        //如果为0,出现1的次数由高位决定
        if(CurrNum == 0)
        {
            //等于高位数字 * 当前位数
            count += HigherNum * Factor;
        }
        //如果为1,出现1的次数由高位和低位决定 
        else if(CurrNum == 1)
        {
            //高位数字 * 当前位数 + 低位数字 + 1
            count += HigherNum * Factor + LowerNum + 1;
        }
        //如果大于1,出现1的次数由高位决定
        else
        {  
            //（高位数字+1）* 当前位数
            count += (HigherNum + 1) * Factor;
        }

        //前移一位
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

