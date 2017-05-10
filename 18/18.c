#include <stdio.h>

#define N 3
#define M 1

int joseph(int n, int m) {
  int fn = 0;

  for (int i = 2; i <= n; i++)
  {
    fn = (fn + m) % i;  
  }

  return fn;
}

int main()
{
	// int array[N];
	// for(int i = 0; i < N; i++)
	// 	array[i] = i+1;
	int cursor[ N ];
	int delEle = M;

	for (int i = 0; i < N; i++)
		cursor[i] = (i + 1) % N;

	int count = 1;
	int point = delEle;
	cursor[point - 1] = cursor[point];
	int del;
	int prior;

	while (count < N)
	{
		printf("\npoint:%d ", point);
		prior = point;

		for (int i = 0; i < delEle - 1; ++i)
        {
			prior = cursor[prior];
            printf("prior:%d.", prior);            
		}

		point = cursor[prior];
		cursor[prior] = cursor[point];
        printf("prior:%d, point:%d, cursor[%d]:%d.\n",
                    prior, point, prior,cursor[prior]); 
		count++;
	}

    if (point == 0)
    {
        point = N;
    }

	printf("\n%d", point);

    printf("\n%d\n", joseph(N, M));    

	return 1;
}

