
/*
40.2)
һ����β����������(m ��)���� N ����ɫ(N<=10)��
���һ���㷨��ȡ������һ�Σ�Ҫ��������� N ����ɫ����ʹ������̡�
������ʱ�临�Ӷ���ռ临�Ӷȡ�
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int shortestlengh(char * in, char ** dst, int N)
{
    //���inin����ʽ����������
    int nlen = strlen(in);
    char * in2 = (char *)malloc(2 * nlen * sizeof(char)); 
    memcpy(in2, in, nlen * sizeof(char));
    memcpy(in2 + nlen, in, nlen * sizeof(char));

    int start = 0, end = nlen - 1;
    int shortestlen = nlen;
    int hash[256] = {0};
    int colornum = 0;
    int s = 0, e = -1;

    //�������п��ܵ���ʼ��
    while(s < nlen)
    {
        //�ҵ��ڵ�ǰ������ҵ�������ɫ�Ľ�β
        while (colornum < N && e <= 2 * nlen) 
        {    
            e++;
            if (hash[(int)(in2[e])] == 0)
            {
                colornum++;
            }
            hash[(int)(in2[e])]++;
        }

        //ȥ��ǰ����ͬ�Ĳ���
        while (in2[s] == in2[s + 1])
        {
            s++;
            hash[(int)in2[s]]--;
        }

        //������̵Ĵ�
        if (shortestlen > e - s + 1)
        {
            shortestlen = e - s + 1;
            start = s;
            end = e;
        }
        
        //�Ż�
        if (e - s + 1 == N)
        {
            printf("the least found before running through.\n");
            break;
        }

        //����s,����һ����ɫ��ʼ
        hash[(int)in2[s]]--;
        if (hash[(int)in2[s]] == 0)
        {
            colornum--;
        }
        s++;
    }

    *(dst) = (char *)malloc(end - start + 2);
    memcpy(*dst, in2 + start, end - start + 1);
    (*dst)[end - start + 1] = '\0'; //ע��
    
    printf("the traverse is stopped at %d,", s);
    printf("the left chars is %s.\n", in2 + s);

    free(in2);
    
    return end - start + 1;
}

int shortestlengh2(char * in, char ** dst, int N)
{
    //���inin����ʽ����������
    int nlen = strlen(in);
    char * in2 = (char *)malloc(2 * nlen * sizeof(char)); 
    memcpy(in2, in, nlen * sizeof(char));
    memcpy(in2 + nlen, in, nlen * sizeof(char));

    int start = 0, end = nlen - 1;
    int shortestlen = nlen;
    int hash[256] = {0};
    int colornum = 0;
    int s = 0, e = 0;// -1

    //�������п��ܵ���ʼ��
    while(s < nlen)
    {
        //�ҵ��ڵ�ǰ������ҵ�������ɫ�Ľ�β
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

        //ȥ��ǰ����ͬ�Ĳ���
        while (in2[s] == in2[s + 1])
        {
            s++;
            hash[(int)in2[s]]--;
        }

        //������̵Ĵ�
        if (shortestlen > e - s + 1)
        {
            shortestlen = e - s + 1;
            start = s;
            end = e;
        }
        
        //�Ż�
        if (e - s + 1 == N)
        {
            printf("the least found before running through.\n");
            break;
        }

        //����s,����һ����ɫ��ʼ
        hash[(int)in2[s]]--;
        if (hash[(int)in2[s]] == 0)
        {
            colornum--;
        }
        s++;
    }

    *(dst) = (char *)malloc(end - start + 2);
    memcpy(*dst, in2 + start, end - start + 1);
    (*dst)[end - start + 1] = '\0'; //ע��
    
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

