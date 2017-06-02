#include <iostream>
using namespace std;

typedef struct LNode{
	int data;
	LNode *next;
}LNode, *List;

void InsertList(List &l, int data)//ͷ����ڵ�
{
	List head;
	LNode *p=new LNode;
	p->data=data;
	if(NULL==l)
		p->next=NULL;
	else
		p->next=l;
	l=p;
}

void PrintList(List l)//��ӡ����
{
	LNode *p=l;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

void DeleteNode(List &l, LNode *toBeDeleted)//ɾ������l�е�toBeDeleted�ڵ�
{
	LNode *p;
	if(!l || !toBeDeleted)
		return;

	if(l==toBeDeleted)//��ɾ���Ľڵ�ʱ��ͷ
	{
		p=l->next;
		delete toBeDeleted ;
		l=p;		
	}
	else
	{
		if(toBeDeleted->next==NULL)//��ɾ���Ľڵ�ʱ���һ���ڵ�
		{
			p=l;
			while(p->next!=toBeDeleted)
				p=p->next;
			p->next=NULL;
			delete toBeDeleted;
		}
		else//ɾ���ڵ�ʱ�м�ڵ�
		{
			p=toBeDeleted->next;
			toBeDeleted->data=p->data;
			toBeDeleted->next=p->next;
			delete p;

		}

	}

}

int main()
{
	List l=NULL;
	LNode *p;
	int n;
	InsertList(l, 3);
	InsertList(l, 7);
	InsertList(l, 12);
	InsertList(l, 56);
	InsertList(l, 33);
	InsertList(l, 78);
	InsertList(l, 20);
	InsertList(l, 89);

	PrintList(l);
	cout<<"the node to be deleted:";
	cin>>n;

	p=l;
	while(p->data!=n && p)
		p=p->next;

	if(!p)
	{
		cout<<"the node is not exist."<<endl;
		return -1;
	}
	else
		DeleteNode(l, p);

	cout<<"the list of the node deleted is:";
	PrintList(l);

    return 0;
}



