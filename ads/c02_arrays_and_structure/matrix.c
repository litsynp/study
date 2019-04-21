#define MAX_SIZE 10

void printMatix(int matrix[][MAX_SIZE], int rows, int cols)
{
  int i, j;
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < cols; j++)
    {
      printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

void transpose(int matrix[][MAX_SIZE])
{
  int i, j;
  for (i = 0; i < MAX_SIZE - 1; i++)
  {
    for (j = i + 1; j < MAX_SIZE; j++)
    {
      swap(matrix[i][j], matrix[j][i]);
    }
  }
}