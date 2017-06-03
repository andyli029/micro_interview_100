#include <iostream>
#include <list>

using namespace std;

struct TreeNode
{
    int m_nValue;
    TreeNode* m_pLeft;
    TreeNode* m_pRight;
};

typedef TreeNode BSTreeNode;

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

///////////////////////////////////////////////////////////////////////////////
//
// If the tree with head pHead has a node pNode, return true.
// Otherwise return false.
///////////////////////////////////////////////////////////////////////////////
//
bool HasNode(TreeNode* pHead, TreeNode* pNode)
{
    if(pHead == pNode)
        return true;
 
    bool has = false;
 
    if(pHead->m_pLeft != NULL)
        has = HasNode(pHead->m_pLeft, pNode);
 
    if(!has && pHead->m_pRight != NULL)
        has = HasNode(pHead->m_pRight, pNode);
 
    return has;
}

///////////////////////////////////////////////////////////////////////////////
//
// Find the last parent of pNode1 and pNode2 in a tree with head pHead
///////////////////////////////////////////////////////////////////////////////
//
TreeNode* LastCommonParent_1(TreeNode* pHead, TreeNode* pNode1, TreeNode* 
pNode2)
{
    if(pHead == NULL || pNode1 == NULL || pNode2 == NULL)
        return NULL;
 
    // check whether left child has pNode1 and pNode2
    bool leftHasNode1 = false;
    bool leftHasNode2 = false;
    if(pHead->m_pLeft != NULL)
    {
        leftHasNode1 = HasNode(pHead->m_pLeft, pNode1);
        leftHasNode2 = HasNode(pHead->m_pLeft, pNode2);
    }
 
    if(leftHasNode1 && leftHasNode2)
    {
        if(pHead->m_pLeft == pNode1 || pHead->m_pLeft == pNode2)
            return pHead;
 
        return LastCommonParent_1(pHead->m_pLeft, pNode1, pNode2);
    }
 
    // check whether right child has pNode1 and pNode2
    bool rightHasNode1 = false;
    bool rightHasNode2 = false;
    if(pHead->m_pRight != NULL)
    {
        if(!leftHasNode1)
            rightHasNode1 = HasNode(pHead->m_pRight, pNode1);
        if(!leftHasNode2)
            rightHasNode2 = HasNode(pHead->m_pRight, pNode2);
    }
 
    if(rightHasNode1 && rightHasNode2)
    {
        if(pHead->m_pRight == pNode1 || pHead->m_pRight == pNode2)
            return pHead;
 
        return LastCommonParent_1(pHead->m_pRight, pNode1, pNode2);
    }
 
    if((leftHasNode1 && rightHasNode2)
        || (leftHasNode2 && rightHasNode1))
        return pHead;
 
    return NULL;
}

///////////////////////////////////////////////////////////////////////////////
//
// Get the path form pHead and pNode in a tree with head pHead
///////////////////////////////////////////////////////////////////////////////
//
bool GetNodePath(TreeNode* pHead, TreeNode* pNode, std::list<TreeNode*>& path)
{
    if(pHead == pNode)
        return true;

    path.push_back(pHead);

    bool found = false;

    if(pHead->m_pLeft != NULL)
        found = GetNodePath(pHead->m_pLeft, pNode, path);

    if(!found && pHead->m_pRight)
        found = GetNodePath(pHead->m_pRight, pNode, path);

    if(!found)
        path.pop_back();

    return found;
}

///////////////////////////////////////////////////////////////////////////////
//
// Get the last common Node in two lists: path1 and path2
///////////////////////////////////////////////////////////////////////////////
//
TreeNode* LastCommonNode
(
    const std::list<TreeNode*>& path1,
    const std::list<TreeNode*>& path2
)
{
    std::list<TreeNode*>::const_iterator iterator1 = path1.begin();
    std::list<TreeNode*>::const_iterator iterator2 = path2.begin();
   
    TreeNode* pLast = NULL;
 
    while(iterator1 != path1.end() && iterator2 != path2.end())
    {
        if(*iterator1 == *iterator2)
            pLast = *iterator1;
 
        iterator1++;
        iterator2++;
    }
 
    return pLast;
}

///////////////////////////////////////////////////////////////////////////////
//
// Find the last parent of pNode1 and pNode2 in a tree with head pHead
///////////////////////////////////////////////////////////////////////////////
//
TreeNode* LastCommonParent_2(TreeNode* pHead, TreeNode* pNode1, TreeNode* 
pNode2)
{
    if(pHead == NULL || pNode1 == NULL || pNode2 == NULL)
        return NULL;
 
    std::list<TreeNode*> path1;
    GetNodePath(pHead, pNode1, path1);
 
    std::list<TreeNode*> path2;
    GetNodePath(pHead, pNode2, path2);
 
    return LastCommonNode(path1, path2);
}

int main()
{
	int a[7] = {10, 6, 14, 4, 8, 12, 16};
	
	createTree(a, 7);

    return 0;
}
