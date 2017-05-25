#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

#define PRODUCER_NUM   5  //��������
#define CONSUMER_NUM   3  //��������
#define PRD_NUM        20 //��������Ĳ�Ʒ��
#define DELAY_TIME     3  //����(������)����֮������ʱ����

#define QUEUE_SIZE     (PRD_NUM + 1) //�����������QUEUE_SIZE-1��Ԫ��

#if 0
struct Queue{
     ElemType elem[MaxSize];
     int head, tail;
};
#endif

typedef struct queue_{
     int aData[QUEUE_SIZE];  //����Ԫ��
     int dwHead;  //ָ�����Ԫ��
     int dwTail;  //ָ���βԪ�ص���һ��Ԫ��
}T_QUEUE, *PT_QUEUE;

//��ʼ��ѭ������
void InitQue(T_QUEUE *ptQue)
{
    memset(ptQue, 0, sizeof(*ptQue));
}

//��ѭ�������в���Ԫ��
void EnterQue(PT_QUEUE ptQue, int dwElem)
{
    if(IsQueFull(ptQue))
    {
        printf("Elem %d cannot enter Queue %p(Full)!\n", dwElem, ptQue);
        return;
    }
    ptQue->aData[ptQue->dwTail]= dwElem;
    ptQue->dwTail = (ptQue->dwTail + 1) % QUEUE_SIZE;
}

//��ѭ��������ȡ��Ԫ��
int LeaveQue(PT_QUEUE ptQue)
{
    if(IsQueEmpty(ptQue))
    {
        printf("Queue %p is Empty!\n", ptQue);
        return -1;
    }
    int dwElem = ptQue->aData[ptQue->dwHead];
    ptQue->dwHead = (ptQue->dwHead + 1) % QUEUE_SIZE;
    return dwElem;
}

//�Ӷ�������β������ʾ����Ԫ��ֵ
void DisplayQue(PT_QUEUE ptQue)
{
    if(IsQueEmpty(ptQue))
    {
        printf("Queue %p is Empty!\n", ptQue);
        return;
    }

    printf("Queue Element: ");
    int dwIdx = ptQue->dwHead;
    while((dwIdx % QUEUE_SIZE) != ptQue->dwTail)
        printf("%d ", ptQue->aData[(dwIdx++) % QUEUE_SIZE]);

    printf("\n");
}

//�ж�ѭ�������Ƿ�Ϊ��
int IsQueEmpty(PT_QUEUE ptQue)
{
    return ptQue->dwHead == ptQue->dwTail;
}

//�ж�ѭ�������Ƿ�Ϊ��
int IsQueFull(PT_QUEUE ptQue)
{
    return (ptQue->dwTail + 1) % QUEUE_SIZE == ptQue->dwHead;
}

//��ȡѭ������Ԫ����Ŀ
int QueDataNum(PT_QUEUE ptQue)
{
    return (ptQue->dwTail - ptQue->dwHead + QUEUE_SIZE) % QUEUE_SIZE;
}

//��ȡѭ�����ж���λ��
int GetQueHead(PT_QUEUE ptQue)
{
    return ptQue->dwHead;
}
//��ȡѭ�����ж���Ԫ��
int GetQueHeadData(PT_QUEUE ptQue)
{
    return ptQue->aData[ptQue->dwHead];
}
//��ȡѭ�����ж�βλ��
int GetQueTail(PT_QUEUE ptQue)
{
    return ptQue->dwTail;
}

//static T_QUEUE gtQueue;



#if 0
void main(void)
{
    InitQue(&gtQueue);
    printf("Enter Queue 1,2,3,4,5...\n");
    EnterQue(&gtQueue, 1);
    EnterQue(&gtQueue, 2);
    EnterQue(&gtQueue, 3);
    EnterQue(&gtQueue, 4);
    EnterQue(&gtQueue, 5);
    printf("Queue Status: Empty(%d), Full(%d)\n", IsQueEmpty(&gtQueue), 
    IsQueFull(&gtQueue));
    printf("Queue Elem Num: %u\n", QueDataNum(&gtQueue));
    printf("Head: %u(%d)\n", GetQueHead(&gtQueue), GetQueHeadData(&gtQueue));
    printf("Tail: %u\n", GetQueTail(&gtQueue));
    DisplayQue(&gtQueue);

    printf("\nLeave Queue...\n");
    printf("Leave %d\n", LeaveQue(&gtQueue));
    printf("Leave %d\n", LeaveQue(&gtQueue));
    printf("Leave %d\n", LeaveQue(&gtQueue));
    DisplayQue(&gtQueue);

    printf("\nEnter Queue 6,7...\n");
    EnterQue(&gtQueue, 6);
    EnterQue(&gtQueue, 7);
    DisplayQue(&gtQueue);

    printf("\nLeave Queue...\n");
    printf("Leave %d\n", LeaveQue(&gtQueue));
    printf("Leave %d\n", LeaveQue(&gtQueue));
    printf("Leave %d\n", LeaveQue(&gtQueue));
    DisplayQue(&gtQueue);
}
#endif

T_QUEUE gtQueue;
pthread_mutex_t gtQueLock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t gtPrdCond = PTHREAD_COND_INITIALIZER; //Full->Not Full
pthread_cond_t gtCsmCond = PTHREAD_COND_INITIALIZER; //Empty->Not Empty

void *ProducerThread(void *pvArg)
{
    pthread_detach(pthread_self());
    int dwThrdNo = *((int *)(pvArg));

    while(1)
    {
        pthread_mutex_lock(&gtQueLock);
        while(IsQueFull(&gtQueue))  //����������Ϊ����ʱ���������̱߳�����
            pthread_cond_wait(&gtPrdCond, &gtQueLock);

        EnterQue(&gtQueue, GetQueTail(&gtQueue)); 
        //������Ԫ���±���ΪԪ��ֵ���
        if(QueDataNum(&gtQueue) == 1) //�������߿�ʼ������֪ͨ(����)�������߳�
            pthread_cond_broadcast(&gtCsmCond);
        printf("[Producer %2u]Current Product Num: %u\n", dwThrdNo, QueDataNum(&gtQueue));

        pthread_mutex_unlock(&gtQueLock);
        sleep(rand()%DELAY_TIME + 1);
    }
}

void *ConsumerThread(void *pvArg)
{
    pthread_detach(pthread_self());
    int dwThrdNo = *((int *)(pvArg));

    while(1)
    {
        pthread_mutex_lock(&gtQueLock);
        //�����ɿձ�Ϊ�ǿ�ʱ���������߳̽�������
        while(IsQueEmpty(&gtQueue)) 
            pthread_cond_wait(&gtCsmCond, &gtQueLock);

        if(GetQueHead(&gtQueue) != GetQueHeadData(&gtQueue))
        {
            printf("[Consumer %2u]Product: %d, Expect: %d\n", dwThrdNo,
                   GetQueHead(&gtQueue), GetQueHeadData(&gtQueue));
            exit(0);
        }  
        LeaveQue(&gtQueue);
        //������������Ϊ����ʱ��֪ͨ(����)�������߳�
        if(QueDataNum(&gtQueue) == (PRD_NUM-1)) 
            pthread_cond_broadcast(&gtPrdCond);
        printf("[Consumer %2u]Current Product Num: %u\n", dwThrdNo, QueDataNum(&gtQueue));

        pthread_mutex_unlock(&gtQueLock);

        sleep(rand()%DELAY_TIME + 1);
    }
}

int main(void)
{
    InitQue(&gtQueue);
    srand(getpid());  //��ʼ���������������

    pthread_t aThrd[CONSUMER_NUM + PRODUCER_NUM];
    int dwThrdIdx;

    for(dwThrdIdx = 0; dwThrdIdx < CONSUMER_NUM; dwThrdIdx++)
    {  //����CONSUMER_NUM���������̣߳�����(void*)dwThrdIdx��ΪConsumerThread�Ĳ���
        pthread_create(&aThrd[dwThrdIdx], NULL, 
                    ConsumerThread, (void*)(&dwThrdIdx));
    }

    sleep(2);

    for(dwThrdIdx = 0; dwThrdIdx < PRODUCER_NUM; dwThrdIdx++)
    {
        pthread_create(&aThrd[dwThrdIdx + CONSUMER_NUM], NULL,
                    ProducerThread, (void*)&dwThrdIdx);
    }

    while(1);

    return 0 ;
}

