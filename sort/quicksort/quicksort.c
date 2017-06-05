#include <iostream>
using namespace std;

//Data swop function
void Swap(int &p,int &q)                          
{                                                      
    int temp = p;
    
    p = q;
    q = temp;
} 
 
//Partition function
int Partition(int ArrayInput[], int nLow, int nHigh)                
{
    int nTemp = ArrayInput[nHigh];   
    int i = nLow - 1;
    int j = nLow;

    for (; j < nHigh; j++)
    {
        if (ArrayInput[j] <= nTemp)
        {
            i++;
            if (i != j)
            {
                Swap(ArrayInput[i], ArrayInput[j]);
            }
        }
    }

    Swap(ArrayInput[i + 1], ArrayInput[nHigh]);

    return (i + 1);
}
 
//Quick sort
void Quick_sort(int ArrayInput[], int nLow, int nHigh)            
{
    if (nLow < nHigh)
    {
        int nIndex = Partition(ArrayInput , nLow, nHigh);
        Quick_sort(ArrayInput , nLow, nIndex - 1);
        Quick_sort(ArrayInput , nIndex + 1, nHigh);
    }
}

#define N 7

int main()
{
    int a[] = {2, 3, 8, 9, 6, 4, 1};
    unsigned int i = 0;

    Quick_sort(a, 0, N - 1);

    while (i < N)
    {
        cout << a[i] << endl;
        i++;
    }

    return 0;
}