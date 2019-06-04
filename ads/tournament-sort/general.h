#ifndef GENERAL_H
#define GENERAL_H

#include <stdio.h>
#include <stdlib.h>

#define numRow 5 /* power of 2 (2, 4, 8, 16, ...)가 아닌 값으로 설정 */
#define numCol 10

#define LT_LEN numRow * 2 // length of loser tree

// data item type for node
typedef struct element_t {
    int key;   // number in a row
    int count; // frequency of number appearing in a row
    int row; // row number the key is from
} Element;

// type for BST and LT
typedef struct node_t
{
    Element item;
    struct node_t *left;
    struct node_t *right;
} Node;

typedef Node * TreePointer;

// type for output linked list
typedef struct list_node_t {
    Node * node;
    struct list_node_t * next;
} ListNode;

typedef struct list_node_t * ListPointer;


// create a new node with given information
Node * createNode(int key, int count, int row, Node * left, Node * right);

// print a node's element information to STDOUT
void printNode(Node * node);

// print a node's element information on one line to STDOUT
void printlnNode(Node * node);

// create a copy of node
Node * copyNode(Node * node);

/* 
* getWinner() and getLoser() functions
* decides the winner or the loser of two nodes according to priority
* Priority to decide the winner:
* 1. count
* 2. key
* 3. row number
*/
// return node with higher priority
Node * getWinner(Node * a, Node * b);

// return node with lower priority
Node * getLoser(Node * a, Node * b);

// push an item at the end of a linked list
void push(ListPointer * head, Node * node);

// delete every item in linked list
void deleteList(ListPointer head);

// print all items in linked list
void printList(ListPointer head);

#endif
