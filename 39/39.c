
#include <iostream>
 
using namespace std;
 
struct NODE
{
    NODE *pLeft;
    NODE *pRight;
};
 
typedef struct RESULT_
{
    int nMaxDistance;
    int nMaxDepth;
}RESULT;

inline bool operator==(const RESULT& x, const RESULT& y) {
  return ((x.nMaxDistance == y.nMaxDistance) &&
          (x.nMaxDepth == y.nMaxDepth));
}

inline bool operator!=(const RESULT& x, const RESULT& y) {
  return !(x == y);
}

// good taste
RESULT GetMaximumDistance(NODE* root)
{
    //trick: nMaxDepth is -1 and then caller will plus 1 to balance it as zero.
    RESULT empty = {0, -1};//{ 0, 0};
    RESULT lhs; //left-hand side
    RESULT rhs; //right-hand side
    RESULT result = {0, 0};
    
    if (!root)
    {
        return empty;
    }

    lhs = GetMaximumDistance(root->pLeft);
    rhs = GetMaximumDistance(root->pRight);

    result.nMaxDepth = max(lhs.nMaxDepth, rhs.nMaxDepth) + 1;
    result.nMaxDistance = max(max(lhs.nMaxDistance, rhs.nMaxDistance), 
                             lhs.nMaxDepth + rhs.nMaxDepth + 2);

    return result;
}

RESULT GetMaximumDistance2(NODE* root)
{
    //trick: nMaxDepth is -1 and then caller will plus 1 to balance it as zero.
    RESULT empty = {0, 0};//{ 0, -1};
    RESULT lhs; //left-hand side
    RESULT rhs; //right-hand side
    RESULT result = {0, 0};
    
    if (!root)
    {
        return empty;
    }

    lhs = GetMaximumDistance(root->pLeft);
    rhs = GetMaximumDistance(root->pRight);
    
    if (root->pLeft || root->pRight)
    result.nMaxDepth = max(lhs.nMaxDepth, rhs.nMaxDepth) + 1;
    if (root->pLeft && root->pRight)
    result.nMaxDistance = max(max(lhs.nMaxDistance, rhs.nMaxDistance), 
                             lhs.nMaxDepth + rhs.nMaxDepth + 2);
    if ((root->pLeft && !root->pRight) || (!root->pLeft && root->pRight))
    result.nMaxDistance = max(max(lhs.nMaxDistance, rhs.nMaxDistance), 
                             lhs.nMaxDepth + rhs.nMaxDepth + 1);

    return result;
}

void Link(NODE* nodes, int parent, int left, int right)
{
    if (left != -1)
        nodes[parent].pLeft = &nodes[left]; 
 
    if (right != -1)
        nodes[parent].pRight = &nodes[right];
}

int main()
{
    // P. 241 Graph 3-12
    NODE test1[9] = { 0 };
    Link(test1, 0, 1, 2);
    Link(test1, 1, 3, 4);
    Link(test1, 2, 5, 6);
    Link(test1, 3, 7, -1);
    Link(test1, 5, -1, 8);
    cout << "test1 nMaxDistance: " << GetMaximumDistance(&test1[0]).nMaxDistance
         << ", nMaxDepth: " << GetMaximumDistance(&test1[0]).nMaxDepth << endl;
 
    // P. 242 Graph 3-13 left
    NODE test2[4] = { 0 };
    Link(test2, 0, 1, 2);
    Link(test2, 1, 3, -1);
    cout << "test2 nMaxDistance: " << GetMaximumDistance(&test2[0]).nMaxDistance
         << ", nMaxDepth: " << GetMaximumDistance(&test2[0]).nMaxDepth << endl;

    // P. 242 Graph 3-13 right
    NODE test3[9] = { 0 };
    Link(test3, 0, -1, 1);
    Link(test3, 1, 2, 3);
    Link(test3, 2, 4, -1);
    Link(test3, 3, 5, 6);
    Link(test3, 4, 7, -1);
    Link(test3, 5, -1, 8);
    cout << "test3 nMaxDistance: " << GetMaximumDistance(&test3[0]).nMaxDistance
         << ", nMaxDepth: " << GetMaximumDistance(&test3[0]).nMaxDepth << endl;
    // P. 242 Graph 3-14
    // Same as Graph 3-2, not test
 
    // P. 243 Graph 3-15
    NODE test4[9] = { 0 };
    Link(test4, 0, 1, 2);
    Link(test4, 1, 3, 4);
    Link(test4, 3, 5, 6);
    Link(test4, 5, 7, -1);
    Link(test4, 6, -1, 8);
    cout << "test4 nMaxDistance: " << GetMaximumDistance(&test4[0]).nMaxDistance
         << ", nMaxDepth: " << GetMaximumDistance(&test4[0]).nMaxDepth << endl;
    return 0;
}

