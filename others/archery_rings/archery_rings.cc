#include <iostream>
using namespace std;

/************************************************************************/
/*       
	һ������˶�Ա��У���һ����10��������10ǹ����90���Ŀ�����
	�ж����֣����õݹ��㷨���ʵ�֡�
*/
/************************************************************************/

int sum = 0;
int storeResult[10];

void OutPut()
{
#if 0
	for (int i = 9; i >= 0; --i)
	{
		cout << storeResult[i] << " ";
	}
	cout << endl;
#endif
	++sum;
}

void Comput(int score, int num)
{
	if (score < 0 || score > (num + 1) * 10) //����numΪ0-9
		return;

	if (num == 0)
	{
		storeResult[num] = score;
		OutPut();
		return;
	}

	for (int i = 0; i <= 10; ++i)
	{
		storeResult[num] = i;
		Comput(score - i, num - 1);
	}
}

int main()
{
	Comput(90, 9);
	cout << "the total count: " << sum << endl;

	return 0;
}