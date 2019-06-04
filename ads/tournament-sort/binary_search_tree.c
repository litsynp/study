#include "binary_search_tree.h"

TreePointer insert(TreePointer node, int number, int rowNum)
{
    if (node == NULL) {
        // if the node is EMPTY, create a node and save the number
        node = createNode(number, 1, rowNum, NULL, NULL);
        return node;
    }
    if (node->item.key > number) {
        // if key is smaller, insert in left subtree
        node->left = insert(node->left, number, rowNum);
    }
    else if (node->item.key < number) {
        // if key is bigger, insert in right subtree
        node->right = insert(node->right, number, rowNum);
    }
    else {
        // if the keys are equal, increase the count by 1
        (node->item.count)++;
    }
    return node;
}

void freeEmptyNodesBSTArr(TreePointer bst[]) 
{
    int i;
    for (i = 0; i < numRow; i++) {
        // free empty nodes in roots of each BST
        free(bst[i]);
    }
}

void inorderPrint(TreePointer node)
{
    if (node == NULL) {
        // If the node is EMPTY, finish printing nodes
        return;
    }
    inorderPrint(node->left);
    printlnNode(node);
    inorderPrint(node->right);
}

void initBST(TreePointer bst[], int(*data)[numCol])
{
    int i, j;

    // create one BST per row
    for (i = 0; i < numRow; i++) {
        // initialize BST as NULL
        bst[i] = NULL;
        for (j = 0; j < numCol; j++) {
            // for each BST, insert data from corresponding row 
            bst[i] = insert(bst[i], data[i][j], i);
        }
    }
}

TreePointer getParent(TreePointer root, TreePointer target)
{
    TreePointer parent = NULL;
    
    // tree is empty
    if (root == NULL || target == NULL) {
        return NULL;
    }

    // parent is found
    if (root->left == target || root->right == target || root == target) {
        return root;
    }
    else {
        // search for parent in left subtree
        parent = getParent(root->left, target);
        if (parent != NULL) {
            return parent;
        }
        // search for parent in right subtree
        parent = getParent(root->right, target);
        if (parent != NULL) {
            return parent;
        }
    }
    return NULL;
}

Node * searchMax(TreePointer root)
{
    Node * leftMax = NULL;
    Node * rightMax = NULL;
    Node * max;

    if (root == NULL) {
        return root;
    }
    // Recursively search for the max priority node in left and right subtree 
    leftMax = searchMax(root->left);
    rightMax = searchMax(root->right);

    // there are max nodes in both left and right subtree
    if (leftMax != NULL && rightMax != NULL) {
        max = getWinner(leftMax, rightMax);
    }
    // no node in right subtree
    else if (leftMax != NULL) {
        max = leftMax;
    }
    // no node in left subtree
    else if (rightMax != NULL) {
        max = rightMax;
    }
    // both left and right subtree are empty
    else {
        max = root;
    }

    // get final winner from left, right subtree and root
    max = getWinner(root, max);
    return max;
}

Node * takeMax(TreePointer * root)
{
    TreePointer target = searchMax(*root); // max priority node
    TreePointer parent = getParent(*root, target); // parent of max node
    TreePointer temp = NULL; // temp node to describe empty BST
    TreePointer min; // node with minimum key in right subtree of max node
    TreePointer minParent; // parent of minimum key node
    TreePointer result = copyNode(target); // copy of max node

    // Delete target from BST
    // Case 1. Target has no child
    if (target->left == NULL && target->right == NULL) {
        if (target == parent->left) {
            parent->left = NULL;
        }
        else if (target == parent->right) {
            parent->right = NULL;
        }
        else {
            // create an empty node to indicate that the tree is now empty
            temp = createNode(0, 0, 0, NULL, NULL);
            *root = temp;
        }
        free(target);
    }
    // Case 2. Target has one child
    else if (target->left != NULL && target->right == NULL) {
        if (target == parent) {
            *root = target->left;
        }
        if (target == parent->left) {
            // if target is left child of parent
            parent->left = target->left;
        }
        else {
            // if target is right child of parent
            parent->right = target->left;
        }
        free(target);
    }
    else if (target->left == NULL && target->right != NULL) {
        if (target == parent) {
            *root = target->right;
        }
        if (target == parent->left) {
            // if target is left child of parent
            parent->left = target->right;
        }
        else {
            // if target is right child of parent
            parent->right = target->right;
        }
        free(target);
    }
    // Case 3. Target has two children
    else {
        min = target->right;
        minParent = target;

        // get the node with minimum key in right subtree of target
        while (min->left != NULL) {
            minParent = min;
            min = min->left;
        }

        // replace target with minimum key node
        target->item.key = min->item.key;
        target->item.count = min->item.count;
        target->item.row = min->item.row;

        if (minParent->left == min) {
            minParent->left = min->right;
        }
        else {
            minParent->right = min->right;
        }
        free(min);
    }
    return result;
}