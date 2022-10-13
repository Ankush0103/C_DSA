//Selection Sort algo user inout array
#include<stdio.h>

void selection_sort(int arr[], int n){
    int indexofMin, ptr;
    printf("Running selction sort...\n");
    for(int i = 0; i<n-1; i++){
        indexofMin = i;
        for(int j = i + 1; j<n; j++){
            if(arr[j]<arr[indexofMin]){
                indexofMin = j;
            }
        }
        ptr = arr[i];
        arr[i] = arr[indexofMin];
        arr[indexofMin] = ptr;
    }
}

int main(){
    int arr[100], i, j, n;
    printf("Enter size of array: \n");
    scanf("%d", &n);

    for(i = 0; i<n; i++){
        printf("Enter the array %d integers: \n", i);
        scanf("%d", &arr[i]);
    }
    selection_sort(arr, n);
    printf("Printing sorted array: \n");
    for(i = 0; i<n; i++){
        printf("%d\n", arr[i]);
    }
    return 0;
}