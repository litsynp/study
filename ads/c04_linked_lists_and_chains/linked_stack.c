#include <stdio.h>
#include <stdlib.h>
#define MAX_STACKS 10

typedef int T;
typedef Node *StackPointer;
typedef struct _node
{
  T data;
  StackPointer next;
} Node;

// top[i] should be NULL if i'th stack is empty
StackPointer top[MAX_STACKS];

StackPointer stackInit(T firstData)
{
  StackPointer first = (Node *)malloc(sizeof(Node));
  first->data = firstData;
  first->next = NULL;
  return first;
}

void push(int i, T data)
{ // push data on i'th stack
  StackPointer newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = top[i];
  top[i] = newNode;
}

T pop(int i)
{
  StackPointer temp = top[i];
  T item;
  if (!temp)
  {
    printf("Stack is empty!\n");
    exit(EXIT_FAILURE);
  }

  item = temp->data;
  top[i] = temp->next;
  free(temp);
  return item;
}