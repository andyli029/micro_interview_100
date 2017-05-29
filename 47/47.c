//动态规划

#include <iostream>
using namespace std;

#if 0
void FindLongestDSCArray(int* arr, int n, int idx1, int* ans, int idx2);
void FindLongestDSCArray2(int *arr, int n);

int maxNum = 0;
int res[20];

int main() {
	//Input()
	int input;
	int n;
	cin>>n;
	int *arr = new int[n];
	int i = 0;
	for(i=0;i<n;i++)
		cin>>arr[i];

	//FindLongestDSCArray
	int ans[20];
	int idx1=0,idx2=0;
	ans[idx2++] = arr[idx1++];
	//FindLongestDSCArray(arr, n, idx1, ans, idx2);
	FindLongestDSCArray2(arr,n);
	//Print()
    cout<<endl;
	for(i=0;i<maxNum;i++)
		cout<<res[i]<<" ";
	cout<<endl;

	return 0;
}

void FindLongestDSCArray(int* arr, int n, int idx1, int* ans, int idx2){
	if(idx1 >= n){
		if(idx2>maxNum){
			maxNum = idx2;
			int i = 0;
			for(i=0;i<idx2;i++)
				res[i] = ans[i];
		}
		return;
	}

	if(arr[idx1]< ans[idx2-1]){
		ans[idx2] = arr[idx1];
		FindLongestDSCArray(arr, n, idx1+1, ans, idx2+1);
	}
	else if(idx2-1>=0 && arr[idx1] == ans[idx2-1])
		FindLongestDSCArray(arr, n, idx1+1, ans, idx2);
	else if(idx2-1>=0 && arr[idx1] > ans[idx2-1]){
		//跳过
		FindLongestDSCArray(arr, n, idx1+1, ans, idx2);
		//回溯
		while(idx2-1>=0 && ans[idx2-1]<=arr[idx1])
			idx2--;
		ans[idx2] = arr[idx1];
		FindLongestDSCArray(arr,n,idx1+1,ans,idx2+1);
	}
}


void FindLongestDSCArray2(int *arr, int n){
	int *mark = new int[n];
	int *link = new int[n];

	int i = 0;
	for(i=0;i<n;i++){
		mark[i] = 0;
		link[i] = -1;
	}
	//link[0] = 1;

	int j = 0, maxMark = 0;
	for(i=0;i<n;i++){
		maxMark = 0;
		for(j=0;j<i;j++){
			if(arr[j]>arr[i]){
				if(maxMark<mark[j]){
					maxMark = mark[j];
					link[i] = j;
				}

			}
		}
		mark[i] = maxMark+1;
	}

	//Print()
	int node = 0;
	maxMark = 0;
	for(i=0;i<n;i++){
		if(mark[i]>maxMark)
			node = i;
	}

	while(node != -1){
		cout<<arr[node]<<" ";
		node = link[node];
	}
}
#endif


#include <iostream>
#include <cstring>
using namespace std;

int Fun(int aIn[],int pTable[],int nLen)
{
	int nMaxLen = 0;
	for(int i = nLen-1; i >= 0; --i) {
		int nMax = 0;
		for(int j = i+1; j < nLen; ++j) {
			if(aIn[j] < aIn[i]) {
				nMax = nMax < pTable[j] ? pTable[j] : nMax;
			}
		}
		pTable[i] = 1+nMax;
		nMaxLen = nMaxLen<pTable[i] ? pTable[i] : nMaxLen;
	}

	return nMaxLen;
}

void PrintMaxSubsequence(int aIn[], int pTable[], int nMaxLen, int nLen)
{
	for(int i = 0,j=0; i < nLen; ++i) {
		if(pTable[i] == nMaxLen){
			cout << aIn[i] << " ";
			nMaxLen--;
		}
	}
	cout << endl;
}

int main()
{
	int aIn[] = {9,4,3,2,5,4,3,2};
	int nLen = sizeof(aIn)/sizeof(int);
	int* pTable = new int[nLen];
	memset(pTable,0,nLen*sizeof(int));
	int nMaxLen = Fun(aIn,pTable,nLen);
	cout << nMaxLen << endl;
	PrintMaxSubsequence(aIn,pTable,nMaxLen,nLen);
	delete [] pTable;
	return 0;
}

