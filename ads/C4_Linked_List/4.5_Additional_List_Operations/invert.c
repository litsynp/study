/*
 * inverting a singly linked list
 */
#include <stdio.h>

typedef struct listNode *ListPointer;
typedef struct listNode
{
  char data;
  ListPointer link;
};

ListPointer invert(ListPointer lead)
{ /* invert the list pointed to by lead */
  ListPointer middle, trail;
  middle = NULL;
  while (lead)
  {
    trail = middle;
    middle = lead;
    lead = lead->link;
    middle->link = trail;
  }
  return middle;
}