#include<iostream>
using namespace std;

int findNum(int* arr, int n)
{
    if (arr == NULL) return 0;
    int *cand = new int[n];
    int idx = 0;//记录当前cand数组元素个数
    cand[idx++] = arr[0];
    int max = arr[0], i;

    for (i = 1; i < n; i++)
    {
        if (arr[i] >= max)
        {
            cand[idx++] = arr[i];
            max = arr[i];
        }
        else
        {
            while(idx > 0 && cand[idx - 1] > arr[i])
                idx--;
        }
    }

    for (i = 0; i < idx; i++)
        cout<< cand[i] <<" ";
    cout << endl;

    delete[] cand;

    return idx;
}

int main()
{
      int arr[20] = {1, 2, 4, 5, 6, 7, 8, 9, 10, 3, 11};
    int count = 0;
    count = findNum(arr, 11);
    cout<<count<<endl;
}