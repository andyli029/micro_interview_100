
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

//nGroup arg mean n x n
bool CalcPosition(int **ppW, int *pOrder, int *pResult, int nGroup)	
{
	assert(ppW);
	assert(pOrder);
	assert(pResult);
	assert(nGroup > 0);

	int i32I = 0, i32J = 0;
	int nCurPos = nGroup - 1;
	vector<int> vectOrder;
    vector<int>::iterator it;

	for (i32I = 0; i32I < nGroup; i32I++)
		vectOrder.push_back(pOrder[i32I]);

	while (vectOrder.size() > 1)
	{
		for (it = vectOrder.begin(); it != vectOrder.end(); ++it)
		{
			if (it + 1 != vectOrder.end())
			{
				if (ppW[*it][*(it + 1)] == *it)
				{
					pResult[nCurPos--] = *(it + 1);
					vectOrder.erase(it + 1);
				}
				else
				{
					pResult[nCurPos--] = *it;
					it = vectOrder.erase(it);
				}
			}
		}
	}

	if (vectOrder.size() == 1)
		pResult[nCurPos--] = vectOrder[0];

	return true;
}

int main()
{
	int n;
	cout << "input the team num:";
	cin >> n;
	cout << endl << "input the power matrix:" << endl;

	int **ppW = new int* [n];
	assert(*ppW);
	for (int i32I = 0; i32I < n; i32I++)
	{
		ppW[i32I] = new int [n];
		assert(ppW);
		for (int i32J = 0; i32J < n; i32J++)
			cin >> ppW[i32I][i32J];
	}

	int *pOrder = new int[n];
	assert(pOrder);
	cout << "input the VS:" << endl;
	for (int i32I = 0; i32I < n; i32I++)
		cin >> pOrder[i32I];

	int *pRes = new int[n];
	assert(pRes);
	if (CalcPosition(ppW, pOrder, pRes, n))
	{
		cout << endl << "the rank is:" << endl;
		for (int i32I = 0; i32I < n; i32I++)
			cout << pRes[i32I] << " ";
	}

	//don't forget to free memory...

	return 0;
}

