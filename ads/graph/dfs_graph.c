#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 30

typedef struct node_t {
  int vertex;
  struct node_t * link;
} Node;

typedef Node * NodePointer;

// Graph using adjacency list
NodePointer graph[MAX_VERTICES];

short int visited[MAX_VERTICES];

void dfs(int v)
{
  // v = start vertex
  // w = unvisited node
  NodePointer w;
  visited[v] = TRUE;
  printf("%5d", v);
  for (w = graph[v]; w; w = w->link) {
    if (!visited[w->vertex])
      dfs(w->vertex);
  }
}
