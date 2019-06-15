/*
 * Binary Search Implementation in C
 */
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int iType;

typedef struct element_t
{
  int key;
  iType item;
} Element;

typedef struct node_t
{
  Element data;
  Node *left;
  Node *right;
} Node;

typedef Node *TreePointer;

int modifiedSearch(TreePointer root, int k)
{ /* NULL if tree is empty or key k exists;
    otherwise, return the place to insert node with key k */
  TreePointer temp = root;
  while (root)
  {
    temp = root;
    if (k < root->data.key)
      root = root->left;
    else if (k > root->data.key)
      root = root->right;
    else
      return NULL;
  }
  return temp;
}

void insert(TreePointer *node, int k, iType theItem)
{ /* if k is in the tree pointed at by node, do nothing;
  otherwise add a new node with data = (k, theItem) */
  TreePointer ptr, temp = modifiedSearch(*node, k);
  if (temp || !(*node))
  { // k is not in the tree
    ptr = (TreePointer)malloc(sizeof(*ptr));
    ptr->data.key = k;
    ptr->left = ptr->right = NULL;
    if (*node) // insert as child of temp (tree is not empty)
    {
      if (k < temp->data.key)
        temp->left = ptr;
      else
        temp->right = ptr;
    }
    else // tree is empty
      *node = ptr;
  }
}

Element delete (TreePointer root, int k)
{
  Element temp;
  TreePointer current, target, previous;
  current = root;
  target = NULL;

  if (!current)
    return;
  while (1)
  {
    if (k > current->data.key)
    {
      if (current->right == NULL)
        break;
      previous = current;
      current = current->right;
    }
    else
    {
      if (k == current->data.key)
        target = current;
      if (current->left == NULL)
        break;
      previous = current;
      current = current->left;
    }
  }

  if (target == NULL)
    return;
  else
  {
    // root
    if (previous == NULL)
    {
      temp = current->data;
      free(current);
      root = NULL;
      return temp;
    }
    else
    {
      temp = target->data;
      target->data.key = current->data.key;

      if (previous->left == current)
        previous->left = current->left;
      else
        previous->right = current->right;

      free(current);
      return temp;
    }
  }
}
