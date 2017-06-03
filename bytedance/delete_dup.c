#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* deleteDuplication(ListNode* pHead){
    if(pHead==NULL) return NULL;
	vector<ListNode*> vec;
    ListNode *p=pHead->next;
    ListNode *pre=pHead;
    int repeatnum=NULL;
    while(p!=NULL){
        if(p->val!=pre->val&&repeatnum!=pre->val)
            vec.push_back(pre);
        else
            repeatnum=pre->val;
        pre=p;
        p=p->next;
    }
    if(pre->val!=repeatnum)
        vec.push_back(pre);
    int len=vec.size();
    if(len==0) return NULL;
    for(int i=0;i<len-1;i++)
        vec[i]->next=vec[i+1];
    vec[len-1]->next=NULL;
    return vec[0];
}

// my code
ListNode* deleteDuplication2(ListNode* pHead)
{
    ListNode* pre   = NULL;
    ListNode* pNode = NULL;    
    ListNode* pNext = NULL;
    ListNode* pNew  = NULL;

    bool skip = 0;

    if (!pHead) {
        return NULL;
    }

    pNode = pHead;

    while (pNode) 
    {
        while (pNode->next && pNode->val == pNode->next->val)
        {
            pNode = pNode->next;
            skip = 1;
            // to free the dup nodes
        }      

        if (skip)
        {
            pNode = pNode->next;
            skip = 0;
            if (pre)
                pre->next = pNode;
        }
        else
        {
            if (!pre)
                pNew = pNode;
            pre = pNode;
            pNode = pNode->next; 
        }
    }

    return pNew;
}

int main()
{	
    ListNode n1(2),n2(2),n3(3),n4(3),n5(4),n6(4),n7(5);

    n1.next=&n2;

    n2.next=&n3;

    n3.next=&n4;

    n4.next=&n5;

    n5.next=&n6;

    n6.next=&n7;

    ListNode *pHead=&n1;

    ListNode *pNew = NULL;

    pNew = deleteDuplication2(pHead);
    
    while (pNew)
    {
            
        cout << pNew->val << endl;
            
        pNew = pNew->next;
        
    }

    return 0;
}