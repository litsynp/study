# Graph

## Traversal
### Depth First Search (DFS)
1. Start with start vertex **v**.
2. Select an unvisited vertex **w** from **v**'s adjacency list and carry out a dfs on w.
3. For every vertex visited, mark it as **visited**

### Breadth First Search (BFS)
1. Start with start vertex **v**.
2. Visit each of the vertices on v's adjacency list and place the vertex in a queue.
3. When done with an adjacency list, remove a vertex from queue and proceed examining each of the verticies on its adjacency list.
4. Unvisited vertices are visited and then placed on the queue; visited vertices are ignored.
5. When the queue is empty, bfs is finished.
