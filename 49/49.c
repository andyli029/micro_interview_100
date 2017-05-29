
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
	//前面几个实验都老是忘了delete 这个很不好，还是要铭记在心，尤其我是那么那么的珍惜内存啊
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
			cout<<i<<" ";
			hashTable[i--]--;
		}
	}

}

