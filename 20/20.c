#include <stdio.h>

int str2int(char *str)
{
    char *cursor = str;
    int num = 0;
    int sum = 0;

    for (cursor; (*cursor >= '0'  && *cursor <= '9'); cursor++)
    {
        num = (int)( *cursor - '0');

        if ( sum == 0)
        {
            sum = num;
        }  
        else
        {
            sum = sum * 10 + num;
        }  
    }  

    return sum;
}

int main()
{
    char num_str[10] = {"34567"};

    printf("%d\n", str2int(num_str));

    return 0;
}


