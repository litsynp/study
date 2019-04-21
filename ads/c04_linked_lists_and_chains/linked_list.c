#include <stdio.h>
#include <stdlib.h>

typedef int T;
typedef Node *ListPointer;
typedef struct _node
{
  T data;
  ListPointer next;
} Node;

ListPointer listInit(T firstData)
{
  ListPointer first = (Node *)malloc(sizeof(Node));
  first->data = firstData;
  first->next = NULL;
  return first;
}

void insert(ListPointer *first, ListPointer x, T data)
{ // insert after node x
  ListPointer newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;

  if (*first)
  {
    newNode->next = x->next;
    x->next = newNode;
  }
  else
  { // if no item in the list
    newNode->next = NULL;
    *first = newNode;
  }
}

T delete (ListPointer *first, ListPointer x)
{ // delete x from the list
  ListPointer temp = *first;
  int data;

  if (temp == x)
  { // first one is the x
    data = x->data;
    *first = NULL;
    free(x);
    return data;
  }
  while (temp->next)
  {
    if (temp->next == x)
    { // found the x
      data = x->data;
      temp->next = x->next;
      free(x);
      return data;
    }

    temp = temp->next;
  }

  printf("Node not found\n");
  return NULL;
}

void printList(ListPointer first)
{
  printf("The list contains: ");
  while (first)
  {
    printf("%4d", first->data);
    first = first->next;
  }
  printf("\n");
}