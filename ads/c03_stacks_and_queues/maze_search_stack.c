#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define TRUE 1
#define FALSE 0

#define MAX_ROW 20
#define MAX_COL 20

#define EXIT_ROW 18
#define EXIT_COL 18

typedef struct
{
  int vert;
  int horiz;
} offsets;

typedef struct
{
  int row;
  int col;
  int dir;
} element;

typedef element T;
T stack[MAX_STACK_SIZE];
int top = -1;

int maze[MAX_ROW][MAX_COL];
int mark[MAX_ROW][MAX_COL];
offsets move[8]; // array of moves for each direction

int isFull(T s[])
{
  return top >= MAX_STACK_SIZE - 1;
}

void push(T s[], T item)
{
  if (isFull(s))
  {
    printf("Stack is full\n");
    exit(EXIT_FAILURE);
  }
  s[++top] = item;
}

T pop(T s[])
{
  if (top == -1)
  {
    printf("Stack is empty\n");
    exit(EXIT_FAILURE);
  }

  return s[top--];
}

void initMoves(offsets m[])
{
  m[0].vert = -1;
  m[0].horiz = 0;
  m[1].vert = -1;
  m[0].horiz = 1;
  m[2].vert = 0;
  m[0].horiz = 1;
  m[3].vert = 1;
  m[0].horiz = 1;
  m[4].vert = 1;
  m[0].horiz = 0;
  m[5].vert = 1;
  m[0].horiz = -1;
  m[6].vert = 0;
  m[0].horiz = -1;
  m[7].vert = -1;
  m[0].horiz = -1;
}

void initMark(int m[][MAX_COL])
{ // supposed to create a random maze
  int i, j;
  for (int i = 0; i < MAX_ROW; i++)
  {
    for (int j = 0; j < MAX_COL; j++)
    { // if it's a border, fill it with 1
      if (i == 0 || j == 0 || i == MAX_ROW - 1 || j == MAX_COL - 1)
      {
        m[i][j] = 1;
      }
      else
      {
        m[i][j] = 0;
      }
    }
  }
}

void path(void)
{
  // output a path through the maze if such a path exists
  int i;
  int row, col;
  int nextRow, nextCol;
  int dir;
  int found = FALSE;
  element position;

  mark[1][1] = 1; // start from (1, 1)
  top = 0;

  while (top > -1 && !found)
  {
    position = pop(stack);
    row = position.row;
    col = position.col;
    dir = position.dir;

    while (dir < 8 && !found)
    { // move in direction dir
      nextRow = row + move[dir].vert;
      nextCol = col + move[dir].horiz;
      if (nextRow == EXIT_ROW && nextCol == EXIT_COL)
      { // if found
        found = TRUE;
      }
      else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol])
      { // if legal path found
        mark[nextRow][nextCol] = 1;
        position.row = row;
        position.col = col;
        position.dir = ++dir;
        push(stack, position);

        row = nextRow;
        col = nextCol;
        dir = 0;
      }
      else
      { // if no path found for current direction
        ++dir;
      }
    } // while dir < 8 && !found
  }   // while (top > -1 && !found)

  if (found)
  { // found the exit
    printf("The path is: \n");
    printf("row col\n");
    for (i = 0; i <= top; i++)
    {
      printf("%2d%5d", stack[i].row, stack[i].col);
    }
    printf("%2d%5d\n", row, col);
    printf("%2d%5d\n", EXIT_ROW, EXIT_COL);
  }
  else // if not found
  {
    printf("The maze does not have a path\n");
  }
}