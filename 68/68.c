// need to think another solution
//重新定义比较函数对象
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

struct compare
{
	bool operator() (const string &src1, const string &src2)
	{
		string s1 = src1 + src2;
		string s2 = src2 + src1;

		return s1 < s2;   //升序排列，如果改为s1 > s2则为逆序排列
	}
};
//函数功能 ： 把数组排成最小的数
//函数参数 ： pArray为数组,num为数组元素个数  
//返回值 ：   无
void ComArrayMin(int *pArray, int num)
{
	int i;
	string *pStrArray = new string[num];

	for(i = 0; i < num; i++) //将数字转换为字符串
	{	
		stringstream stream;
		stream<<pArray[i];
		stream>>pStrArray[i];
	}

	sort(pStrArray, pStrArray + num, compare()); //字符串数组排序

	for(i = 0; i < num; i++) //打印字符串数组
		cout<<pStrArray[i];

	cout<<endl;

	delete [] pStrArray;
}



int main()
{
    int arr[] = {121, 232, 342};
    int arr1[] = {123, 32, 12};
    
    ComArrayMin(arr1, 3);    

    return 0;        
}