#include<stdio.h>
int RecursiveBS(int arr[], int value, int index, int n, int low, int high){
    if(low>high){
        return -1;
    }
    int mid = (low+high)/2;
    if(value == arr[mid]){
        return mid;
    }
    else if(value < arr[mid]){
        return RecursiveBS(arr, value, index, n, low, mid-1);
    }
    else{
        return RecursiveBS(arr, value, index, n, mid+1, high);
    }

}

int main(){
    int n, value,  arr[100], i, index;
    printf("Enter total elements in array: \n");
    scanf("%d", &n);

    printf("Enter the array elements: \n");
    for(i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter element to be searched: \n");
    scanf("%d", &value);

    int low = 0, high = n-1;
    int pos = RecursiveBS(arr, value, index, n, low, high);
    if(pos!=-1){
        printf("Element %d found at index %d", value, pos);
    }
    else{
        printf("Element %d not found\n", value);
    }
    return 0;
}