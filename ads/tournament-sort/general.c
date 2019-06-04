#include "general.h"

Node * createNode(int key, int count, int row, Node * left, Node * right)
{
    Node * temp = (Node *)malloc(sizeof(Node));
    temp->item.key = key;
    temp->item.count = count;
    temp->item.row = row;
    temp->left = left;
    temp->right = right;
    return temp;
}

void printNode(Node * node)
{
    if (node != NULL) {
        printf("(%4d, %4d, %4d)", node->item.row, node->item.key, node->item.count);
    }
    else {
        printf("Node is empty");
    }
}

void printlnNode(Node * node)
{
    if (node != NULL) {
        printNode(node);
        printf("\n");
    }
    else {
        printf("Node is empty\n");
    }
}

Node * copyNode(Node * node)
{
    Node * copy;
    copy = createNode(node->item.key, node->item.count, node->item.row, node->left, node->right);
    return copy;
}

Node * getWinner(Node * a, Node * b)
{
    // 1. compare COUNTs of two nodes
    if (a->item.count < b->item.count)
    {
        return b;
    }
    else if (a->item.count > b->item.count)
    {
        return a;
    }
    else {
        // 2. if counts are equal,compare KEYs
        if (a->item.key < b->item.key)
        {
            return b;
        }
        else if (a->item.key > b->item.key)
        {
            return a;
        }
        else {
            // 3. If keys are equal, compare ROW numbers
            return a->item.row < b->item.row ? b : a;
        }
    }
}

Node * getLoser(Node * a, Node * b)
{
    // 1. compare COUNTs of two nodes
    if (a->item.count < b->item.count)
    {
        return a;
    }
    else if (a->item.count > b->item.count)
    {
        return b;
    }
    else {
        // 2. if counts are equal,compare KEYs
        if (a->item.key < b->item.key)
        {
            return a;
        }
        else if (a->item.key > b->item.key)
        {
            return b;
        }
        else {
            // 3. if keys are equal, compare ROW numbers
            return a->item.row < b->item.row ? a : b;
        }
    }
}

void push(ListPointer * head, Node * node)
{
    ListPointer temp = *head;
    ListPointer newNode = (ListPointer)malloc(sizeof(ListNode));
    newNode->node = node;
    newNode->next = NULL;
    
    if (*head == NULL) {
        // if list is empty
        *head = newNode;
        return;
    }
    while (temp->next) {
        // reach the end of list
        temp = temp->next;
    }
    // insert at the end
    temp->next = newNode;
}

void deleteList(ListPointer head)
{
    ListPointer temp = head;
    while (head != NULL) {
        temp = head;
        head = head->next;

        // free element in node
        free(temp->node);
        // free node
        free(temp);
    }
}

void printList(ListPointer head) {
    ListPointer cur = head;

    printf("Nodes in output list:\n");
    while (cur != NULL) {
        printlnNode(cur->node);
        cur = cur->next;
    }
}
