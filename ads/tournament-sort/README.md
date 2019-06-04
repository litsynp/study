Tournament Sort Using Loser Tree
==
Used Data Structures
--
* **Binary Search Tree** (Linked Implementation)
* **Loser Tree** (Array Implementation)
* **Linked List**

Node Priority Definition
--
1. Compare COUNTs of two nodes
2. If counts are equal, compare 

Procedures
--
1. Get input from 2-dimensional array matrix[][]
2. Push input to each BST of corresponding row, according to its KEY and increase the COUNT every time the key is the same.
4. Initialize loser tree by **running the first round**, by taking the **node with maximum priority** first for each leaf nodes.
5. The loser is saved in the lt[i/2], and the winner is saved in winners[i/2].
5. Compare until getting the winner node at lt[0] and **push the champion to output list**.
6. **Take a new node** from row from which **the winner node** is.
7. **compare the new node with its parent**, and the parent and the parent of its parent, ... and so on.
8. Again, **push lt[0]** to output list.
9. Run remaining rounds of tournament sort by **repeating step 5, 6, 7, 8 until BSTs are empty**.
10. Print output list.
11. Free all memory.

Possible Improvements
--
* Woudln't it be better to sort input data according to its COUNT?
* Wouldn't it be better to not DELETE the node from BST and instead get the REFERENCE to the node?
