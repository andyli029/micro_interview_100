#include <stdio.h>
#include <stdlib.h>

typedef struct MinStackElement_ {
  int data;
  int min;
}MinStackElement;

typedef struct MinStack_ {
  MinStackElement *data;
  int size;
  int top;
}MinStack;

MinStack MinStackInit(int maxSize) {
  MinStack stack;

  stack.size = maxSize;
  stack.top = 0;
  stack.data = (MinStackElement*) malloc(sizeof(MinStackElement)*maxSize);

  return stack;
}

void MinStackFree(MinStack *stack) {
  free(stack->data);
}

void MinStackPush(MinStack *stack, int d) {
  if (stack->top == stack->size) printf("out of stack space.\n");
  MinStackElement* p = &stack->data[stack->top];
  p->data = d;
  p->min = ((stack->top == 0) ? d : stack->data[stack->top - 1].min);

  if (p->min > d) p->min = d;

  stack->top ++;
}

int MinStackPop(MinStack *stack) {
  if (stack->top == 0) error("stack is empty!\n");
  return stack->data[--stack->top].data;
}

int MinStackMin(MinStack *stack) {
  if (stack->top == 0) error("stack is empty!\n");
  return stack->data[stack->top - 1].min;
}

int main()
{
    int min;
    MinStack min_stack;

    min_stack = MinStackInit(3);
    MinStackPush(&min_stack, 7);
    MinStackPush(&min_stack, 5);
    MinStackPush(&min_stack, 9);

    min = MinStackMin(&min_stack);
    printf("the min is %d.\n", min);
    
    return 0;
}

