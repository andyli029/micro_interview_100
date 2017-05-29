// Catalan c(2n ,n)/(n + 1) = c(2n, n) - c(2n, n-1)
// https://zh.wikipedia.org/wiki/%E5%8D%A1%E5%A1%94%E5%85%B0%E6%95%B0

#include <iostream>
#include <list>
using namespace std;

#define N 6
int count = 0;
list<char> arrayList;
void BracketPermutation(int left, int right, int num);

int main() {
	BracketPermutation(0, 0, N);
    cout << count << endl;
    return 0;
}

// Permutation:组合
void BracketPermutation(int left, int right, int num){
	//条件1
#if 1
    if (left < right)
        return;
#endif

	if (num == 0) {
        std::_List_iterator<char> it = arrayList.begin();
        count++;
        for(; it != arrayList.end(); it++)
            cout << *it;
        cout << endl;
	}

    //条件2
    if (left < (N / 2)) {
        arrayList.push_back('(');
        num--;
        left++;

        BracketPermutation(left, right, num);

        arrayList.pop_back();
        num++;
        left--;
    }

    if (right < (N / 2)) {
        arrayList.push_back(')');
        num--;
        right++;

        BracketPermutation(left, right, num);

        arrayList.pop_back();
        num--;
        right--;
    }
}

