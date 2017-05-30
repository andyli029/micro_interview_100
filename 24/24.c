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
    lnode *newList;    //新链表的头结点
    lnode *tmp;       //指向list的第一个结点，也就是要摘除的结点
 
    //参数为空或者内存分配失败则返回NULL
    if (list == NULL || (newList = (lnode *)malloc(sizeof(lnode))) == NULL)
    {
        return NULL;
    }
 
    //初始化newList
    newList->data = list->data;
    newList->next = NULL;
 
    //依次将list的第一个结点放到newList的第一个结点位置
    while (list->next != NULL)
    {
        tmp = newList->next;         //保存newList中的后续结点
        newList->next = list->next;       //将list的第一个结点放到newList中
        list->next = list->next->next;     //从list中摘除这个结点
        newList->next->next = tmp;        //恢复newList中后续结点的指针
    }
 
    //原头结点应该释放掉，并返回新头结点的指针
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

    //如果第一个节点的next没有处理，会产生死循环，所以:list->next->next = NULL
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
    l = (lnode *)malloc(sizeof(lnode));   //申请头结点空间
    l->next = NULL;                      //初始化一个空链表
     
    int x;                         //x为链表数据域中的数据
    while(scanf("%d",&x) != EOF)
    {
        lnode *p;
        p = (lnode *)malloc(sizeof(lnode));   //申请新的结点 
        p->data = x;                     //结点数据域赋值 
        p->next = l->next;              //将结点插入到表头L-->|2|-->|1|-->NULL 
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

