#include <stdio.h>

#define N 5
#define M 4

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
		//printf("%d ", point);
		prior = point;

		for (int i = 0; i < delEle - 1; ++i)
		{
			prior = cursor[prior];
		}

		point = cursor[prior];
		cursor[prior] = cursor[point];
		count++;
	}

	printf("%d\n", point);

    printf("%d\n", joseph(N, M));    

	return 1;
}

