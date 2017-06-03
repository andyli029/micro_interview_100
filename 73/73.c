
#if 0
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

/*********************************************************************
* 计算字符串最大对称子串的长度
*********************************************************************/

int MaxSymmetricalSubstringLenth(char* pstring)
{
    int maxlength = 1;

    char* pchar = pstring + 1;
    while(*pchar != '\0')
    {
        //以该字符串为中心，子串长度为奇数
        char *pfirst = pchar - 1;
        char *psecond = pchar + 1;
        while(pfirst > pstring && psecond < &pstring[strlen(pstring) - 1] 
              && *pfirst == *psecond)
        {
            pfirst--;
            psecond++;
        }

        int templength = psecond - pfirst + 1;
        if(templength > maxlength)
        {
            maxlength = templength;
        }


        //字该字符及之后的字符两个为中心，子串为偶数
        pfirst = pchar - 1;
        psecond = pchar;
        while(pfirst > pstring && psecond < &pstring[strlen(pstring) - 1] 
              && *pfirst == *psecond)
        {
            pfirst--;
            psecond++;
        }
        
        templength = psecond - pfirst + 1;
        if(templength > maxlength)
        {
            maxlength = templength;
        }
        
        pchar++;
    }

    return maxlength;
}

int main()
{
    cout<<"Please Enter Your String:"<<endl;
    char *yourstring = new char[1000];
    cin>>yourstring;

    cout<<"The Max Symmetrical SubString Length is:"<<endl;
    cout<<MaxSymmetricalSubstringLenth(yourstring)<<endl;

    delete[] yourstring;    
    return 0;
}

#endif

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

/*********************************************************************
* 计算字符串最大对称子串的长度
*********************************************************************/
int MaxSymmetricalSubstringLenth(char* pstring)
{
    int maxlength = 1;

    char* pchar = pstring + 1;
    while(*pchar != '\0')
    {
        //以该字符串为中心，子串长度为奇数
        char *pfirst = pchar - 1;
        char *psecond = pchar + 1;
        while(pfirst > pstring && psecond < &pstring[strlen(pstring) - 1] 
              && *pfirst == *psecond)
        {
            pfirst--;
            psecond++;
        }

        int templength = psecond - pfirst + 1;
        if(templength > maxlength)
        {
            maxlength = templength;
        }


        //字该字符及之后的字符两个为中心，子串为偶数
        pfirst = pchar - 1;
        psecond = pchar;
        while(pfirst > pstring && psecond < &pstring[strlen(pstring) - 1] 
              && *pfirst == *psecond)
        {
            pfirst--;
            psecond++;
        }
        
        templength = psecond - pfirst + 1;
        if(templength > maxlength)
        {
            maxlength = templength;
        }
        
        pchar++;
    }

    return maxlength;
}

int main()
{
    cout<<"Please Enter Your String:"<<endl;
    char *yourstring = new char[1000];
    cin>>yourstring;

    cout<<"The Max Symmetrical SubString Length is:"<<endl;
    cout<<MaxSymmetricalSubstringLenth(yourstring)<<endl;

    delete[] yourstring;    
    return 0;
}
