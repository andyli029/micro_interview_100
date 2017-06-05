/*
1.��дʵ�����������һ���㷨��˵��Ϊʲô���ѡ���������ķ�����
�鲢���� 0��1���ĸ����ռ� ֻ����ָ����� 
*/

#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;

//����ṹ
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

//����
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

//���������е����н��
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

//�ϲ� 
ListNode* merge(ListNode *a,ListNode *b) 
{
	ListNode *result=NULL;
	if(a==NULL)
		return b;
	else if(b==NULL)
		return a;
	
	//��˳���������
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

//Ѱ���е� 
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
    lis=CreateList(data,0,sizeof(data)/sizeof(int));//��������
    PrintList(lis);
	listMergeSort(&lis);
	PrintList(lis);

	return 0;
}