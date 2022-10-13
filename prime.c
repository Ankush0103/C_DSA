#include<stdio.h>
int main(){
    int n;
    printf("Enter the number: \n");
    scanf("%d", &n);
    if(n%2==0){
        printf("%d not prime", n);
    }
    else{
        printf("%d prime", n);
    }
    return 0;
}