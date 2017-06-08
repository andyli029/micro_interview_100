#include <iostream>
using namespace std;

struct TreeNode 
{
    int m_nValue;
    TreeNode *m_pLeft;
    TreeNode *m_pRight;
};

//把一个有序整数数组放到二叉树
void RecurCreateTree(int *p, int length, TreeNode *&pHead)
{
    if (length > 0)
    {
        pHead = new TreeNode;
        int mid = length / 2;
        pHead->m_nValue = p[mid];
        pHead->m_pLeft = NULL;
        pHead->m_pRight = NULL;
        RecurCreateTree(p, mid, pHead->m_pLeft);
        RecurCreateTree(p + mid + 1, length - mid - 1, pHead->m_pRight);;
    }
    else
    {
        pHead = NULL;
    }
}

//把一个有序整数数组放到二叉树
void RecurCreateTree_(int *p, int length, TreeNode **ppHead)
{
    TreeNode *pHead = NULL;
    
    if (length > 0)
    {
        pHead = new TreeNode;
        int mid = length / 2;
        pHead->m_nValue = p[mid];
        pHead->m_pLeft  = NULL;
        pHead->m_pRight = NULL;
        RecurCreateTree_(p, mid, &pHead->m_pLeft);
        RecurCreateTree_(p + mid + 1, length - mid - 1, &pHead->m_pRight);
    }
    else
    {
        pHead = NULL;
    }

    *ppHead = pHead;
}

//中序递归遍历
void MidRecurTraversal(TreeNode* pHead)
{
    if (NULL != pHead)
    {
        MidRecurTraversal(pHead->m_pLeft);
        cout << pHead->m_nValue << "  ";
        MidRecurTraversal(pHead->m_pRight);
    }
}

//前序递归遍历
void PreRecurTraversal(TreeNode* pHead)
{
    if (NULL != pHead)
    {
        cout << pHead->m_nValue << "  ";
        PreRecurTraversal(pHead->m_pLeft);
        PreRecurTraversal(pHead->m_pRight);
    }
}

int main()
{
    //int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ,11, 12};
    int arr[] = {1, 2, 3, 4, 5};
    
    TreeNode *pHead = NULL;
    RecurCreateTree_(arr, sizeof(arr)/sizeof(arr[0]), &pHead);
    //MidRecurTraversal(pHead);
    PreRecurTraversal(pHead);
    cout << endl;
    
    return 0;
}
