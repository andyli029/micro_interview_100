// need to think
#include <iostream>
#include <string.h>
using namespace std;

void PrintNumber(char* number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);

	for(int i = 0; i < nLength; i++)
	{
		if(isBeginning0 && number[i] != '0')
			isBeginning0 = false;

		if(!isBeginning0)
		{
			cout << number[i];
		}
	}
	cout << " ";
}

void Print1ToMaxOfNDigitsRecursively(char *number, 
                                            int length, int index)
{
	if(index == length - 1)
	{
		PrintNumber(number);
		return;
	}

	for(int i = 0; i < 10; i++)
	{
		number[index + 1] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
	}
}

void Print1ToMaxOfNDigit3(int n)
{
	if(n < 0)
        return;

	char *number = new char[n + 1];
	number[n] = '\0';
	
	for(int i = 0; i < 10; i++)
	{
		number[0] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, n, 0);
	}
    cout << endl;
}

// I optimize Print1ToMaxOfNDigit3
void Print1ToMaxOfNDigit_me(int n)
{
	if(n < 0)
        return;

	char *number = new char[n + 1];
	number[n] = '\0';
	
    Print1ToMaxOfNDigitsRecursively(number, n, -1);

    cout << endl;
}


int main()
{
    Print1ToMaxOfNDigit_me(2);
    return 0;
}
