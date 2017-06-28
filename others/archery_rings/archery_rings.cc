#include <iostream>
using namespace std;

/************************************************************************/
/*       
	一个射击运动员打靶，靶一共有10环，连开10枪打中90环的可能性
	有多少种？请用递归算法编程实现。
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
	if (score < 0 || score > (num + 1) * 10) //次数num为0-9
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