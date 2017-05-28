#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include<string.h>
#include<stack> 
using namespace std;

typedef struct node
{
    int data;
    struct node *lchild,*rchild;
}BinTree;

typedef struct node1
{
    BinTree *btnode;
    bool isFirst;
}BTNode;

BinTree* treeRoot = NULL;

#if 0
void creatBinTree(char *s, BinTree *&root)  //创建二叉树，s为形如A(B,C(D,E))形式的字符串 
{
    int i;
    bool isRight=false;
    stack<BinTree*> s1;          //存放结点 
    stack<char> s2;              //存放分隔符
    BinTree *p,*temp;
    root->data=s[0];
    root->lchild=NULL;
    root->rchild=NULL;
    s1.push(root);
    i=1;
    while(i<strlen(s))
    {
        if(s[i]=='(')
        {
            s2.push(s[i]);
            isRight=false;
        }    
        else if(s[i]==',')    
        {
            isRight=true;
        }
        else if(s[i]==')')
        {
            s1.pop();
            s2.pop();
        }
        else if(isalpha(s[i]))
        {
            p=(BinTree *)malloc(sizeof(BinTree));
            p->data=s[i];
            p->lchild=NULL;
            p->rchild=NULL;
            temp=s1.top();
            if(isRight==true)    
            {
                temp->rchild=p;
                cout<<temp->data<<"的右孩子是"<<s[i]<<endl;
            }
            else
            {
                temp->lchild=p;
                cout<<temp->data<<"的左孩子是"<<s[i]<<endl;
            }
            if(s[i+1]=='(')
                s1.push(p);
        }
        i++;
    }    
}

void display(BinTree *root)        //显示树形结构 
{
    if(root!=NULL)
    {
        cout<<root->data;
        if(root->lchild!=NULL)
        {
            cout<<'(';
            display(root->lchild);
        }
        if(root->rchild!=NULL)
        {
            cout<<',';
            display(root->rchild);
            cout<<')';
        }
    }
}
#endif

void insert(int value)
{
	if(treeRoot == 0)
	{
		treeRoot = new BinTree();
		treeRoot->data = value;
		treeRoot->lchild = 0;
		treeRoot->rchild = 0;
		//printf("tag\n");
	}
	else
	{
		BinTree* p = treeRoot, *q;
		BinTree* newNode;
		while(p != 0)
		{
			q = p;
			if(p->data >= value)
				p = p->lchild;
			else
				p = p->rchild;	
		}
		newNode = new BinTree();
		newNode->data = value;
		newNode->lchild = 0;
		newNode->rchild = 0;
		if(q->data >= value)
			q->lchild = newNode;
		else
			q->rchild = newNode;
	}
	//printf("tag\n");
}

void createTree(int* a, int n)
{
	for(int i = 0; i < n; i++)
		insert(a[i]);
	//printf("tag\n");
}

void preOrder1(BinTree *root)     //递归前序遍历 
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preOrder1(root->lchild);
        preOrder1(root->rchild);
    }
}

void preOrder2(BinTree *root)     //非递归前序遍历 
{
    stack<BinTree*> s;
    BinTree *p=root;
    while(p!=NULL||!s.empty())
    {
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            s.push(p);
            p=p->lchild;
        }
        if(!s.empty())
        {
            p=s.top();
            s.pop();
            p=p->rchild;
        }
    }
}

void inOrder1(BinTree *root)      //递归中序遍历
{
    if(root!=NULL)
    {
        inOrder1(root->lchild);
        cout<<root->data<<" ";
        inOrder1(root->rchild);
    }
} 

void inOrder2(BinTree *root)      //非递归中序遍历
{
    stack<BinTree*> s;
    BinTree *p=root;
    while(p!=NULL||!s.empty())
    {
        while(p!=NULL)
        {
            s.push(p);
            p=p->lchild;
        }
        if(!s.empty())
        {
            p=s.top();
            cout<<p->data<<" ";
            s.pop();
            p=p->rchild;
        }
    }    
} 

void postOrder1(BinTree *root)    //递归后序遍历
{
    if(root!=NULL)
    {
        postOrder1(root->lchild);
        postOrder1(root->rchild);
        cout<<root->data<<" ";
    }    
} 

void postOrder2(BinTree *root)    //非递归后序遍历
{
    stack<BTNode*> s;
    BinTree *p=root;
    BTNode *temp;
    while(p!=NULL||!s.empty())
    {
        //沿左子树一直往下搜索，直至出现没有左子树的结点
        while(p!=NULL)
        {
            BTNode *btn=(BTNode *)malloc(sizeof(BTNode));
            btn->btnode=p;
            btn->isFirst=true;
            s.push(btn);
            p=p->lchild;
        }
        if(!s.empty())
        {
            temp=s.top();
            s.pop();
            if(temp->isFirst==true)     //表示是第一次出现在栈顶 
             {
                temp->isFirst=false;
                s.push(temp);
                p=temp->btnode->rchild;    
            }
            else                        //第二次出现在栈顶 
             {
                cout<<temp->btnode->data<<" ";
                p=NULL;
            }
        }
    }    
}

void postOrder3(BinTree *root)     //非递归后序遍历
{
    stack<BinTree*> s;
    BinTree *cur;                      //当前结点 
    BinTree *pre=NULL;                 //前一次访问的结点 
    s.push(root);
    while(!s.empty())
    {
        cur=s.top();
        if((cur->lchild==NULL&&cur->rchild==NULL)||
           (pre!=NULL&&(pre==cur->lchild||pre==cur->rchild)))
        {
            cout<<cur->data<<" ";  
              //如果当前结点没有孩子结点或者孩子节点都已被访问过 
            s.pop();
            pre=cur; 
        }
        else
        {
            if(cur->rchild!=NULL)
                s.push(cur->rchild);
            if(cur->lchild!=NULL)    
                s.push(cur->lchild);
        }
    }    
}

int main(int argc, char *argv[])
{
    char s[100];

    //while(scanf("%s", s)==1)
    {
        //BinTree *root=(BinTree *)malloc(sizeof(BinTree));
        //creatBinTree(s,root);
    	int a[7] = {10, 6, 14, 4, 8, 12, 16};
    	
    	createTree(a, 7);
        BinTree *root = treeRoot;
        //display(root);
        cout<<endl;
        preOrder2(root);
        cout<<endl; 
        inOrder2(root);
        cout<<endl;
        postOrder2(root);
        cout<<endl;
        postOrder3(root);
        cout<<endl;
    }

    return 0;
}

