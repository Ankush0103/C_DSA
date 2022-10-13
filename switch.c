#include<stdio.h>
#include<math.h>
int main(){
    int c=0, num, fact, n, r, sum =0, flag=1, i;
    while(c!=4){
        printf(" 1.Factorial of number\n 2.Prime number or not\n 3.Palindrome number or not\n 4. exit\n");

        printf("Enter your question: \n"); // Displays choice option to user.
        scanf("%d", &c);
        switch(c) // Writing case statements for 4 options
        {
            // Factorial
            case 1: printf("Enter an integer: \n");
            scanf("%d", &num);
            n = num;
            fact = num;
            while(num>1){
                fact = fact*(num-1);
                num = num-1;
            }
            printf("Factorial of %d is %d\n", n, fact);
            break;
            // Prime or not
            case 2: printf("Enter an integer: \n");
            scanf("%d", &num);
            for(i=2; i<=sqrt(num); i++){
                if(num%i == 0){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                printf("%d is Prime number\n", num);
            }
            else{
                printf("%d is not a Prime Number\n", num);
            }
            break;
            // PaLindrome
            case 3: printf("Enter a number: \n");
            scanf("%d", &num);
            n = num;
            while(num>0){
                r = num%10;
                sum = (sum*10) + r;
                num = num/10;
            }
            if(n==sum){
                printf("Palindrome number\n");
            }
            else{
                printf("Not a Palindrome number\n");
            }
            break;
            //  Exit 
            case 4: printf("Exit\n");
            break;
        }
        return 0;
    }