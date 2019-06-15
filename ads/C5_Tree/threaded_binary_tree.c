/*
 * Threaded Binary Tree Implementation in C
 */
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// threaded tree definition
typedef ThreadedTree *ThreadedPointer;
typedef struct threaded_t
{
  short int leftThread;
  ThreadedPointer leftChild;
  char data;
  ThreadedPointer rightChild;
  short int rightThread;
} ThreadedTree;

/*********************************************/
/* Inorder Traversal of Threaded Binary Tree */
/*********************************************/
ThreadedPointer insucc(ThreadedPointer tree)
{ /* find the inorder successor of tree in a threaded binary tree */
  /* which means the smallest of ones that are bigger */
  ThreadedPointer temp;
  temp = tree->rightChild;
  if (!tree->rightThread)
    while (!temp->leftThread)
      temp = temp->leftChild;
  return temp;
}

void tinorder(ThreadedPointer tree)
{ /* traverse the threaded binary tree inorder */
  ThreadedPointer temp = tree;
  for (;;)
  {
    temp = insucc(temp);
    if (temp == tree)
      break;
    printf("%3c", temp->data);
  }
}

void insertRight(ThreadedPointer s, ThreadedPointer r)
{ /* insert r as the right child of s */
  ThreadedPointer temp;
  r->rightChild = s->rightChild;
  r->rightThread = s->rightThread;
  r->leftChild = s;
  r->leftThread = TRUE;
  s->rightChild = r;
  s->rightThread = FALSE;
  if (!r->rightThread)
  {
    temp = insucc(r);
    temp->leftChild = r;
  }
}