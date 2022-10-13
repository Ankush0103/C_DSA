// DFS using adjacency matrix
// We dont have to implemnent stack since it already taken by the function.
#include<stdio.h>
#include<stdlib.h>

int visited[7] = {0,0,0,0,0,0,0};
    int A[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };

void DFS(int i){
    int j;
    printf("%d ", i);
    visited[i] = 1;
    for(int j = 0; j<7; j++){
        if(A[i][j] == 1 && !visited[j]){
            DFS(j);
        }
    }
}
int main(){
    //DFS Implementation
    int n;
    printf("Enter the value of root node n: \n");
    scanf("%d", &n);
    DFS(n);
    return 0;
}