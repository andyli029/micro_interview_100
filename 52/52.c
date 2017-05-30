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

int btreeDepth(BSTreeNode * &root){
    int leftDepth = 0;
    int rightDepth = 0;

    if(root == NULL){
        return 0;
    }

    leftDepth = btreeDepth(root->m_pLeft);
    rightDepth = btreeDepth(root->m_pRight);

    return leftDepth > rightDepth ? (leftDepth + 1) : (rightDepth + 1);
}

int main()
{
	int a[7] = {10, 6, 14, 4, 8, 12, 16};
	
	createTree(a, 7);
    
    printf("the depth is :%d\n", btreeDepth(treeRoot));
    
    return 0;
}

