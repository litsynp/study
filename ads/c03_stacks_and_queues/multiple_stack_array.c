#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 100
#define MAX_STACKS 10 // max num of stacks + 1

typedef struct
{
  int key;
} element;

typedef element T;

// stack i can grow from boundary[i] + 1 to boundary[i + 1] before it's full
element memory[MEMORY_SIZE];
int top[MAX_STACKS];
int boundary[MAX_STACKS]; // bottom of the stack
int n;                    // num of stacks entered by the user

void stackFull(int i)
{
  printf("%dth stack is full!\n", i);
  exit(EXIT_FAILURE);
}

void stackEmpty(int i)
{
  printf("%dth stack is empty!\n", i);
  exit(EXIT_FAILURE);
}

void push(int i, element item)
{ // push item on i'th stack
  if (top[i] == boundary[i + 1])
  {
    stackFull(i);
  }
  memory[++top[i]] = item;
}

element pop(int i)
{ // remove top element from the i'th stack
  if (top[i] == boundary[i])
  {
    stackEmpty(i);
  }
  return memory[top[i]--];
}

int main()
{
  int j;
  top[0] = boundary[0] = -1;
  for (j = 0; j < n; j++)
  {
    top[j] = boundary[j] = (MEMORY_SIZE / n) * j;
  }
  boundary[n] = MEMORY_SIZE - 1;
}