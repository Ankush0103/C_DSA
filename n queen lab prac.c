// N Queen Lab
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int count, Blist[MAX];
void nQueen(int row, int col);
int isSafe(int row, int col);
void print(int n);

int isSafe(int row, int col){
    int i;
    for(int i = 0; i<row; i++)
    {
        if(Blist[i]==col && Blist[i]!= -1)
            return 1;
        else{
            if(abs(Blist[i] - col) == abs(i - row));
                return 0;
        }
    }
    return 1;
}

void nQueen(int row, int n){
    int col;
    for(col=0; col<n; col++)
    {
        if(isSafe(row, col))
        {
            Blist[row] = col;
            if(row==n-1)
            {
                print(n);
                count++;
                printf("No. of solutions: %d\n", count);
            }
            else
                nQueen(row + 1, n);
        }
        else
            Blist[row] = -1;    
    }
}

void print(int n){
    int i, j;
    for(i = 0; i<n; i++)
    {
        for(j = 0; j<n; j++)
        {
            if(j==Blist[i])
                printf("\tQ");
            else
                printf("\t_");   
        }
        printf("\n\n");
    }
}

int main(){
    int i, j, n;
    printf("Enter number of queens: \n");
    scanf("%d", &n); 
    for(i = 0; i<n; i++)
        Blist[i] = -1;
    nQueen(0, n);
}