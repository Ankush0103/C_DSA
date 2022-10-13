// Bubble sort user taken input of array
#include<stdio.h>

void bubble_sort(int arr[], int n){
    printf("Running Bubble Sort...\n");
    int i = 0, j = 0, ptr;
    for(i = 0; i < n; i++){
        for(j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                ptr = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = ptr;
            }
        }
    }
}

int main(){
    int n;
    int arr[100], i;
    printf("Enter size of array: \n");
    scanf("%d", &n);
    
    for(i=0; i<n; i++){
        printf("Enter the array %d integers: \n", i);
        scanf("%d", &arr[i]);
    }
    bubble_sort(arr,n);
    printf("Printing the sorted array: \n");
    for(i = 0; i<n; i++){
        printf("%d\n", arr[i]);
    }
    
    return 0;
}