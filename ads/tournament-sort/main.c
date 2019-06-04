#include "general.h"
#include "binary_search_tree.h"
#include "loser_tree.h"

// matrix of data to sort
// * numRow, numCol are defined in "general.h"
int matrix[numRow][numCol] = {
    { 5,90,5,9,80,80,7,90,7,90 },
    { 100,30,30,51,160,160,160,51,160,59 },
    { 500,100,7000,100,900,600,100,100,650,100 },
    { 1000,300,41,300,41,41,41,900,900,950 },
    { 90,81,81,95,81,83,81,90,81,90 }
};

int main(void)
{
    TreePointer bst[numRow]; // binary search tree (BST)
    ListPointer output = NULL; // output list ordered according to priority
    
    // 1. initialize binary search tree
    initBST(bst, matrix);

    // 2. perform tournament sort using loser tree and push sorted items to output list
    tournamentSort(bst, &output);

    // 3. print items in output list
    printList(output);

    // 4. free empty nodes in BST created during tournament sort
    freeEmptyNodesBSTArr(bst);

    // 5. delete every item in output list
    deleteList(output);

    return 0;
}