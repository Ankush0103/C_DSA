#include<stdio.h>

void display(int arr[], int n){
    // Traversal size n
    for(int i = 0; i<n; i++){
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

int insertion(int arr[], int size, int element, int capacity, int index){
    if(size>=capacity){
        return -1;
    }
    for(int i = size-1; i>=index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main(){
    // int size, element, index;
    // int arr[100];
    // printf("enter the size of array: \n");
    // scanf("%d", &size);
    // printf("enter elements of array");
    // for(int i = 0; i<size; i++){
    //     printf("index %d: \n", i);
    // }
    // printf("Enter the element & index to be inserted: \n");
    // scanf("%d %d", &element, &index);
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, element = 45, index = 1;
    display(arr, size);
    insertion(arr, size, element, 100, index);
    size += 1;
    display(arr, size);
    return 0;
}