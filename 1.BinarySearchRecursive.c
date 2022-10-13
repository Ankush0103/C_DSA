#include <stdio.h>
#include <stdlib.h>

int RecursiveBS(int arr[], int low, int high, int key)
{
    if (high >= low)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            return RecursiveBS(arr, low, mid - 1, key);
        else
            return RecursiveBS(arr, mid + 1, high, key);
    }
    return -1;
}

int main()
{
    int i, n, key;
    printf("Enter size of array: \n");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the keys of array: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter the key to be found: \n");
    scanf("%d", &key);
    int found = RecursiveBS(arr, 0, n - 1, key);
    if (found == -1)
    {
        printf("Element not found in array\n");
    }
    else
    {
        printf("Element found at position %d\n", found + 1);
    }
    return 0;
}