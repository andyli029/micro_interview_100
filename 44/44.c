// ./a.out < 1
// maybe have bug
// �ȴ���ÿ�����ŵĵõ�hashֵ��Ȼ�������map�����С�
// Map<hashֵ������>�������Եõ�ÿ�����Ŷ�Ӧ���ظ�������
// ��������O(n)��ʱ��Ϳ����ҵ������ǰ10��
//
//

#include <iostream>
#include <map>
#include <iterator>
#include <stdio.h>
using namespace std;

#define HASH __gnu_cxx
#include <ext/hash_map>
#define uint32_t unsigned int
#define uint64_t unsigned long int

struct StrHash
{
    uint64_t operator()(const std::string& str) const
    {
        uint32_t b = 378551;
        uint32_t a = 63689;
        uint64_t hash = 0;

        for(size_t i = 0; i < str.size(); i++)
        {
            hash = hash * a + str[i];
            a = a * b;
        }

        return hash;
    }
    uint64_t operator()(const std::string& str, uint32_t field) const
    {
        uint32_t b = 378551;
        uint32_t a = 63689;
        uint64_t hash = 0;

        for(size_t i = 0; i < str.size(); i++)
        {
            hash = hash * a + str[i];
            a = a * b;
        }

        hash = (hash<<8) + field;
        return hash;
    }
};


struct NameNum{
    string name;
    int num;
    NameNum():num(0),name(""){}
};
int main()
{
    HASH::hash_map< string, int, StrHash > names;
    HASH::hash_map< string, int, StrHash >::iterator it;
    NameNum namenum[10];
    string l = "";

    while(getline(cin, l))
    {
        it = names.find(l);
        if(it != names.end())
        {
            names[l] ++;
        }
        else
        {
            names[l] = 1;
        }
    }

    int i = 0;
    int max = 1;
    int min = 1;
    int minpos = 0;

    for(it = names.begin(); it != names.end(); ++it)
    {
        if(i < 10)
        {
            namenum[i].name = it->first;
            namenum[i].num = it->second;
            if(it->second > max)
                max = it->second;
            else if(it->second < min)
            {
                min = it->second;
                minpos = i;
            }
        }
        else
        {
            if(it->second > min)
            {
                namenum[minpos].name = it->first;
                namenum[minpos].num = it->second;
                int k = 1;
                min = namenum[0].num;
                minpos = 0;

                while(k < 10)
                {
                    if(namenum[k].num < min)
                    {
                        min = namenum[k].num;
                        minpos = k;
                    }
                    k++;
                }
            }
        }

        i++;
    }

    i = 0;
    cout << "maxlength (string,num): " << endl;

    while(i < 10)
    {
        cout << "(" << namenum[i].name.c_str() << "," << namenum[i].num << ")" << endl;
        i++;
    }

    return 0;
}


