// the same as 24
#include <iostream>
#include <stack>
using namespace std;

void PrintlistReverse(listNode *pHead)
{
    stack<ListNode *> nodes;
    ListNode *pNode = pHead;

    while(pNode != NULL)
    {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    while( !nodes.empty() )
    {
        nodes.top();
        cout << pNode->m_pNext << " ";
        nodes.pop();
    }
}
