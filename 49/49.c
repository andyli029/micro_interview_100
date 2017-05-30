
#include <iostream>
using namespace std;

void SuperSort(int *arr, int n);

int main() {
    int n;
    cin>>n;
    int i = 0;
    int *arr = new int[n];
    for(i=0;i<n;i++)
        cin>>arr[i];

    SuperSort(arr,n);
    // 清理内存
    delete arr;
    return 0;
}

void SuperSort(int *arr, int n){
    int hashTable[65535];
    int i = 0;
    //申请空间初始化
    for(i=0;i<65535;i++)
        hashTable[i]=0;
    //排序
    for(i=0;i<n;i++)
        hashTable[arr[i]]++;
    //结果
    for(i=0;i<65535;i++){
        if(hashTable[i] != 0){
            cout << i << " ";
            hashTable[i--]--;
        }
    }
    cout << endl;

}

