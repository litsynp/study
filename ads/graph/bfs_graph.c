#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 30

typedef struct node_t
{
  int vertex;
  struct node_t *link;
} Node;

typedef Node *NodePointer;

typedef Node *QueuePointer;
int front, rear;

// Graph using adjacency list
NodePointer graph[MAX_VERTICES];

short int visited[MAX_VERTICES];

void bfs(int v)
{
  // v = start vertex
  // w = unvisited vertex from v's adjacency list
  NodePointer w;
  front = rear = NULL; // Init queue
  printf("%5d", v);
  addq(v);
  visited[v] = TRUE;
  while (front) {
    v = deleteq();
    for (w = graph[v]; w; w = w->link) {
      if (!visited[w->vertex]) {
        printf("%5d", w->vertex);
        addq(w->vertex);
        visited[w->vertex] = TRUE;
      }
    }
  }
}
