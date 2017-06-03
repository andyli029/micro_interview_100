#include <iostream>
using namespace std;

// need to think
/**
 * ��Ŀ�����˿����������5���ƣ��ж��ǲ���һ��˳�ӣ� ����5�����ǲ��������ġ�
 * 2��10Ϊ���ֱ��� AΪ1�� JΪ11��QΪ12�� Ϊ13��С�����Կ����������֡�
 * @param numbers
 * @return
 */
#if 0
bool isContinuous(array numbers)
{
        if (numbers == null || numbers.length != 5) {
            return false;
        }
        // ��Ԫ�ؽ�������
        array.sort(numbers);
        int numberOfZero = 0;
        int numberOfGap = 0;
        for (int i = 0; i < numbers.length && numbers[i] == 0; i++) {
            numberOfZero++;
        }
        // ��һ����0Ԫ�ص�λ��
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
    int *temp = new int[14];//������hash
    int i = 0;
    int max = 1;
    int min = 13;

    for(i = 0; i < 14; i++)//0---13
        temp[i] = 0;

    for(i = 0; i < 5; i++)
    {
        if(A[i] > max)
            max = A[i];//��¼�����
        if(A[i] < min && A[i] != 0)
            min = A[i];//��¼��С��
        if(temp[A[i]] != 0 && A[i] != 0)//�з��������ƣ�
            return false;
        temp[A[i]]++;//��hash ����¼���ƣ�������Ƶ�ֵ��
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
