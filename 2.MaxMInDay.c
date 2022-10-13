#include <stdio.h>
#include <stdlib.h>

struct MM
{
    int max;
    int min;
};

struct MM maxmin(int arr[], int low, int high)
{
    struct MM mm, lmm, rmm;
    int mid;
    if (low == high)
        mm.max = mm.min = arr[low];
    else
    {
        mid = (low + high) / 2;
        lmm = maxmin(arr, low, mid);
        rmm = maxmin(arr, mid + 1, high);
        if (lmm.max > rmm.max)
            mm.max = lmm.max;
        else
            mm.max = rmm.max;
        if (lmm.min < rmm.min)
            mm.min = lmm.min;
        else
            mm.min = rmm.min;
    }
    return mm;
}

int main()
{
    int i, n;
    struct MM mm;
    printf("Enter size of array: \n");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        printf("Enter the array %dth index integers: \n", i);
        scanf("%d", &arr[i]);
    }
    mm = maxmin(arr, 0, n - 1);
    printf("Maximum element present in array: %d\n", mm.max);
    printf("Minimum element present in array: %d\n", mm.min);
    return 0;
}