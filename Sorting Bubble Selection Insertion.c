// Sorting Algorithms
#include<stdio.h>

void bubbleSort(int arr[], int n){
    printf("\nRunning Bubble Sort...\n");
    int i = 0, j = 0, ptr;
    for(i = 0; i < n-1; i++){  // For number of passes
        for(j = 0; j < n-i-1; j++){ // Number of comparison in each pass
            if(arr[j] > arr[j+1]){
                ptr = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = ptr;
            }
        }
    }
}

void selectionSort(int arr[], int n){
    int indexofMin, ptr;
    printf("Running Selection sort...\n");
    for(int i = 0; i<n-1; i++){
        indexofMin = i;
        for(int j = i + 1; j<n; j++){
            if(arr[j]<arr[indexofMin]){
                indexofMin = j;
            }
        }
        // Swapping arr[i] and arr[indexofMin]
        ptr = arr[i];
        arr[i] = arr[indexofMin];
        arr[indexofMin] = ptr;
    }
}

void insertionSort(int arr[], int n){
    int key, j;
    printf("Running Insertion sort...\n");
    // Loop for passes
    for(int i = 0; i<=n-1; i++){ 
        key = arr[i];
        j = i - 1;
        // Loop for each pass
        while(j>=0 && arr[j]> key){
            arr[j+1] = arr[j];
            j--;            
        }
        arr[j+1] = key;
    }
}


int main(){
    int n;
    int arr[n], i;
    printf("Enter size of array: \n");
    scanf("%d", &n);
    
    for(i=0; i<n; i++){
        printf("Enter the array %dth index integers: \n", i);
        scanf("%d", &arr[i]);
    }

    printf("Displaying unsorted Array: \n");
    for(i=0; i<n; i++){
        printf("%d  ", arr[i]);
    }
    printf("\n");
    bubbleSort(arr,n);
    printf("Printing the bubble sorted  array: \n");
    for(i = 0; i<n; i++){
        printf("%d  ", arr[i]);
        
    }

    printf("\n\n");

    selectionSort(arr, n);
    printf("Printing selection sorted array: \n");
    for(i = 0; i<n; i++){
        printf("%d  ", arr[i]);
    }

    printf("\n\n");

    insertionSort(arr, n);
    printf("Printing the insertion sorted array: \n");
    for(i = 0; i<n; i++){
        printf("%d  ", arr[i]);
        
    }

    printf("\n");

    return 0;
}