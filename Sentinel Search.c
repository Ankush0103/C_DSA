//Sentinel Search
#include<stdio.h>

#define max 100

int main(){
    int a[max],n,i,key;

    printf("Enter Size of Array:");

    scanf("%d",&n);

    printf("Enter Array Element:");

    for(i=0; i<n; i++)

        scanf("%d",&a[i]);

    printf("Array:\n");

    for(i=0; i<n; i++)

        printf("%d\n",a[i]);

    printf("Enter Key To Search:");

    scanf("%d",&key);

    sentinelsearch(a,n,key);
}

sentinelsearch(int a[max],int n,int key){
    int i,last;
    last=a[n-1];
    a[n-1]=key;
    i=0;
    while(a[i]!=key)
       i++;
    a[n-1]=last;

    if(a[i]==key)
    {
        printf("Search found at location %d", i+1);
    }
    else
    {
        printf("Not found");
    }
}