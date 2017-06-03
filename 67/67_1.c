// need to think
#include <iostream>
#include <math.h>
using namespace std;

const int FACE_NUM = 6; //���ӵ�����

//�������� �� n�����ӵĵ���
//�������� �� numberΪ������
//����ֵ ��   ��
void PrintSumProbabilityOfDices(int number)
{
	if(number <= 0)
		return;

	int *pSum = new int[number * FACE_NUM + 1]; //�͵�����
	double total = pow(6.0, number);  //<cmath>
	int size = number * FACE_NUM;
	int i, j, k;

	//��ʼ��
	pSum[0] = 0;
	for(i = 1; i <= FACE_NUM; i++)
		pSum[i] = 1;
	for(; i <= size; i++)
		pSum[i] = 0;

	for(i = 2; i <= number; i++) //���Ӹ�����2��n
	{
		for(j = i * FACE_NUM; j >= i; j--) //��i�����ӵĺ͵ķ�ΧΪ [i, i*FACE_NUM]
		{
			pSum[j] = 0;
//��ʵչ������ F(i, j) = F(i-1, j-6) + F(i-1, j-5) + F(i-1, j-4) + F(i-1, j-3) + F(i-1, j-2) + F(i-1, j-1) 
			for(k = 1; k <= 6 && j >= k; k++) 
			{
                if (j == number * FACE_NUM)
                {
                    cout << j << endl;
                }
				pSum[j] += pSum[j - k]; 
			}
		}
		//�����ܵ��������i�����ӵĺͲ�����С��i
		for(j = i - 1; j >= 0; j--)
			pSum[j] = 0;
	}

	//��ӡ���
	for(i = 0; i <= size; i++)
		cout<<"sum = "<<i<<", p = "<<pSum[i] / total<<endl;
}

int main()
{
    PrintSumProbabilityOfDices(2);
    return 0;
}