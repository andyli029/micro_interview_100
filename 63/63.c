#include<iostream>
#include<string>
using namespace std;

void DelChars(char* pstrSource,char* pstrDel)
{
    if(pstrSource == NULL || pstrDel == NULL)
        return;
    
    //建立并初始化哈希表
    const int hashLength = 256;
    unsigned int hashList[hashLength];
    for(int i = 0;i < hashLength; ++i)
    {
        hashList[i] = 0;
    }
    
    //hash表中存储第二个字符串中每个字符出现的次数
    char *pch = pstrDel;
    while(*pch != '\0')
    {
        hashList[*pch]++;
        pch++;
    }

    char *pfast = pstrSource;
    char *pslow = pstrSource;
    while(*pfast != '\0')
    {
        //如果pfast指向的字符不需要删除，就把其所指的值赋给pslow，两者都向后移
//否则，pfast向后移动继续寻找，pslow不动
        if(hashList[*pfast] == 0)
        {
            *pslow = *pfast;
            pslow++;
        }
        pfast++;
    }

    //非常容易忽视，记得加上字符串结束符！
    *pslow = '\0';
}

int main()
{
    const int StrMaxLength = 100;
    cout<<"Enter your first(/resource) string:"<<endl;
    char strFirst[StrMaxLength];
    cin.getline(strFirst,sizeof(strFirst));

    cout<<"Enter your second(/detele) string:"<<endl;
    char strSecond[StrMaxLength];
    cin.getline(strSecond,sizeof(strSecond));

    cout<<"the final string you want is:"<<endl;
    DelChars(strFirst,strSecond);
    cout<<strFirst<<endl;

    return 0;
}

