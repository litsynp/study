#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef struct
{
  int key;
} element;

typedef element T;

T queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

int isFull(T q[])
{
  return front == rear;
}

int isEmpty(T q[])
{
  return front == rear;
}

void insert(T q[], T item)
{
  rear = (rear + 1) % MAX_QUEUE_SIZE;
  if (isFull(q))
  {
    printf("Queue is full.\n");
    exit(EXIT_FAILURE);
  }

  q[rear] = item;
}

T delete (T q[])
{
  if (front == rear)
  {
    printf("Queue is empty.\n");
    exit(EXIT_FAILURE);
  }
  front = (front + 1) % MAX_QUEUE_SIZE;
  return q[front];
}
