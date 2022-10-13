#include<stdio.h>
#include<stdlib.h>
#define INF 9999
int** FloydWarshall(int **adjMatrix, int n)
{
    int i, j, k, **distMatrix;
    distMatrix = (int **)malloc(sizeof(int)*n);
    for(i=0; i<n; i++)
        distMatrix[i] = (int *)malloc(sizeof(int)*n);
    for(i = 0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i!=j && adjMatrix[i][j]==0)
                distMatrix[i][j] = INF;
            else
                distMatrix[i][j] = adjMatrix[i][j];
        }
    }

    for(k = 0; k<n; k++)
    {
        for(i = 0; i<n; i++)
        {
            for(j = 0; j<n; j++)
            {
                if(distMatrix[i][j]>distMatrix[i][k] + distMatrix[k][j])
                    distMatrix[i][j]=distMatrix[i][k] + distMatrix[k][j];
            }
        }
    }
    return distMatrix;
}

void print(int **distMatrix, int n)
{
    int i, j;
    for(i = 0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==j && distMatrix[i][j]<0)
            {
                printf("Distance Matrix not available, negative cycle exist");
                return;
            }
        }
    }
    for(i = 0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%d ", distMatrix[i][j]);
        printf("\n");
    }
}

int main()
{
    int i, j, n, sn, **distMatrix, **adjMatrix;
    printf("enter the number of nodes: \n");
    scanf("%d", &n);
    distMatrix = (int **)malloc(sizeof(int)*n);
    adjMatrix = (int **)malloc(sizeof(int)*n);
    for(i = 0; i<n; i++)
    {
        adjMatrix[i] = (int *)malloc(sizeof(int)*n);
        distMatrix[i] = (int *)malloc(sizeof(int)*n);
    }
    printf("Enter the adj MAtrix: \n");
    for(i = 0; i<n; i++)
    {
        for(j = 0; j<n; j++)
        {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
    distMatrix = FloydWarshall(adjMatrix, n);
    printf("teh updated distance matrix is \n");
    print(distMatrix, n);
    return 0;
}