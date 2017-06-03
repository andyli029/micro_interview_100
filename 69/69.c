#include <iostream>
using namespace std;

// Get the minimum number of a roatation of a sorted array
int Min(int *numbers, int length)
{
    if(numbers == 0 || length <= 0)
        throw new std::exception();//"Invalid parameters"

    int index1 = 0;
    int index2 = length - 1;
    int indexMid = index1;

    while(numbers[index1] >= numbers[index2])
    {
        if(index2 - index1 == 1)
        {
            indexMid = index2;
            break;
        }
 
        indexMid = (index1 + index2) / 2;

        if(numbers[indexMid] >= numbers[index1])
            index1 = indexMid;
        else if(numbers[indexMid] <= numbers[index2])
            index2 = indexMid;
    }

    return numbers[indexMid];
}

int main()
{
    int arr[6] = {3, 4, 5, 2};    
    
    cout << Min(arr, 4) << endl;    

    return 0;
}