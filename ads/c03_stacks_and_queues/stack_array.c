#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct
{
  int key;
} element;

typedef element T;

T stack[MAX_STACK_SIZE];
int top = -1;

int isFull(T s[])
{
  return top >= MAX_STACK_SIZE - 1;
}

void push(T s[], T item)
{
  if (isFull(s))
  {
    printf("Stack is full\n");
    exit(EXIT_FAILURE);
  }
  s[++top] = item;
}

T pop(T s[])
{
  if (top == -1)
  {
    printf("Stack is empty\n");
    exit(EXIT_FAILURE);
  }

  return s[top--];
}