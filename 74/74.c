#include <iostream>
using namespace std;

bool g_bInputInvalid = false;
 
//////////////////////////////////////////////////////////////////////////
// Input: an array with "length" numbers. A number in the array
// appear more than "length / 2 + 1" times.
// Output: If the input is valid, return the number appearing more than
// "length / 2 + 1" times. Otherwise, return 0 and set flag g_bInputInvalid
// to be true.
//////////////////////////////////////////////////////////////////////////
int MoreThanHalfNum(int* numbers, unsigned int length)
{
    if(numbers == NULL && length == 0)
    {
        g_bInputInvalid = true;
        return 0;
    }
 
    g_bInputInvalid = false;
 
    int result = numbers[0];
    int times = 1;
    for(int i = 1; i < length; ++i)
    {
        if(times == 0)
        {
            result = numbers[i];
            times = 1;
        }
        else if(numbers[i] == result)
            times++;
        else
            times--;
    }
 
    // verify whether the input is valid
    times = 0;
    for(int i = 0; i < length; ++i)
    {
        if(numbers[i] == result)
            times++;
    }
 
    if(times * 2 <= length)
    {
        g_bInputInvalid = true;
        result = 0;
    }
 
    return result;
}

int main()
{
    int a[] = {1, 2, 3, 4, 2, 3, 2, 2, 2};

    cout << MoreThanHalfNum(a, 9) << endl;

    return 0;
}

