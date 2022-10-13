#include<stdio.h>

void insertion_sort(int arr[], int n){
    int key, j;
    for(int i = 0; i<=n-1; i++){
        key = arr[i];
        j = i - 1;
        while(j>=0 && arr[j]> key){
            arr[j+1] = arr[j];
            j--;            
        }
        arr[j+1] = key;
    }
}

int main(){
    int n;
    int arr[100], i, j, key;
    printf("Enter size of array: \n");
    scanf("%d", &n);

    for(i = 0; i<n; i++){
        printf("Enter the array %d integers: \n", i);
        scanf("%d", &arr[i]);
    }
    insertion_sort(arr, n);
    printf("Printing the sorted array: \n");
    for(i = 0; i<n; i++){
        printf("%d\n", arr[i]);
    }
    return 0;
}