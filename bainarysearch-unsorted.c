#include<stdio.h>

int bubbleSort(int arr[], int size, int copy[])
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;

        int cpy = copy[j];
        copy[j] = copy[j + 1];
        copy[j + 1] = cpy;
      }
    }
  }
}

int binarySearch(int arr[], int low, int high, int key)
{

  if (high < low)
  {
    return -1;
  }
  else
  {
    int mid = (low + high) / 2;
    if (key == arr[mid])
    {
      return mid;
    }

    else if (key > arr[mid])
    {
      binarySearch(arr, mid + 1, high, key);
    }
    else
    {
      binarySearch(arr, low, mid - 1, key);
    }
  }
}

int main()
{
  int size, n;
  printf("\n Enter size of Array : ");
  scanf("%d",&size);

  int arr[size];
  int copy[size];

  printf("\n enter the elements:");
  for (int i = 0; i < size; i++)
  {
    scanf("%d",&arr[i]);
    copy[i] = i;
  }

  bubbleSort(arr, size, copy);

  printf("\n enter the elemnts to search:");
  scanf("%d",&n);

  int result = binarySearch(arr, 0, size - 1, n);

  if (result != -1)
  {
    printf("Element found in index %d",copy[result]);
  }

  else
  {
   printf("\n elements not found.");
  }
  return 0;
}