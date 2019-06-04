#include "loser_tree.h"
#include "binary_search_tree.h"

void printLT(TreePointer lt[])
{
    int i;
    printf("Printing elements in LT\n");
    for (i = 1; i < LT_LEN; i++) {
        if (lt[i] != NULL) {
            printf("%dth item in LT is ", i);
            printNode(lt[i]);
            printf("\n");
        }
        else {
            printf("%dth item in LT is EMPTY\n", i);
        }
    }
    printf("Printing elements in LT complete\n");
}

void initTree(TreePointer tree[])
{
    int i;
    // set all items in tree array as NULL
    for (i = 1; i < LT_LEN; i++) {
        tree[i] = NULL;
    }
}


void initLT(TreePointer bst[], TreePointer lt[])
{
    int i, j;
    Node * winners[numRow];

    for (i = numRow, j = 0; i < 2 * numRow; i++, j++) {
        // get max priority nodes on LT leaf nodes
        lt[i] = takeMax(&(bst[j]));
    }

    // calculate winner and loser of initial round
    for (i = LT_LEN - 1; i > 1; i -= 2) {
        // parent of leaf nodes
        if (i > numRow) {
            lt[i / 2] = getLoser(lt[i], lt[i - 1]);
            winners[i / 2] = getWinner(lt[i], lt[i - 1]);
        }
        // parent of non-leaf nodes
        else if (i < numRow) {
            lt[i / 2] = getLoser(winners[i], winners[i - 1]);
            winners[i / 2] = getWinner(winners[i], winners[i - 1]);
        }
        // case where i == numRow
        else {
            lt[i / 2] = getLoser(lt[i], winners[i - 1]);
            winners[i / 2] = getWinner(lt[i], winners[i - 1]);
        }
        // final node
        if (i / 2 == 1) {
            lt[0] = getWinner(winners[i], winners[i - 1]); // take output
        }
    }
}


int isEmptyRuns(TreePointer lt[])
{
    int i;
    int emptyCnt = 0; // count of empty runs

    // check leaf nodes of LT
    for (i = numRow; i < numRow * 2; i++) {
        if (lt[i]->item.count == 0) {
            // if a run is empty, the count of its root is 0
            emptyCnt++;
        }
    }
    // if at least one run is empty, return 1
    return emptyCnt == numRow ? 1 : 0;
}

void tournamentSort(TreePointer bst[], ListPointer * output)
{
    int i;
    TreePointer lt[LT_LEN]; // LT (loser tree)
    int winnerRow; // row where the winner is from
    int winnerIdx; // index of winner in LT
    Node * temp; // temp node for winner
    Node * parent; // temp node for parent

    initLT(bst, lt); // perform initial round

    // while there is at least one BST left
    while (!isEmptyRuns(lt)) {
        push(output, lt[0]); // push winner
        winnerRow = lt[0]->item.row;
        winnerIdx = winnerRow + numRow;
        lt[winnerIdx] = takeMax(&(bst[winnerRow]));
        temp = lt[winnerIdx];

        for (i = winnerIdx; i > 1; i = i / 2) {
            parent = lt[i / 2];
            lt[i / 2] = getLoser(temp, lt[i / 2]);
            temp = getWinner(temp, parent);
        }
        lt[0] = temp; // get the winner
    }
}