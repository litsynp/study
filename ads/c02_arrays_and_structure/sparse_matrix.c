#define MAX_TERMS 101
#define MAX_COL 20

typedef struct
{
  int col;
  int row;
  int value;
} term;

term m[MAX_TERMS];

term fastTranspose(term a[], term b[])
{
  int rowTerms[MAX_COL]; // count[]
  int startingPos[MAX_COL];
  int i, j;
  int numCols = a[0].col;
  int numTerms = a[0].value; // non-zero elements

  b[0].row = numCols;
  b[0].col = a[0].row;
  b[0].value = numTerms;

  if (numTerms > 0) // if non-zero matrix
  {
    // initialize as 0
    for (i = 0; i < numCols; i++)
    {
      rowTerms[i] = 0;
    }

    // Step 1. for each column of A, count non-zero elements
    for (i = 1; i <= numTerms; i++)
    {
      rowTerms[a[i].col]++;
    }

    // Step 2. for each row of B, compute the start position in B
    startingPos[0] = 1; // start from 1
    for (i = 1; i < numCols; i++)
    {
      startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
    }

    // Step 3. for each value in A, move it to B
    for (i = 1; i <= numTerms; i++)
    {
      j = startingPos[a[i].col]++;
      b[j].row = a[i].col;
      b[j].col = a[j].row;
      b[j].value = a[i].value;
    }
  }
}
