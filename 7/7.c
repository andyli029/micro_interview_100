
typedef struct Node_ {
  int data;
  Node *next;
}Node;

// if there is no cycle.
int isJoinedSimple(Node * h1, Node * h2) {

  while (h1->next != NULL) {
    h1 = h1->next;
  }

  while (h2->next != NULL) {
    h2 = h2->next;
  }

  return h1 == h2;
}

// if there could exist cycle
int isJoined(Node *h1, Node * h2) {
  Node* cylic1 = testCylic(h1);
  Node* cylic2 = testCylic(h2);

  if (cylic1 + cylic2==0) return isJoinedSimple(h1, h2);
  if (cylic1==0 && cylic2!=0 || cylic1!=0 &&cylic2==0) return 0;
  Node *p = cylic1;
  while (1) {
    if (p==cylic2 || p->next == cylic2) return 1;
    p=p->next->next;
    cylic1 = cylic1->next;
    if (p==cylic1) return 0;
  }
}

Node* testCylic(Node * h1) {
  Node * p1 = h1, *p2 = h1;

  while (p2!=NULL && p2->next!=NULL) {
    p1 = p1->next;
    p2 = p2->next->next;
    if (p1 == p2) {
      return p1;
    }
  }

  return NULL;
}