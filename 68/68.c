// need to think another solution
//���¶���ȽϺ�������
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

		return s1 < s2;   //�������У������Ϊs1 > s2��Ϊ��������
	}
};
//�������� �� �������ų���С����
//�������� �� pArrayΪ����,numΪ����Ԫ�ظ���  
//����ֵ ��   ��
void ComArrayMin(int *pArray, int num)
{
	int i;
	string *pStrArray = new string[num];

	for(i = 0; i < num; i++) //������ת��Ϊ�ַ���
	{	
		stringstream stream;
		stream<<pArray[i];
		stream>>pStrArray[i];
	}

	sort(pStrArray, pStrArray + num, compare()); //�ַ�����������

	for(i = 0; i < num; i++) //��ӡ�ַ�������
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