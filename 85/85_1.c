// 
#include <iostream>
#include <iomanip> 
#include <limits>
#include <stdio.h>
#include <string.h>
using namespace std;

int get_substr_num(char *p, int p_len, char *sub, int sub_len)
{
    int i;
    int s;
    int sum = 0;

    for (i = 0; i < p_len; i++)
    {
        s = 0;
        while (p[i] == sub[s])
        {
            s++;
            i++;
            if (s == sub_len)
            {
                sum++;
                break;
            }
        }
    }

    return sum;
}

int main()
{
    int sum = 0;
    char pachar[] = "aswewasweweastytyastrtas";  
    char pbchar[] = "as";  
  
    int sza = strlen(pachar);
    int szb = strlen(pbchar);

    cout << pachar << ", the len is:"<< sza << endl;
    cout << pbchar << ", the len is:" << szb << endl;    
    sum = get_substr_num(pachar, sza, pbchar, szb);
    cout << "the sum of the same sub in parent is:" << sum << endl;
    
    return 0;
}
