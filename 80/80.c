//need to think
//catalan �� to 46

/*
80.����Ͱ�һ�������⣨���㡢�㷨��
��������:
���߰���ͬ����,�ų�����,ÿ�ű����ǴӰ���������,���ҵڶ��űȶ�Ӧ�ĵ�һ�ŵ��˸�,
�����з�ʽ�ж�����?
start time = 19:20
end time = �ڶ��� 10:56
*/


#include <stdio.h>
#include <stdlib.h>

#define N 12
int way[2][6]; //�洢��ʽ

/*
min ***** B
A   ***** Max
*/
int TwoLines(int * num, int len) //�������ֱ����С��������
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
    int minloc = (N - len)/4;  //��ǰ��С���ֵ�λ��
    int maxloc = (N + len)/4 - 1; //��ǰ������ֵ�λ��
    way[0][minloc] = num[0];
    way[1][maxloc] = num[len - 1];

    int Bminloc = len / 2 - 1;  //B��С���ܵ�ȡֵ��num�����е�λ��
    int Bmaxloc = len - 2;
    int Aminloc = 1;
    int Amaxloc = len/2;

    
    for (int b = Bminloc; b <= Bmaxloc; b++)
    {
        for (int a = Aminloc; a <= Amaxloc; a++)
        {
            if (a == b ) //���ֲ�����ͬ
            {
                continue;
            }
            if (maxloc < N/2 - 1)  //bλ�õ����ֱ�������ұߵ�����С
            {
                if( !(num[b] < way[0][maxloc + 1]) )
                {
                    continue;
                }
            }
            if (minloc > 0) //aλ�õ����ֱ��������ߵĴ�
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
