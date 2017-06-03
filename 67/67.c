#include <iostream>
using namespace std;

// need to think
/**
 * 题目：从扑克牌中随机抽5张牌，判断是不是一个顺子， 即这5张牌是不是连续的。
 * 2～10为数字本身， A为1。 J为11、Q为12、 为13。小王可以看成任意数字。
 * @param numbers
 * @return
 */
#if 0
bool isContinuous(array numbers)
{
        if (numbers == null || numbers.length != 5) {
            return false;
        }
        // 对元素进行排序
        array.sort(numbers);
        int numberOfZero = 0;
        int numberOfGap = 0;
        for (int i = 0; i < numbers.length && numbers[i] == 0; i++) {
            numberOfZero++;
        }
        // 第一个非0元素的位置
        int small = numberOfZero;
        int big = small + 1;
        while (big < numbers.length) {
            if (numbers[small] == numbers[big]) {
                return false;
            }
            numberOfGap += (numbers[big] - numbers[small] - 1);
            small = big;
            big++;
        }
        return numberOfGap <= numberOfZero;
}
#endif

bool isContinuous(int A[])
{
    int *temp = new int[14];//用于做hash
    int i = 0;
    int max = 1;
    int min = 13;

    for(i = 0; i < 14; i++)//0---13
        temp[i] = 0;

    for(i = 0; i < 5; i++)
    {
        if(A[i] > max)
            max = A[i];//记录最大牌
        if(A[i] < min && A[i] != 0)
            min = A[i];//记录最小牌
        if(temp[A[i]] != 0 && A[i] != 0)//有非王的重牌；
            return false;
        temp[A[i]]++;//做hash ，记录王牌，或非玩牌的值。
    }

    if(max - min <= 4)
        return true;
    else
        return false;
}

int main() {
    int numbers1[] = {1, 3, 2, 5, 4};
    cout << isContinuous(numbers1) << endl;

    int numbers2[] = {1, 3, 2, 6, 4};
    cout << isContinuous(numbers2) << endl;
}
