/*
1.编写实现链表排序的一种算法。说明为什么你会选择用这样的方法？
归并排序 0（1）的辅助空间 只进行指针操作 
*/

#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;

//链表结构
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

//建立
ListNode *CreateList(int data[],int pos,int len)
{
	ListNode *list;
	if(pos>=len)
	{
		return NULL;
	}
	else
	{
		list=(ListNode *)malloc(sizeof(ListNode));
		list->m_nValue=data[pos];
		list->m_pNext=CreateList(data,pos+1,len);
		return list;
	}
}

//遍历链表中的所有结点
void PrintList(ListNode* pHead)
{
    ListNode *pNode=pHead;
    while(pNode!=NULL)
    {
        cout<<pNode->m_nValue<<" ";
        pNode=pNode->m_pNext;
    }
    cout<<endl;
}

//合并 
ListNode* merge(ListNode *a,ListNode *b) 
{
	ListNode *result=NULL;
	if(a==NULL)
		return b;
	else if(b==NULL)
		return a;
	
	//按顺序排序插入
	if(a->m_nValue<=b->m_nValue)
    {
        result=a;
        result->m_pNext=merge(a->m_pNext,b);
    }
    else  
    {
        result=b;
        result->m_pNext=merge(a,b->m_pNext);
    }
    return result; 	
}

//寻找中点 
void findMid(ListNode* source, ListNode** first, ListNode** mid)  
{  
    ListNode* fast;  
    ListNode* slow;  
  
    if(source==NULL||source->m_pNext== NULL)  
    {  
        *first=source;  
        *mid=NULL;  
    }  
    else  
    {  
        slow=source;  
        fast=source->m_pNext;  
   
        while(fast!=NULL)  
        {  
            fast=fast->m_pNext;  
            if(fast!=NULL)  
            {  
                fast=fast->m_pNext;  
                slow=slow->m_pNext;  
            }  
        }

        *first=source;
        *mid=slow->m_pNext;
        slow->m_pNext=NULL; 
    }
}

void listMergeSort(ListNode **p)
{
	ListNode *head = *p;
	ListNode *a, *b;
	
	if(head == NULL || head->m_pNext == NULL)
		return ;
	
	findMid(head, &a, &b);
	
	listMergeSort(&a);
	listMergeSort(&b);
	
	*p = merge(a,b);
}

int main()
{
    int data[]={1,7,3,5,6,2,8,4};
    
    ListNode *lis;
    lis=CreateList(data,0,sizeof(data)/sizeof(int));//创建链表
    PrintList(lis);
	listMergeSort(&lis);
	PrintList(lis);

	return 0;
}