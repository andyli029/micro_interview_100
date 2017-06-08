
// 给出一个函数来合并两个字符串A和B。字符串A的后几个字节和字符串B的前几个字节重叠。 

#include <iostream>
#include <iomanip> 
#include <limits>
#include <stdio.h>
#include <string.h>
using namespace std;

#define N 101

void copystr(char pachar[], char pbchar[], int sza, int szb,  char* &result);  
void myStrcpy(char a[],char b[]);

int main()  
{  
    char pachar[] = "asdfvxcbnbvcxzghgh";  
    char pbchar[] = "ghjklqwe";  
  
    int sza = sizeof(pachar);
    int szb = sizeof(pbchar);
    int sz = sza + szb - 1;
    char* result = new char[sz]; 

    //copystr(pachar, pbchar, sza, szb, result);
    cout << result << endl;

    myStrcpy(pachar, pbchar);
  
    return 0;
}  

// the clear thinking
void myStrcpy(char a[], char b[])
{
	char c[N];
	int len,len2,i,j,k,f;
	len = strlen(a);
	f = 0;

	for(i = 0; i < len; i++)//遍历a 开始查找当前i位置到结束是否是b的前缀 
	{
		k = i;
		j = 0;
		while(a[k] == b[j])
		{
			k++;
			j++;
			if(k == len)
			{
				f = 1;
				break;
			}
		}

		if(f == 1) break;
	}

	len2 = strlen(b);
	for(k = 0; k < i; k++)//从i开始 与b前面相同 
		c[k] = a[k];
	for(j = 0; j < len2; k++,j++)
		c[k] = b[j];

	for(i = 0; i < k; i++)
		printf("%c", c[i]);
	printf("\n");
}

void copystr(char pachar[], char pbchar[], int sza, int szb, char* &result)  
{  
        int posa = 0;  
    int posb = 0;  
    int pos = 0;  
    int sa = 0;  
    int sz = sza + szb - 1;
    // 字符串索引为 [0 ～ size -1], 最后一个字符为结束字符‘\0’，因此有效字符索引 index < size -1   
    while(pos < sz && posa < sza - 1 && posb < szb - 1){
        // 如果a串中没找找到与b串中首字符相匹配的，则说明不存在重叠，  
        // 在找到重叠之前，将a串中相应字符拷贝到目标串  
        while((pachar[posa] != pbchar[0]) && (posa < sza - 1)){   
            result[pos] = pachar[posa];  
            ++pos;  
            ++posa;  
        }  
          
        // 拷贝a串停止，两种可能情况分别处理： 一是拷贝到a串末尾，二是遇到与b串首字符相匹配的情况  
        if(posa == sza - 1){  // 拷贝到末尾, 继续拷贝b串直至结束  
                while(posb <= szb - 1){  
                result[pos] = pbchar[posb];  
                ++pos;  
                ++posb;  
            }  
            break;  
        }
        //遇到相同字符，分两种情况，一是遇到重叠字串，即a串此处开始的部分与b串的起始部分完全相同，二是偶遇相同字符，不是头尾重叠  
        else
        {
            sa = posa; // 为不是重叠的结果保存备用记录  
            while((pachar[posa] == pbchar[posb]) && (posa < sza - 2) && (posb < szb - 2)){ // 循环判断是否完全重叠  
                ++posa;  
                ++posb;  
            }  
            if(posa == sza - 2){ // 重叠  
                posb = 0;   // 恢复posb初始位置  
                while(posb <= szb - 1){  
                    result[pos] = pbchar[posb];  
                    ++pos;  
                    ++posb;  
                }  
                break;  
            }else{ // 偶遇相同字符  
                posa = sa; // 恢复 posa 偶遇 b[0] 位置  
                posb = 0;   // 恢复posb初始位置  
                result[pos] = pachar[posa];  
                ++pos;  
                ++posa;  
            }  
        }  
    }  
}  