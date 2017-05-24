
#include <stdio.h>

int JumpStep(int n)  
{  
    if (n <= 0)  return 0;

    if (n == 1 || n == 2) return n;

    return ( JumpStep(n - 1) + JumpStep(n - 2) );  
}

int main(int argc, char *argv[])  
{
    int nStep = 0;
    printf("step num:");
    scanf("%d", &nStep);
    printf("step num:%d, the num of ways is: %d.\n", nStep, JumpStep(nStep));
    return 0;
}

