struct ComplexNode
{
    int m_nValue;
    ComplexNode* m_pNext;
    ComplexNode* m_pSibling;
};

///////////////////////////////////////////////////////////////////////////////
//
// Clone all nodes in a complex linked list with head pHead,
// and connect all nodes with m_pNext link
///////////////////////////////////////////////////////////////////////////////
//
void CloneNodes(ComplexNode* pHead)
{
    ComplexNode* pNode = pHead;
    while (pNode != NULL)
    {
        ComplexNode* pCloned = new ComplexNode();
        pCloned->m_nValue = pNode->m_nValue;
        pCloned->m_pNext = pNode->m_pNext;
        pCloned->m_pSibling = NULL;

        pNode->m_pNext = pCloned;

        pNode = pCloned->m_pNext;
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Connect sibling nodes in a complex link list
///////////////////////////////////////////////////////////////////////////////
//
void ConnectSiblingNodes(ComplexNode* pHead)
{
    ComplexNode* pNode = pHead;
    while (pNode != NULL)
    {
        ComplexNode* pCloned = pNode->m_pNext;
        if(pNode->m_pSibling != NULL)
        {
            pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
        }
 
        pNode = pCloned->m_pNext;
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Split a complex list into two:
// Reconnect nodes to get the original list, and its cloned list
///////////////////////////////////////////////////////////////////////////////
//
ComplexNode* ReconnectNodes(ComplexNode* pHead)
{
    ComplexNode* pNode = pHead;
    ComplexNode* pClonedHead = NULL;
    ComplexNode* pClonedNode = NULL;

    if (pNode != NULL)
    {
        pClonedHead = pClonedNode = pNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }

    while (pNode != NULL)
    {
        pClonedNode->m_pNext = pNode->m_pNext;
        pClonedNode = pClonedNode->m_pNext;

        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }

    return pClonedHead;
}

///////////////////////////////////////////////////////////////////////////////
//
// Clone a complex linked list with head pHead
///////////////////////////////////////////////////////////////////////////////
//
ComplexNode* Clone(ComplexNode* pHead)
{
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}
