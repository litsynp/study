#include <stdio.h>
#include <stdlib.h>

typedef Node *PolyPointer;
typedef struct _node
{
  int coef;
  int expon;
  PolyPointer next;
} Node;

void attach(int coef, int expon, PolyPointer *ptr)
{
  // create a new node and attach to the node pointed by ptr
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