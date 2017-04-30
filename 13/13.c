#include <stdlib.h>
#include <stdio.h>

typedef struct ListNode_
{
    int m_nKey;
    ListNode* next;
}ListNode;

ListNode * lastK(ListNode* head, int k)
{
  ListNode *p = head, *pk = head;

  if (k < 0) 
    printf("k < 0.\n");

  for (; k > 0; k--)
  {
    if (pk->next != NULL)  
        pk = pk->next;
    else 
        return NULL;
  }

  while (pk->next != NULL) {
    p  = p->next;
    pk = pk->next;
  }

  return p;
}