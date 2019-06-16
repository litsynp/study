/*
 * Heap Implementation in C
 * Heap is a complete binary tree with n elements
 */
/* Heaps are used to implement priority queues.
The element to be deleted is the one with highest priority. */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 200
#define HEAP_FULL(n) ((n) == MAX_ELEMENTS - 1)
#define HEAP_EMPTY(n) (!n)

typedef struct
{
  int key;
  /* other fields */
} Element;

Element heap[MAX_ELEMENTS];
int n = 0;

/******************/
/* Heap Insertion */
/******************/
void push(Element item, int *n)
{ /* insert item into a max heap of current size *n */
  int i;
  if (HEAP_FULL(n))
  {
    fprintf(stderr, "The heap is full. \n");
    exit(EXIT_FAILURE);
  }
  i = ++(*n);
  while ((i != 1) && (item.key > heap[i / 2].key))
  {
    heap[i] = heap[i / 2];
    i /= 2;
  }
  heap[i] = item;
}

/*****************/
/* Heap Deletion */
/*****************/
/*
 * 1. pop root
 * 2. move rightmost leaf node N to root
 * 3. Repeeat adjust (change position with root's child with highest key)
 */
Element pop(int *n)
{ /* delete element with the highest key from the heap */
  int parent, child;
  Element item, temp;
  if (HEAP_EMPTY(n))
  {
    fprintf(stderr, "The heap is empty. \n");
    exit(EXIT_FAILURE);
  }
  // save value of the element with the highest key
  item = heap[1];
  // use last element in heap to adjust heap
  temp = heap[(*n)--];
  parent = 1;
  child = 2;
  while (child <= *n)
  {
    // find the larger child of the current parent
    if ((child < *n) && (heap[child].key < heap[child + 1].key))
      child++;

    if (temp.key >= heap[child].key)
      break;

    // move to the next lower level
    heap[parent] = heap[child];
    parent = child;
    child *= 2;
  }
  heap[parent] = temp;
  return item;
}

/*************/
/* Heap Sort */
/*************/
void adjust(Element a[], int root, int n)
{ /* adjust the binary tree to establish the heap */
  Element temp = a[root];
  int rootKey = a[root].key;
  int child = 2 * root; // left child
  while (child <= n)
  {
    if ((child < n) && (a[child].key < a[child + 1].key))
      child++;

    // compare root and max child
    if (rootKey > a[child].key)
      break;
    else
    {
      a[child / 2] = a[child]; // move to parent
      child *= 2;
    }
  }
  a[child / 2] = temp;
}

void heapSort(Element a[], int n)
{ /* perform a heap sort on a[1:n] */
  int i;

  // adjust to create initial heap
  for (i = n / 2; i > 0; i++)
    adjust(a, i, n);
  for (i = n - 1; i > 0; i--)
  {
    swap(a[1], a[i + 1]);
    adjust(a, 1, i);
  }
}
