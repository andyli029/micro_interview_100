// 
#include <iostream>
#include <iomanip> 
#include <limits>
#include <stdio.h>
#include <string.h>
using namespace std;

int get_substr_index(char *p, int p_len, char *sub, int sub_len)
{
    int i;
    int j;
    int s;
    int sum = 0;

    for (i = 0; i < p_len; i++)
    {
        s = 0;
        j = i;
        while (p[j] == sub[s])
        {
            s++;
            j++;
            if (s == sub_len)
            {
                return i;
            }
        }
    }

    return -1;
}

int main()
{
    int index = -1;
    char pachar[] = "aswewawsweweastytyastrtas";  
    char pbchar[] = "waws";  
  
    int sza = strlen(pachar);
    int szb = strlen(pbchar);

    cout << pachar << ", the len is:"<< sza << endl;
    cout << pbchar << ", the len is:" << szb << endl;    
    index = get_substr_index(pachar, sza, pbchar, szb);
    cout << "the sum of the same sub in parent is:" << index << endl;
    
    return 0;
}
