
#if 0
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

/*********************************************************************
* �����ַ������Գ��Ӵ��ĳ���
*********************************************************************/

int MaxSymmetricalSubstringLenth(char* pstring)
{
    int maxlength = 1;

    char* pchar = pstring + 1;
    while(*pchar != '\0')
    {
        //�Ը��ַ���Ϊ���ģ��Ӵ�����Ϊ����
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


        //�ָ��ַ���֮����ַ�����Ϊ���ģ��Ӵ�Ϊż��
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
* �����ַ������Գ��Ӵ��ĳ���
*********************************************************************/
int MaxSymmetricalSubstringLenth(char* pstring)
{
    int maxlength = 1;

    char* pchar = pstring + 1;
    while(*pchar != '\0')
    {
        //�Ը��ַ���Ϊ���ģ��Ӵ�����Ϊ����
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


        //�ָ��ַ���֮����ַ�����Ϊ���ģ��Ӵ�Ϊż��
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
