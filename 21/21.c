#include <stdio.h>
#include <set>
#include <string.h>

using namespace std;

#define N 100


//with number repeat
void zuhe(int n, int m, int* path, int octave)
{
	//printf("n: %d, m: %d\n", n, m);
	if(m < 0 || n < 1)
		return;
	
	if(m == 0)
	{
		for (int i = 0; i < octave; i++)
		{
			printf("%d ", path[i]);
		}
		printf("\n");
	}
	else
	{
		zuhe(n-1, m, path, octave);
		path[octave] = n;
		zuhe(n, m-n, path, octave + 1);	
	}
}


//with no number repeat
void zuhe2(int n, int m, int* path, int octave)
{
	// printf("n: %d, m: %d\n", n, m);
	// for (int i = 0; i < octave; i++)
	// {
	// 	printf("%d: %d ", i, path[i]);
	// }
	// printf("\n");

	if(m < 0 || n < 0)
		return;
	
	if(m == 0)
	{
		for (int i = 0; i < octave; i++)
		{
			printf("%d ", path[i]);
		}
		printf("\n");
	}
	else
	{
		zuhe2(n-1, m, path, octave);
		path[octave] = n;
		zuhe2(n-1, m-n, path, octave + 1);	
	}
}

/******************************************************************/
// another solution

void dump(int aux[], int n) {
  for (int i = 0; i < n; i++) 
    if (aux[i]) printf("%3d", i + 1);
  printf("\n");
}

void helper(int dest, int idx, int aux[], int n) {
  if (dest == 0) 
    dump(aux, n);
  if (dest <= 0 || idx == n) return;

  helper(dest, idx + 1, aux, n);
  aux[idx] = 1;

  helper(dest - idx - 1, idx + 1, aux, n);
  aux[idx] = 0;
}

void findCombination(int n, int m) {
  if (n > m) findCombination(m, m);
  int aux[n];
  memset(aux, 0, n * sizeof(int));
  helper(m, 0, aux, n);
}

/******************************************************************/

int main()
{
	int n = 5;
	int m = 8;
	int path[N];
	//zuhe2(n, m, path, 0);

    findCombination(5, 8);
}