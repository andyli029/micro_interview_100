
/*
40.2)
一串首尾相连的珠子(m 个)，有 N 种颜色(N<=10)，
设计一个算法，取出其中一段，要求包含所有 N 种颜色，并使长度最短。
并分析时间复杂度与空间复杂度。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int shortestlengh(char * in, char ** dst, int N)
{
    //变成inin的形式，避免求余
    int nlen = strlen(in);
    char * in2 = (char *)malloc(2 * nlen * sizeof(char)); 
    memcpy(in2, in, nlen * sizeof(char));
    memcpy(in2 + nlen, in, nlen * sizeof(char));

    int start = 0, end = nlen - 1;
    int shortestlen = nlen;
    int hash[256] = {0};
    int colornum = 0;
    int s = 0, e = -1;

    //遍历所有可能的起始点
    while(s < nlen)
    {
        //找到在当前起点下找到所有颜色的结尾
        while (colornum < N && e <= 2 * nlen) 
        {    
            e++;
            if (hash[(int)(in2[e])] == 0)
            {
                colornum++;
            }
            hash[(int)(in2[e])]++;
        }

        //去掉前面相同的部分
        while (in2[s] == in2[s + 1])
        {
            s++;
            hash[(int)in2[s]]--;
        }

        //更新最短的串
        if (shortestlen > e - s + 1)
        {
            shortestlen = e - s + 1;
            start = s;
            end = e;
        }
        
        //优化
        if (e - s + 1 == N)
        {
            printf("the least found before running through.\n");
            break;
        }

        //更新s,从下一个颜色开始
        hash[(int)in2[s]]--;
        if (hash[(int)in2[s]] == 0)
        {
            colornum--;
        }
        s++;
    }

    *(dst) = (char *)malloc(end - start + 2);
    memcpy(*dst, in2 + start, end - start + 1);
    (*dst)[end - start + 1] = '\0'; //注意
    
    printf("the traverse is stopped at %d,", s);
    printf("the left chars is %s.\n", in2 + s);

    free(in2);
    
    return end - start + 1;
}

int shortestlengh2(char * in, char ** dst, int N)
{
    //变成inin的形式，避免求余
    int nlen = strlen(in);
    char * in2 = (char *)malloc(2 * nlen * sizeof(char)); 
    memcpy(in2, in, nlen * sizeof(char));
    memcpy(in2 + nlen, in, nlen * sizeof(char));

    int start = 0, end = nlen - 1;
    int shortestlen = nlen;
    int hash[256] = {0};
    int colornum = 0;
    int s = 0, e = 0;// -1

    //遍历所有可能的起始点
    while(s < nlen)
    {
        //找到在当前起点下找到所有颜色的结尾
        while (colornum < N && e <= 2 * nlen) 
        {   
            if (hash[(int)(in2[e])] == 0)
            {
                colornum++;
            }
            hash[(int)(in2[e])]++;

            if (colornum < N)
            {
                e++;
            }
        }

        //去掉前面相同的部分
        while (in2[s] == in2[s + 1])
        {
            s++;
            hash[(int)in2[s]]--;
        }

        //更新最短的串
        if (shortestlen > e - s + 1)
        {
            shortestlen = e - s + 1;
            start = s;
            end = e;
        }
        
        //优化
        if (e - s + 1 == N)
        {
            printf("the least found before running through.\n");
            break;
        }

        //更新s,从下一个颜色开始
        hash[(int)in2[s]]--;
        if (hash[(int)in2[s]] == 0)
        {
            colornum--;
        }
        s++;
    }

    *(dst) = (char *)malloc(end - start + 2);
    memcpy(*dst, in2 + start, end - start + 1);
    (*dst)[end - start + 1] = '\0'; //注意
    
    printf("the traverse is stopped at %d,", s);
    printf("the left chars is %s.\n", in2 + s);

    free(in2);
    
    return end - start + 1;
}

int main()
{
    //char *s = "addcddcbccbba";
    char *s = "addcddcbaccbba";
    char *d = NULL;
    int n = shortestlengh(s, &d, 4);
    printf("%d\n%s\n", n, d);
    return 0;
}

