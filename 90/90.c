//类似于不借助辅助变量交换两个值

#include <cstdio>
#include <string.h>

template <typename T>
 static void swap(T &a, T &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}
void reverse(char *s)
{
    int i = 0;
    int len = strlen(s);
    int j = len - 1;

    while(i < j)
    {

        /****************
        异或方法交换两个数据
        s[i] = s[i]^s[j];
        s[j] = s[i]^s[j];
        s[i] = s[i]^s[j];
        *****************/
        swap(s[i], s[j]);
        i++;
        j--;
    }
}

int main(void)
{
    char str[] = "Buyer's Remorse";
    printf("%s\n",str);

    reverse(str);
    printf("%s\n",str);
    
    return 0;
}