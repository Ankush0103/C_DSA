#include<stdio.h>
#include<limits.h>

int MCM(int p[], int n)
{
    int m[n][n];
    int i, j, k, l, q;
    for(i=1; i<n; i++)
        m[i][i] = 0; // number of multiplications are 0(zero) when there is only one matrix
    // l is chain length and it varies from 2 to n.
    for(l = 2; l<n; l++)
    {
        for(i = 1; i< n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = INT_MAX; // assigning to maximum value
            for(k =i; k<j; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j])
                    m[i][j] = q; // if number of multiplication will be found less that number wiill be updated                
            }
        }
    }
    return m[1][n - 1]; // returning the final answer which is M[1][n]
}

int main(){
    int n, i;
    printf("enter the number of matrices: \n");
    scanf("%d", &n);
    n++;
    int arr[n];
    printf("enter dimensions: \n");
    for(i = 0; i<n; i++){
        printf("enter d%d :: ", i);
        scanf("%d", &arr[i]);
    }
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Minimum number of multiplicatio0ns is %d ", MCM(arr, size));
    return 0;   
}