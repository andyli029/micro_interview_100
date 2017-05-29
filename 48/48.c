
#include <iostream>
using namespace std;

int FindData(int* arr,int value,int l,int r)
{
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(arr[mid]==value)
            return mid;
        else
        {
            if(arr[l]>=arr[mid])
            {
                if(value>arr[mid] && value<=arr[l])
                    r=mid-1;
                else
                    l=mid+1;
            }
            else
            {
                if(value<arr[mid] && value>=arr[r])
                    l=mid+1;
                else
                    r=mid-1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[]={6,4,2,0,10,8};
    int n;
    cin >>n;
    cout <<FindData(arr,n,0,5)<<endl;
    return 0;
}

