void selection_sort(int list[], int n)
{
  int i, j;
  int min;

  for (i = 0; i < n - 1; i++)
  {
    min = i;

    // find min from unsorted list[i+1...n]
    for (j = i + 1; i < n; j++)
    {
      if (list[j] < list[min])
      {
        min = j;
      }
    }

    swap(list[i], list[min]);
  }
}

int binary_search(int list[], int n, int value)
{
  // search from an ordered list
  int left = 0;
  int right = n - 1;
  int mid;

  while (left <= right)
  {
    mid = (left + right) / 2;
    switch (compare(list[mid], value))
    {
    case -1: // '<'
      left = mid + 1;
      break;
    case 0: // '='
      return mid;
    case 1: // '>'
      right = mid - 1;
    }
  }
  return -1;
}

int binary_search_recursive(int list[], int n, int left, int right, int value)
{
  // search from an ordered list recursively
  int mid;
  if (left <= right)
  {
    mid = (left + right) / 2;
    switch (compare(list[mid], value))
    {
    case -1: // '<'
      return binary_search_recursive(list, n, mid + 1, right, value);
    case 0: // '='
      return mid;
    case 1: // '>'
      return binary_search_recursive(list, n, left, mid - 1, value);
    }
  }
  // result not found
  return -1;
}