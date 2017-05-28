
/*
42.���޸� append  �����������������ʵ�֣�
�����ǽ�������Ĳ�����1->2->3  �� 2->3->5  ��Ϊ 1->2->3->5
����ֻ���������������޸�������������ݡ�
*/ 
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

struct node{
	
	int data;
	struct node *next;
};

//�����ǽ���ĺϲ� 
node *merge(node *h1, node *h2) 
{
	node *head;

	if (h1 == NULL) return h2;
	if (h2 == NULL) return h1;

	if (h1->data > h2->data) //˭��ͷ 
	{
		head = h2;
		h2 = h2->next;
	} 
	else 
	{
		head = h1;
		h1 = h1->next;
	}
	
	node *current = head;
	
	while(h1 || h2) 
	{
		if(h1 != NULL && h2 != NULL && h1->data == h2->data)//ȥ����ͬ�� 
		{
			h1 = h1->next;
			continue;
		}

		//h1�գ�����h2��Ϊ�գ�����ֵС��h1 
		if(h1 == NULL || (h2 != NULL && h2->data < h1->data))
		{
			current->next = h2;
			h2 = h2->next; 
			current = current->next;
		}
		else if (h2 == NULL ||(h1 != NULL && h1->data < h2->data))
		{
			current->next = h1;
			h1 = h1->next;
			current = current->next;
		}
	}

	current->next = NULL;

	return head;
}


void insertNode(node* &head, int data)//����ǰ 
{
	node *x = new node;
	x->data = data;
	x->next = head;
	head = x;
}

int main(){
	int a[] = {1, 2, 4, 9, 10, 11};
	int b[] = {2, 3, 5, 6, 7, 8};
	int i;
	node *h1 = NULL, *h2 = NULL;
	
	//���� 
	for (i = 5; i >= 0; i--)//���Ų���� 
		insertNode(h1, a[i]);
	for (i = 5; i >= 0; i--)
		insertNode(h2, b[i]);	
	
	node *result = NULL;
	
	result = merge(h1, h2);
	//result=h1;
	while (result != NULL)// 1 2 3 4 5 6 7 8
	{
		printf("%d ",result->data);
		result = result->next; 
	}

    printf("\n");

	return 0;
}


