/*
 * Doubly Linked List Implementation
 * ptr = ptr->llink->rlink = ptr->rlink->llink
 */
#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct Node *NodePointer;
typedef struct Node
{
  NodePointer llink;
  Element data;
  NodePointer rlink;
};

void dinsert(NodePointer node, NodePointer newNode)
{ /* insert newNode to the right of node */
  newNode->llink = node;
  newNode->rlink = node->rlink;
  node->rlink->llink = newNode;
  node->rlink = newNode;
}

void ddelete(NodePointer node, NodePointer deleted)
{ /* delete from the doubly linked list */
  if (node == deleted)
    printf("Deletion of header node not permitted.\n");
  else
  {
    deleted->llink->rlink = deleted->rlink;
    deleted->rlink->llink = deleted->llink;
    free(deleted);
  }
}