#include<stdio.h>
int main(){
    int sum, num, pal, a;
    sum = 0;
    printf("Enter the number : \n");
    scanf("%d", &num);
    pal = num;
    while(num!=0){
        a = num%10;
        sum = sum*10 + a;
        num /= 10;
    }

    if(pal == sum){
        printf("%d is palindrome\n", pal);
    }
    else{
        printf("%d Not palindrome", pal);
    }
    return 0;
}

