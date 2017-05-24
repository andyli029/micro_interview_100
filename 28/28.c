#include <stdio.h>

int count_bit(int n)
{
    int count = 0;

    while(n != 0)
    {
        if(n % 2 ==1)
            count++;

        n /= 2;
    }

    return count;
}

int count_1(int n) {
    int c = 0;

    while (n != 0)
    {
        n = n & (n - 1);
        c++;
    }

    return c;
}

#if 0
int count_2(int n) {
    int c = 0;
    if (n<0) 
    { 
        c++; 
        n = n & (1<<(sizeof(int)*8-1)); 
    }

    while (n != 0)
    {
        c += tab[ n & 0xff];
        n >>= 8;
    }

    return c;
}
#endif
int main()  
{
    int nStep = 0;

    printf("num:");
    scanf("%d", &nStep);

    printf("the num of one is: %d.\n", count_bit(nStep));

    printf("the num of one is: %d.\n", count_1(nStep));

    return 0;
}