struct Node {
   Node* pParent;
   Node* pLeft;
   Node* pRight;
};

Node* GetNext(const Node *pNode)
{
    Node* tmp  = NULL;
    Node* tmp1 = NULL; 

    if (!pNode->pRight) 
    {
        tmp1 = pNode;

        while (tmp1->pParent)
        {
            if (tmp1->pParent->pLeft == tmp1)
            {
                return tmp1->pParent;
            }
            tmp1 = tmp1->pParent;        
        }
        
        return NULL;
    }
    else
    {
        tmp = pNode->pRight;
        
        while (tmp)
        {
            if (!tmp->pLeft)
            {
                return tmp;
            }
            tmp = tmp->pLeft;
        }
     }
}