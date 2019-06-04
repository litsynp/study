#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "general.h"

// insert a node into a BST
TreePointer insert(TreePointer node, int number, int rowNum);

// delete empty nodes in BST array, which are created during tournament sort
void freeEmptyNodesBSTArr(TreePointer bst[]);

// inorderly print all elements in BST
void inorderPrint(TreePointer node);

// initialize BST with given matrix data
void initBST(TreePointer bst[], int(*data)[numCol]);

// return parent node of target node in BST
TreePointer getParent(TreePointer root, TreePointer target);

// search for the max priority node from BST
Node * searchMax(TreePointer root);

// get copy of max priority node and delete the original from BST
Node * takeMax(TreePointer * root);

#endif