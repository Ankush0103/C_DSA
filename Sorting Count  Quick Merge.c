// Sorting Day 10 QuickSort, MergeSort, CountSort
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// We first write program for merge sort.
 void merge(int arr[],  int mid, int low, int high){
     int i, j, k, n, B[100];
     i = low;
     j = mid + 1;
     k = low;

     while(i<mid+1 && j<high+1){ // while(i<=mid && j<=high)
         if(arr[i]<arr[j]){
             B[k] = arr[i];
             i++;
             k++;
         }
         else{
             B[k] = arr[j];
             j++;
             k++;
         }
     }
     while(i<=mid){ // Copying elements of left array to the sorted array.
         B[k] = arr[i];
         k++;
         i++;
     }

     while(j<=high){ // Copying elements of right array to the sorted array.
         B[k] = arr[j];
         k++;
         j++;
     }
     for(int i = low; i <= high; i++){ // Copying element from sorted to main array(B array to given array)
         arr[i] = B[i];
     }
}

void mergeSort(int arr[], int low, int high){
    int mid;
    if(low<high){
        mid = (high + low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, mid, low, high);
    }
}

// Now we write program for count sort.
int maximum(int arr[], int n){
    int max = INT_MIN;
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n){
    printf("\nRunning the count sort...\n");
    int i, j;
    // Find the maximum element in A
    int max = maximum(arr, n);
    // Creating the count array 
    int* count = (int *)malloc((max+1)*sizeof(int));
    // Initialize the array elements to 0
    for(int i = 0; i < max+1; i++){
        count[i] = 0;
    }
    // Incrementing the count index in given array
    for(i = 0; i<n;i++){
        count[arr[i]] = count[arr[i]] + 1;
    }
    i = 0; // counter for count array
    j = 0; // counter for countsorting array 

    while(i<=max){
        if(count[i]>0){
            arr[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else{
            i++;
        }
    }
}

// Now we write program for quick sort
int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int ptr;

    do{
        while(arr[i]<=pivot){
            i++;
        }

        while(arr[j]>pivot){
            j--;
        }

        if(i<j){
            ptr = arr[i];
            arr[i] = arr[j];
            arr[j] = ptr;
        }
    }while(i < j);

    // Swap arr[low] and arr[j]
    ptr = arr[low]; // We don't swap pivot & A[j] because pivot is a variable and we want to see vahnge in array so we use A[low]
    arr[low] = arr[j];
    arr[j] = ptr;
    return j;
}

void quickSort(int arr[], int low, int high)
{
    int partitionIndex; // Index of pivot afetr partition
    
    if(low<high){ // It means that one element should be in array for sorting process. If no element in array and subarray then quickSort stops,
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1); // sorting left subarray
        quickSort(arr, partitionIndex + 1, high); // sorting right subarray
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
    
    countSort(arr, n);
    printf("Printing the count sorted array\n");
    for(i = 0; i<n; i++){
        printf("%d  ", arr[i]);
        
    }
    printf("\n\n");

    int low;
    int high;
    quickSort(arr, 0, n-1);
    printf("Printing the quick sorted array\n");
    for(i = 0; i<n; i++){
        printf("%d  ", arr[i]);       
    }
    printf("\n\n");


    mergeSort(arr, 0, n-1);
    printf("Printing the merge sorted array\n");
    for(i = 0; i<n; i++){
        printf("%d  ", arr[i]);       
    }
    printf("\n\n");    
    return 0;
}