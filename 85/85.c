
// ����һ���������ϲ������ַ���A��B���ַ���A�ĺ󼸸��ֽں��ַ���B��ǰ�����ֽ��ص��� 

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

	for(i = 0; i < len; i++)//����a ��ʼ���ҵ�ǰiλ�õ������Ƿ���b��ǰ׺ 
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
	for(k = 0; k < i; k++)//��i��ʼ ��bǰ����ͬ 
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
    // �ַ�������Ϊ [0 �� size -1], ���һ���ַ�Ϊ�����ַ���\0���������Ч�ַ����� index < size -1   
    while(pos < sz && posa < sza - 1 && posb < szb - 1){
        // ���a����û���ҵ���b�������ַ���ƥ��ģ���˵���������ص���  
        // ���ҵ��ص�֮ǰ����a������Ӧ�ַ�������Ŀ�괮  
        while((pachar[posa] != pbchar[0]) && (posa < sza - 1)){   
            result[pos] = pachar[posa];  
            ++pos;  
            ++posa;  
        }  
          
        // ����a��ֹͣ�����ֿ�������ֱ��� һ�ǿ�����a��ĩβ������������b�����ַ���ƥ������  
        if(posa == sza - 1){  // ������ĩβ, ��������b��ֱ������  
                while(posb <= szb - 1){  
                result[pos] = pbchar[posb];  
                ++pos;  
                ++posb;  
            }  
            break;  
        }
        //������ͬ�ַ��������������һ�������ص��ִ�����a���˴���ʼ�Ĳ�����b������ʼ������ȫ��ͬ������ż����ͬ�ַ�������ͷβ�ص�  
        else
        {
            sa = posa; // Ϊ�����ص��Ľ�����汸�ü�¼  
            while((pachar[posa] == pbchar[posb]) && (posa < sza - 2) && (posb < szb - 2)){ // ѭ���ж��Ƿ���ȫ�ص�  
                ++posa;  
                ++posb;  
            }  
            if(posa == sza - 2){ // �ص�  
                posb = 0;   // �ָ�posb��ʼλ��  
                while(posb <= szb - 1){  
                    result[pos] = pbchar[posb];  
                    ++pos;  
                    ++posb;  
                }  
                break;  
            }else{ // ż����ͬ�ַ�  
                posa = sa; // �ָ� posa ż�� b[0] λ��  
                posb = 0;   // �ָ�posb��ʼλ��  
                result[pos] = pachar[posa];  
                ++pos;  
                ++posa;  
            }  
        }  
    }  
}  