#include <stdio.h>

// the bad taste
bool desideTree(int* a, int start, int end)
{
	if(start + 1 >= end)
		return true;

	int t = start;
	while(t < end)
	{
		if(a[t] > a[end])
			break;
		t++;
	}

	int mid = t;
	while(t < end)
	{
		if(a[t] < a[end])
			break;
		t++;
	}

	if(t < end)
		return false;

	bool result1 = desideTree(a, start, mid-1);
	bool result2 = desideTree(a, mid, end-1);

	return (result1 && result2);
}


// my code: the damn onsite in 2017.6.30 on the 2nd round of AI&R in MS, 
// a long long ..way to go
bool be_post(int arr[], int length)
{
	int i = 0;
	int mid = 0;

	if (arr == NULL)
		return false;

	if (length == 1 || length == 0)// the two  choice: or judge pre the func
		return true;
	
	int root = arr[length - 1];
	
	for (i = 0; i < length; i++)
	{
		if (arr[i] > root)
		{
			mid = i;
			break;
		}

		mid = i; // the past bugfix 
	}

	i = mid;
	for (i; i < length - 1; i++)
	{
		if (arr[i] <= root)
		{
			return false;
		}
	}

	bool left = true;
	//if (mid > 0) // the past bugfix
		left = be_post(arr, mid);		

	bool right = true;
	//if (mid < length - 1)// the past bugfix
		right = be_post(arr + mid, length - mid - 1);	

	return (left && right);
}


int main()
{
	int a[4] = {7, 4, 6, 5};

	int a1[4] = {1, 2, 3, 4};
	//bool result = desideTree(a, 0, 3);

    bool result = be_post(a1, 4);

	if(result)
		printf("true\n");
	else
		printf("false\n");

    return 0;
}