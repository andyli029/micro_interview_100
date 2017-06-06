#include <stdio.h>
#include <stdbool.h> //gcc need the head file for declaration of bool

void Reorder(int *pData, unsigned int length, bool (*func)(int));
bool isEven(int);

/////////////////////////////////////////////////////////////////////////
// Devide an array of integers into two parts, the intergers which 
// satisfy func in the first part, otherwise in the second part
// Input: pData  - an array of integers
//        length - the length of array
//        func   - a function
/////////////////////////////////////////////////////////////////////////

void Reorder(int *pData, unsigned int length, bool (*func)(int))
{
    if(pData == NULL || length == 0)
        return;

    int *pBegin = pData;
    int *pEnd = pData + length - 1;

    while(pBegin < pEnd)
    {
        // if *pBegin does not satisfy func, move forward
        if(!func(*pBegin))
        {
            pBegin ++;
            continue;
        }

        // if *pEnd does not satisfy func, move backward
        if(func(*pEnd))
        {
            pEnd --;
            continue;
        }

        // if *pBegin satisfy func while *pEnd does not,
        // swap these integers
        int temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;
    }
}

/////////////////////////////////////////////////////////////////////////
// Determine whether an integer is even or not
// Input: an integer
// otherwise return false
/////////////////////////////////////////////////////////////////////////
//Even:Å¼Êý£¬odd:ÆæÊý
bool isEven(int n)
{
    return (n & 1) == 0;
}

/////////////////////////////////////////////////////////////////////////
// Devide an array of integers into two parts, odd in the first part,
// and even in the second part
// Input: pData  - an array of integers
//        length - the length of array
/////////////////////////////////////////////////////////////////////////
void ReorderOddEven(int *pData, unsigned int length)
{
    if(pData == NULL || length == 0)
        return;

    Reorder(pData, length, isEven);
}

int main()
{
    int array[] = {2, 1, 6, 10, 3, 5, 8, 7};
    int i = 0;

    ReorderOddEven(array, 8);

    for (; i < 8; i++)
    {
        printf("%d ", array[i]);
    }    
    printf("\n");

    return 0;
}
