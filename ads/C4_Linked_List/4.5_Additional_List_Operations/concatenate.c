/*
 * concatenating singly linked lists
 */
#include <stdio.h>

typedef struct listNode *ListPointer;
typedef struct listNode
{
  char data;
  ListPointer link;
};

ListPointer concatenate(ListPointer ptr1, ListPointer ptr2)
{ /* produce a new list that contains the list
      ptr1 followed by the list ptr2. The list
      pointed to by ptr1 is changed permanently */
  ListPointer temp;
  // check for empty lists
  if (!ptr1)
    return ptr2;
  if (!ptr2)
    return ptr1;

  // neither list is empty, find end of first list
  for (temp = ptr1; temp->link; temp = temp->link)
    ;

  // link end of first to start of second
  temp->link = ptr2;
  return ptr1;
}