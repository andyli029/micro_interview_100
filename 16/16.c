//
//��ɢ:��������Լ���ӡ�ڼ��������
//
#include <stdio.h>
#include <queue>
#include <vector>
#include <vector>
#include<iostream>
using namespace std;

typedef struct BSTreeNode_ // a node in the binary search tree (BST)
{
    int m_nValue; // value of node
    struct BSTreeNode_ *m_pLeft; // left child of node
    struct BSTreeNode_ *m_pRight; // right child of node
}BSTreeNode;


BSTreeNode *treeRoot = NULL;


#if 0
void TransLevel(Node* root,int level)
{
    if(root == NULL)
        return ;
    else
    {
        if(level == 1)
           printf("%d ",root->data);
        else
        {
            TransLevel(root->left,level-1);
            TransLevel(root->right,level-1);
        }
    }
}

void TransLevel2(Node* root,int level)
{
    if(root == NULL)
        return ;
    else
    {
        int count_levels,count_nodes,level_nodes;
        Node* tmp;
        queue<Node*> queue;
        queue.EnQueue(root);
        
        count_levels=1;

        while(!queue.IsEmpty())
        {
            //����Ѿ���Ҫ��ӡ�Ĳ�
            if(count_levels == level)
                break;

            count_nodes = 0;
            //������һ��Ľڵ���
            level_nodes = queue.Size();
            
            //ÿһ�ν�һ���ڵ���ӣ�ֱ����һ�����нڵ����
            //ͬʱ����һ��Ľڵ����
            while(count_nodes < level_nodes)
            {
               tmp = queue.DeQueue();

               if(tmp->left != NULL)
                    queue.EnQueue(tmp->left);

               if(tmp->right != NULL)
                    queue.EnQueue(tmp->right);

               count_nodes++;
            }

            count_levels++;
        }
        //������ʣ�µ�Ԫ�ؼ�ΪҪ��ӡ�Ľڵ�
        PrintQueue(queue);
    }
}

void printNodeAtLevel(Node *root , int level)  
{  
    if(root == NULL || level<0)  
        return ;//ʧ��  
    if(level == 0)//Ҷ�ӽڵ�  
        cout<<root->data<<" ";  
    if(root->pLChild)  
        printNodeAtLevel(root->pLChild , level-1);  
    if(root->pRChild)  
        printNodeAtLevel(root->pRChild,level-1);  
}  

void printNodeAtLevel(Node *root , int level)  
{  
    if(root == NULL || level<0)  
        return ;//ʧ��  
    if(level == 0)//Ҷ�ӽڵ�  
        cout<<root->data<<" ";  
    if(root->pLChild)  
        printNodeAtLevel(root->pLChild , level-1);  
    if(root->pRChild)  
        printNodeAtLevel(root->pRChild,level-1);  
}

#endif

void printNodeByLevel(BSTreeNode *root)  
{  
    vector<BSTreeNode*> vec;  
    int cur , last;//�趨�ò����ʼ��ͽ�����  
    cur = 0;
    last = vec.size();

    vec.push_back(root);  

    while (cur < vec.size())
    {//ѭ����ֹ������û�и������  
        last = vec.size();

        while (cur < last)
        {//����һ��
            cout<<vec[cur]->m_nValue<<" ";

            if(vec[cur]->m_pLeft)//������
                vec.push_back(vec[cur]->m_pLeft);

            if(vec[cur]->m_pRight)//���Һ���
                vec.push_back(vec[cur]->m_pRight);

            cur++;  
        }

        cout<<endl;//�ò���ʽ������������
    } 
}  

void insert(int value)
{
	if (treeRoot == 0)
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
		while (p != 0)
		{
			q = p;
			if (p->m_nValue >= value)
				p = p->m_pLeft;
			else
				p = p->m_pRight;	
		}
		newNode = new BSTreeNode();
		newNode->m_nValue = value;
		newNode->m_pLeft = 0;
		newNode->m_pRight = 0;
		if (q->m_nValue >= value)
			q->m_pLeft = newNode;
		else
			q->m_pRight = newNode;
	}
	//printf("tag\n");
}

void createTree(int* a, int n)
{
	for (int i = 0; i < n; i++)
		insert(a[i]);
	//printf("tag\n");
}

int main()
{
	int a[7] = {10, 6, 14, 4, 8, 12, 16};
	
	createTree(a, 7);

	printNodeByLevel(treeRoot);

    return 0;
}


