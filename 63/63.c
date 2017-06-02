#include<iostream>
#include<string>
using namespace std;

void DelChars(char* pstrSource,char* pstrDel)
{
    if(pstrSource == NULL || pstrDel == NULL)
        return;
    
    //��������ʼ����ϣ��
    const int hashLength = 256;
    unsigned int hashList[hashLength];
    for(int i = 0;i < hashLength; ++i)
    {
        hashList[i] = 0;
    }
    
    //hash���д洢�ڶ����ַ�����ÿ���ַ����ֵĴ���
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
        //���pfastָ����ַ�����Ҫɾ�����Ͱ�����ָ��ֵ����pslow�����߶������
//����pfast����ƶ�����Ѱ�ң�pslow����
        if(hashList[*pfast] == 0)
        {
            *pslow = *pfast;
            pslow++;
        }
        pfast++;
    }

    //�ǳ����׺��ӣ��ǵü����ַ�����������
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

