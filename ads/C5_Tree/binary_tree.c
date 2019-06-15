/*
 * Binary Tree Implementaion in C
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 50
#define MAX_QUEUE_SIZE 50

typedef int Element;

typedef Node *TreePointer;

typedef struct node_t
{
  Element data;
  Node *left;
  Node *right;
} Node;

/*************************/
/* Binary Tree Traversal */
/*************************/
void inorder(TreePointer ptr)
{ /* inorder tree traversal */
  if (ptr)
  {
    inorder(ptr->left);
    printf("%d", ptr->data);
    inorder(ptr->right);
  }
}

void iterInorder(TreePointer node)
{
  /* iterative inorder traversal using STACK*/
  int top = -1; // initialize stack
  TreePointer stack[MAX_STACK_SIZE];
  for (;;)
  {
    for (; node; node = node->left)
      push(node); // add to stack
    node = pop(); // delete from stack
    if (!node)
      break; // empty stack
    printf("%d", node->data);
    node = node->right;
  }
}

void levelOrder(TreePointer ptr)
{ /* Level-order traversal of a binary tree using QUEUE */
  int rear;
  int front = rear = 0;
  TreePointer queue[MAX_QUEUE_SIZE];
  if (!ptr)
    return; // empty tree
  addq(ptr);
  for (;;)
  {
    ptr = deleteq();
    if (ptr)
    {
      printf("%d", ptr->data);
      if (ptr->left)
        addq(ptr->left);
      if (ptr->right)
        addq(ptr->right);
    }
    else
      break;
  }
}

/*************************************/
/* Additional Binary Tree Operations */
/*************************************/
TreePointer copy(TreePointer original)
{
  /* this function returns a TreePointer to an exact copy of the original tree */
  TreePointer temp;
  if (original)
  {
    temp = malloc(sizeof(*temp));
    temp->left = copy(original->left);
    temp->right = copy(original->right);
    temp->data = original->data;
    return temp; // breakpoint
  }
  return NULL;
}

int equal(TreePointer first, TreePointer second)
{ /* FALSE if the binary trees first and second are not equal
    Otherwise it returns TRUE */
  return ( // TRUE if
      (!first && !second) || // empty trees -> true
      (first && second && // addresses are equal
       (first->data == second->data) && // data are euqal
       equal(first->left, second->left) && // left subtrees are equal
       equal(first->right, second->right))); // right subtrees are equal
}

void insert(TreePointer root)
{
}
