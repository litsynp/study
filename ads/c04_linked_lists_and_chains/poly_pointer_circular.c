#include <stdio.h>
#include <stdlib.h>

typedef Node *PolyPointer;
typedef struct _node
{
  int coef;
  int expon;
  PolyPointer next;
} Node;

PolyPointer p;

PolyPointer avail; // points to the first node in the list of freed nodes - initially NULL

PolyPointer getNode(void)
{ // provide a node for use from avail, if available
  // otherwise, allocate a new memory for node
  PolyPointer node;
  if (avail)
  {
    node = avail;
    avail = avail->next;
  }
  else
  {
    node = (PolyPointer)malloc(sizeof(Node));
  }
  return node;
}

void retNode(PolyPointer node)
{ // return (or insert) a node to the available list
  node->next = avail;
  avail = node;
}

void cerase(PolyPointer *ptr)
{ // erase the circular list pointed to by ptr
  PolyPointer temp;
  if (*ptr)
  {
    temp = (*ptr)->next;
    (*ptr)->next = avail;
    avail = temp;
    *ptr = NULL;
  }
}

void attach(int coef, int expon, PolyPointer *ptr)
{ // create a new node and attach to the node pointed by ptr
  PolyPointer temp = (PolyPointer)malloc(sizeof(Node));
  temp->coef = coef;
  temp->expon = expon;
  (*ptr)->next = temp;
  *ptr = temp;
}

PolyPointer padd(PolyPointer a, PolyPointer b)
{
  PolyPointer c;    // output polynomial
  PolyPointer rear; // rear points to the last element in c
  PolyPointer temp;
  int sum;

  rear = (PolyPointer)malloc(sizeof(Node));
  c = rear;

  while (a && b)
  {
    switch (compare(a->expon, b->expon))
    {
    case -1:
      attach(b->coef, b->expon, &rear);
      b = b->next;
      break;
    case 0:
      sum = a->coef + b->coef;
      if (sum)
      {
        attach(sum, a->expon, &rear);
      }
      a = a->next;
      b = b->next;
      break;
    case 1:
      attach(a->coef, a->expon, &rear);
      a = a->next;
    }
  }

  // add remaining terms of a and b into c
  for (; a; a = a->next)
  {
    attach(a->coef, a->expon, &rear);
  }
  for (; b; b = b->next)
  {
    attach(b->coef, b->expon, &rear);
  }
  rear->link = NULL;

  // delete extra initial node
  temp = c;
  c = c->link;
  free(temp);
  return c;
}

void erase(PolyPointer *ptr)
{
  // erase a polynomial from memory
  PolyPointer temp;
  while (*ptr)
  {
    temp = *ptr;
    *ptr = (*ptr)->link;
    free(temp);
  }
}

int main()
{

  avail = NULL;
}