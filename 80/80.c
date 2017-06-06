//need to think
//catalan 数 to 46

/*
80.阿里巴巴一道笔试题（运算、算法）
问题描述:
个高矮不同的人,排成两排,每排必须是从矮到高排列,而且第二排比对应的第一排的人高,
问排列方式有多少种?
start time = 19:20
end time = 第二天 10:56
*/


#include <stdio.h>
#include <stdlib.h>

#define N 12
int way[2][6]; //存储方式

/*
min ***** B
A   ***** Max
*/
int TwoLines(int * num, int len) //输入数字必须从小到大排列
{
    static int ways = 0;
    if(len == 0)
    {
        ways++;
        printf("way:%d\n", ways);
        for(int j = 0; j < 2; j++)
        {
            for(int i = 0; i < N/2; i++)
            {
                printf("%d ", way[j][i]);
            }
            printf("\n");
        }
    }
    int minloc = (N - len)/4;  //当前最小数字的位置
    int maxloc = (N + len)/4 - 1; //当前最大数字的位置
    way[0][minloc] = num[0];
    way[1][maxloc] = num[len - 1];

    int Bminloc = len / 2 - 1;  //B最小可能的取值在num数组中的位置
    int Bmaxloc = len - 2;
    int Aminloc = 1;
    int Amaxloc = len/2;

    
    for (int b = Bminloc; b <= Bmaxloc; b++)
    {
        for (int a = Aminloc; a <= Amaxloc; a++)
        {
            if (a == b ) //数字不能相同
            {
                continue;
            }
            if (maxloc < N/2 - 1)  //b位置的数字必须比它右边的数字小
            {
                if( !(num[b] < way[0][maxloc + 1]) )
                {
                    continue;
                }
            }
            if (minloc > 0) //a位置的数字必须比它左边的大
            {
                if( !( num[a] > way[1][minloc - 1]))
                {
                    continue;
                }
            }

            way[0][maxloc] = num[b];
            way[1][minloc] = num[a];
            int * num2 = (int *)malloc((len - 4) * sizeof(int));
            int i, j;
            for (i = 1, j = 0; j < len - 4; i++)
            {
                if(i == b || i == a)
                {
                    continue;
                }
                num2[j] = num[i];
                j++;
            }

            TwoLines(num2, len - 4);
                
            free(num2);
        }
    }
    return ways;
}

int main()
{
    int num[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int ways = TwoLines(num, N);
    return 0;
}
