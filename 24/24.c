#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;

typedef struct lnode_
{
    int data;
    struct lnode_ *next;
}lnode, *plnode;

plnode ReverseSinglyLinkedList(plnode list)
{
    lnode *newList;    //�������ͷ���
    lnode *tmp;       //ָ��list�ĵ�һ����㣬Ҳ����Ҫժ���Ľ��
 
    //����Ϊ�ջ����ڴ����ʧ���򷵻�NULL
    if (list == NULL || (newList = (lnode *)malloc(sizeof(lnode))) == NULL)
    {
        return NULL;
    }
 
    //��ʼ��newList
    newList->data = list->data;
    newList->next = NULL;
 
    //���ν�list�ĵ�һ�����ŵ�newList�ĵ�һ�����λ��
    while (list->next != NULL)
    {
        tmp = newList->next;         //����newList�еĺ������
        newList->next = list->next;       //��list�ĵ�һ�����ŵ�newList��
        list->next = list->next->next;     //��list��ժ��������
        newList->next->next = tmp;        //�ָ�newList�к�������ָ��
    }
 
    //ԭͷ���Ӧ���ͷŵ�����������ͷ����ָ��
    free(list);
    return newList;
}

lnode* ReverseSinglyLinkedList2(lnode *list)
{
    lnode *tmp = NULL;
    lnode *p   = NULL;

    if (list == NULL)
    {
        return NULL;
    }

    tmp = list->next;

    while (tmp->next != NULL)
    {
        p = tmp->next;
        tmp->next = p->next;
        p->next = list->next;
        list->next = p;
    }

    return list;
}

lnode* ReverseSinglyLinkedList3(lnode *list)
{
    lnode *cursor1 = NULL;
    lnode *cursor2 = NULL;
    lnode *cursor  = NULL;

    if (list == NULL)
    {
        return NULL;
    }

    //�����һ���ڵ��nextû�д����������ѭ��������:list->next->next = NULL
    cursor  = list->next->next;
    cursor1 = list->next;

    while (cursor!= NULL)
    {
        cursor2 = cursor;
        cursor = cursor->next;
        cursor2->next = cursor1;
        cursor1 = cursor2;
    }

    list->next->next = NULL;
    list->next = cursor2;

    return list;
}

lnode* ReverseSinglyLinkedList4(lnode *list)
{
    lnode *cursor1 = NULL;
    lnode *cursor2 = NULL;
    lnode *cursor  = NULL;

    if (list == NULL)
    {
        return NULL;
    }

    cursor  = list->next;
    cursor1 = list->next;

    while (cursor->next != NULL)
    {
        cursor2 = cursor->next;
        cursor->next = cursor->next->next;
        cursor2->next = cursor1;
        cursor1 = cursor2;
    }

    list->next = cursor2;

    return list;
}

lnode* LinkedListCreat()
{
    lnode *l;
    l = (lnode *)malloc(sizeof(lnode));   //����ͷ���ռ�
    l->next = NULL;                      //��ʼ��һ��������
     
    int x;                         //xΪ�����������е�����
    while(scanf("%d",&x) != EOF)
    {
        lnode *p;
        p = (lnode *)malloc(sizeof(lnode));   //�����µĽ�� 
        p->data = x;                     //���������ֵ 
        p->next = l->next;              //�������뵽��ͷL-->|2|-->|1|-->NULL 
        l->next = p; 
    }
    return l; 
}

void PrintlistReverse5(lnode *pHead)
{
    stack<lnode *> nodes;
    lnode *pNode = pHead->next;

    while(pNode != NULL)
    {
        nodes.push(pNode);
        pNode = pNode->next;
    }

    while( !nodes.empty() )
    {
        cout << nodes.top()->data << " ";
        nodes.pop();
    }
}

int main()
{
    lnode* list;
    lnode* start;
    printf("please enter in:");
    list = LinkedListCreat();

    for(start = list->next; start != NULL; start = start->next)
        printf("%d ",start->data);

    printf("\n");

#if 0  
    list = ReverseSinglyLinkedList4(list);

    for(start = list->next; start != NULL; start = start->next)
        printf("%d ",start->data);
    printf("\n");
#endif

    PrintlistReverse5(list);

    printf("\n");

    return 0;
}

