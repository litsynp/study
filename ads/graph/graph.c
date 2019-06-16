#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

#define TRUE 1
#define FALSE 0

typedef Node *NodePointer;
typedef struct node_t
{
  int vertex;
  struct node_t *link;
} Node;

// adjacent lists (graph)
NodePointer graph[MAX_VERTICES];

// visited flags for dfs & bfs
short int visited[MAX_VERTICES];

// queue definition used by bfs
typedef struct queue_t *QueuePointer;
typedef struct queue_t
{
  int vertex;
  QueuePointer link;
} Queue;
QueuePointer front, rear;
/*
//queue functions
void addq(int);
int deleteq();
*/

/**********************/
/* Depth First Search */
/**********************/
void dfs(int v)
{
  NodePointer w;
  printf("%5d", v);
  visited[v] = TRUE;
  for (w = graph[v]; w; w = w->link)
    if (!visited[w->vertex])
      dfs(w->vertex);
}

/************************/
/* Breadth First Search */
/************************/
void bfs(int v)
{
  NodePointer w;
  front = rear = NULL;
  printf("%5d", v);
  addq(v);
  visited[v] = TRUE;
  while (front)
  {
    v = deleteq();
    for (w = graph[v]; w; w = w->link)
    {
      printf("%5d", w->vertex);
      addq(w->vertex);
      visited[w->vertex] = TRUE;
    }
  }
}

/***********************/
/* Connected Components*/
/***********************/
void connected(void)
{
  int i;
  for (i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      dfs(i);
      printf("\n");
    }
  }
}

/***********************************/
/* Creating Min Cost Spannig Trees */
/***********************************/
// Spanning Tree: any tree that consists soley of
//  edges in G and that includes all the vertices in G
/*
 * Three methods that create a min cost spanning tree
 *  using greedy method
 * 1. Kruskal's Algorithm
 * 2. Prim's Algorithm
 * 3. Sollin's Algorithm
*/

void kruskal()
{
  // n = num of vertices
  E = { .. } // edges in original graph
  T =  {}; // spanning tree
  while (T cointains less than n - 1 edges && E is not empty) {
    choose a least cost edge (v, w) from E;
    delete (v, w) from E;
    if ((v, w) does not create a cycle in T)
      add (v, w) to T;
    else
      discard (v, w);
  }
  if (T contains fewer than n-1 edges)
    printf("No spanning tree\n");
}

void prim()
{
  T = {}; // edges in min spanning tree
  TV = {0}; // vertex that has been visited, start w/ vertex 0 and no edges
  while (T contains fewer than n-1 edges) {
    let (u, v) be a least cost edge ('u' from TV, 'v' not from TV)
    if (there is no such edge)
      break;
    add v to TV;
    add (u, v) to T;
  }
  if (T contains fewer than n-1 edges)
    printf("No spanning tree\n");
}


/************************************************/
/* Single Src/All Dest: Non-negative Edge Costs */
/************************************************/
void shortestPath(int v, int cost[][MAX_VERTICES],
                  int distance[], int n, short int found[])
{
/*
 * distance[i]: the shortest path from v to i
 * found[i]: 0 if shortest path from i hasn't been found,
 *            1 if it has
 * cost[][]: adjacency matrix
 *    - cost[a][b] would mean distance from a to b
 */
  int i, u, w;
  for (i = 0; i < n; i++) {
    found[i] = FALSE;
    distance[i] = cost[v][i];
  }
  found[v] = TRUE;
  distance[v] = 0;
  for (i = 0; i < n-2; i++) {
    u = choose(distance, n, found);
    found[u] = TRUE;
    for (w = 0; w < n; w++)
      if (!found[w])
        if (distance[u] + cost[u][w] < distance[w])
          distance[w] = distance[u] + cost[u][w];
  }
}

int choose(int distance[], int n, short int found[])
{ /* choosing the least cost edge */
  int i, min, minpos;
  min = INT_MAX;
  minpos = -1;
  for (i = 0; i < n; i++) {
    if ((distance[i] < min) && !found[i]) {
      min = distance[i];
      minpos = i;
    }
  }
  return minpos;
}
