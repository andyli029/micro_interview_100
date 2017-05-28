
// *1 y = 3^x
// 

//*2
// for i in {1..100}; do echo $i >> 1;done;
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include <sys/time.h>
using namespace std;

#define m 10
#define max 100

int getdata(FILE* fp)//生成数据流的样本数据
{
    int i = 1;
    if(fp != NULL)
    {
        while(i< max)
        {
            char tmp[m];
            memset(tmp, 0, m);

            if(i == max -1)
                    sprintf(tmp, "%d\n", i++);
            else
                    sprintf(tmp, "%d\n ", i++);

            cout << tmp << endl;
            //fwrite(tmp, strlen(tmp), 1, fp);
        }
    }
    return -1;
}

int main(int argc, char* argv[])
{
#if 1
     //生产数据流的语句 模拟
    FILE* fp = fopen("1", "rwb");
    //getdata(fp);
    //fclose(fp);
#endif
    int i = 0;
    int a[m];
    string l = "";
    char buf[10];
    struct timeval * tv;
        

    unsigned int time_ = (unsigned int)time(NULL);
    gettimeofday(tv , NULL);
    srand(time_ + tv->tv_usec);

    while(fgets(buf, 10, fp))//getline(cin, l)
    {
        const char* p1 = buf;//l.c_str();
        const char* p2 = NULL;
        char tmp[100];
        while(*p1 != '\0')
        {
            p2 = p1;
            while(*p2 != ',' && *p2 != '\0')
                    p2 ++;

            memset(tmp, 0, 100);
            strncpy(tmp, p1, p2-p1);
            int k = atoi(tmp);
            if(i < m)
                    a[i] = k;
            else
            {
                //rand algritem
                //unsigned int time_ = (unsigned int)time(NULL);
                int rand_ = random();
                int l = rand_ %(i+1);

                if(l < m)
                {
                    a[l] = k;
                    cout << "rand:" << rand_ << ", i+1:" << i+1 
                         << ", l:"<< l <<", k:"<< k << endl; 
                }
            }
            i ++;
            if(*p2 != '\0')
                    p2 ++;
            p1 = p2;
        }
    }

    if(i > m)
    {
        i = 0;
        cout << "rand m data:";
        while(i < m)

                cout << a[i++] << ",";
        cout << endl;
    }
    else
        cout << "have no stream" << endl;

    return 0;
}
