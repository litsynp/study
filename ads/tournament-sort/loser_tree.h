#ifndef LOSER_TREE_H
#define LOSER_TREE_H

#include "general.h"

// print all items in LT
void printLT(TreePointer lt[]);

// initialize all tree array items as NULL
void initTree(TreePointer tree[]);

// perform initial round of tournament sort
void initLT(TreePointer bst[], TreePointer lt[]);

// check runs to see whether the LT is empty and ready for printing
int isEmptyRuns(TreePointer lt[]);

// run tournament sort
// take elements from bst, sort the elements,
// and put in output list
void tournamentSort(TreePointer bst[], ListPointer * output);

#endif