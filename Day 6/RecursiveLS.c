#include<stdio.h>
int RecursiveLS(int arr[], int value, int index, int n){
    int pos = 0;
    if(index>=n){
        return 0;
    }
    else if(arr[index] == value){
        pos = index + 1;
        return pos;
    }
    else{
        return RecursiveLS(arr, value, index+1, n);
    }
    return pos;
}

int main(){
    int n, value, pos, m = 0, arr[100], i;
    printf("Enter total elements in array: \n");
    scanf("%d", &n);

    printf("Enter the array elements: \n");
    for(i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter element to be searched: \n");
    scanf("%d", &value);

    pos = RecursiveLS(arr, value, 0, n);
    if(pos!=0){
        printf("Element %d found at pos %d\n", value, pos);
    }
    else{
        printf("Element %d not found\n", value);
    } 
    return 0;
}