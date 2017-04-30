#include <stack>
#include <stdio.h>
using namespace std;

typedef struct BSTreeNode_ // a node in the binary search tree (BST)
{
    int m_nValue; // value of node
    struct BSTreeNode_ *m_pLeft; // left child of node
    struct BSTreeNode_ *m_pRight; // right child of node
}BSTreeNode;

BSTreeNode* treeRoot = 0;
BSTreeNode* treeHead = 0;

void swap(BSTreeNode ** l, BSTreeNode ** r) {
  BSTreeNode * p = *l;
  *l = *r;
  *r = p;
}

void mirror(BSTreeNode * root) {
  if (root == NULL) return;
  swap(&(root->m_pLeft), &(root->m_pRight));
  mirror(root->m_pLeft);
  mirror(root->m_pRight);
}

void mirrorIteratively(BSTreeNode * root) {
  if (root == NULL) return;
  stack<BSTreeNode*> buf;
  buf.push(root);
  while (!buf.empty()) {
    BSTreeNode * n = buf.top();
    swap(&(root->m_pLeft), &(root->m_pRight));
    if (root->m_pLeft != NULL) buf.push(root->m_pLeft);
    if (root->m_pRight != NULL) buf.push(root->m_pRight);
  }
}

void visitLink(BSTreeNode* head)
{
	//printf("\n");
	while(head)
	{
		printf("%d ", head->m_nValue);
		head = head->m_pRight;
	}
	printf("\n");
}

void visitLink2(BSTreeNode* head)
{
	//printf("\n");
	if(head)
	{
		printf("%d ", head->m_nValue);
		if (head->m_pLeft)
            visitLink2(head->m_pLeft);

        if (head->m_pRight)
            visitLink2(head->m_pRight);
	}
	//printf("\n");
}

void insert(int value)
{
	if(treeRoot == 0)
	{
		treeRoot = new BSTreeNode();
		treeRoot->m_nValue = value;
		treeRoot->m_pLeft = 0;
		treeRoot->m_pRight = 0;
		//printf("tag\n");
	}
	else
	{
		BSTreeNode* p = treeRoot, *q;
		BSTreeNode* newNode;
		while(p != 0)
		{
			q = p;
			if(p->m_nValue >= value)
				p = p->m_pLeft;
			else
				p = p->m_pRight;	
		}
		newNode = new BSTreeNode();
		newNode->m_nValue = value;
		newNode->m_pLeft = 0;
		newNode->m_pRight = 0;
		if(q->m_nValue >= value)
			q->m_pLeft = newNode;
		else
			q->m_pRight = newNode;
	}
	//printf("tag\n");
}

void createTree(int* a, int n)
{
	for(int i = 0; i < n; i++)
		insert(a[i]);
	//printf("tag\n");
}

void DestroyTree(BSTreeNode* root)
{
	if(root)
	{
		DestroyTree(root->m_pLeft);
		DestroyTree(root->m_pRight);
		delete root;
		root = 0;
	}
}

void DestroyLink(BSTreeNode* head)
{
	while(head)
	{
		BSTreeNode* p = head->m_pRight;
		delete head;
		head = p;
	}
}

int main()
{
	int a[7] = {10, 6, 14, 4, 8, 12, 16};
	
	createTree(a, 7);

#if 0
    BSTreeNode *head = NULL;
    BSTreeNode *tail = NULL;
    convert2(&head, &tail, treeRoot);
    visitLink(head);
#endif

#if 1
	mirror(treeRoot);
	//treeRoot = treeHead;
	visitLink2(treeRoot);
    printf("\n");
#endif
	//DestroyLink(treeRoot);
	DestroyTree(treeRoot);

    return 0;
}
