#include <iostream>
using namespace std;

struct ListNode{
  int m_nKey;
  ListNode * m_pNext;
};

void createCrossList(int * arr1, int len1, int * arr2, int len2, ListNode ** 
head1, ListNode ** head2){
  if(arr1 == NULL || len1 < 1 || arr2 == NULL || len2 < 1)  return;
  for(int i = 0; i < len1; ++i){
    ListNode * newnode = new ListNode;
    newnode->m_nKey = arr1[i];
    newnode->m_pNext = NULL;
    if(*head1 == NULL){
      *head1 = newnode;
    }
    else{
      newnode->m_pNext = *head1;
      *head1 = newnode;
    }
  }
  for(int i = 0; i<len2; ++i){
    ListNode * newnode = new ListNode;
    newnode->m_nKey = arr2[i];
    newnode->m_pNext = NULL;
    if(*head2 == NULL){
      *head2 = newnode;
    }
    else{
      newnode->m_pNext = *head2;
      *head2 = newnode;
    }
  }
  ListNode * cur1 = *head1;
  ListNode * cur1pre = *head1;
  while(cur1 != NULL){
    ListNode * cur2 = *head2;
    int flag = 0;
    while(cur2 != NULL){
      if(cur1->m_nKey == cur2->m_nKey){
        cur1pre->m_pNext = cur2;
        flag = 1;
        break;
      }
      else{
        cur2 = cur2->m_pNext;
      }
    }
    if(flag == 1){
      break;
    }
    cur1pre = cur1;
    cur1 = cur1->m_pNext;
  }
}

int commonNodeInCrossList(ListNode ** head1, ListNode ** head2){
  if(*head1 == NULL || *head2 == NULL){
    return -100;
  }
  int list1len = 0;
  int list2len = 0;
  ListNode * cur1 = *head1;
  ListNode * cur2 = *head2;
  while(cur1 != NULL){
    list1len++;
    cur1 = cur1->m_pNext;
  }
  while(cur2 != NULL){
    list2len++;
    cur2 = cur2->m_pNext;
  }
  //std::cout<<list1len<<std::endl;
  //std::cout<<list2len<<std::endl;
  int lendiff = 0;
  if(list1len > list2len){
    lendiff = list1len - list2len;
    cur1 = *head1;
    cur2 = *head2;
  }
  else{
    lendiff = list2len - list1len;
    cur1 = *head2;
    cur2 = *head1;
  }
  int i = 1;
  while(i <= lendiff){
    cur1 = cur1->m_pNext;
    i++;
  }
  while(cur1 != NULL && cur2 != NULL){
    if(cur1->m_nKey == cur2->m_nKey){
      return cur1->m_nKey;
    }
    cur1 = cur1->m_pNext;
    cur2 = cur2->m_pNext;
  }
}

void listTraverse(ListNode ** head){
  if(*head == NULL) return;
  ListNode * cur = *head;
  while(cur != NULL){
    std::cout<<cur->m_nKey<<" ";
    cur = cur->m_pNext;
  }
  std::cout<<std::endl;
}

int main(int argc, char ** argv){
  int arr1[] = {9,8,7,6,4,2,0,-2};
  int len1 = sizeof(arr1)/sizeof(int);
  int arr2[] = {9,8,7,5,3,1};
  int len2 = sizeof(arr2)/sizeof(int);
  ListNode * head1 = NULL;
  ListNode * head2 = NULL;

  createCrossList(arr1, len1, arr2, len2, &head1, &head2);
  listTraverse(&head1);
  int commonNum = commonNodeInCrossList(&head1, &head2);
  std::cout<<"num : "<<commonNum<<std::endl;

  //system("pause");
  return 0;
}

