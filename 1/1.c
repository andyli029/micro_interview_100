// g++ -g ./1.c

#include <stdio.h>
#include <stdlib.h>

//struct BSTreeNode_;

typedef struct BSTreeNode_
{
    int m_nValue; // value of node
    struct BSTreeNode_ *m_pLeft; // left child of node
    struct BSTreeNode_ *m_pRight; // right child of node
}BSTreeNode;


BSTreeNode* treeRoot = 0;
BSTreeNode* treeHead = 0;
BSTreeNode* pre = 0;

void convert(BSTreeNode* root)
{
    if(root != 0)
	{
		convert(root->m_pLeft);
		//printf("%d ", root->m_nValue);
		if(pre)
		{
			pre->m_pRight= root;
			root->m_pLeft = pre;
			//printf("link\n");
		}

		if(!treeHead)
			treeHead = root;

		pre = root;

		convert(root->m_pRight);
	}
}

void convert2(BSTreeNode **head, BSTreeNode **tail, BSTreeNode *root)
{
  BSTreeNode *lt = NULL; 
  BSTreeNode *rh = NULL;
  
  if (root == NULL) {
    head = NULL, tail = NULL;
    return;
  }
  
  convert2(head, &lt, root->m_pLeft);
  convert2(&rh, tail, root->m_pRight);
  
  if (lt != NULL) {
    lt->m_pRight = root;
    root->m_pLeft = lt;
  } else {
    *head = root;
  }
  
  if (rh != NULL) {
    root->m_pRight = rh;
    rh->m_pLeft = root;
  } else {
    *tail = root;
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
	convert(treeRoot);
	treeRoot = treeHead;
	visitLink(treeRoot);
#endif
	DestroyLink(treeRoot);
	//DestroyTree(root);

    return 0;
}
