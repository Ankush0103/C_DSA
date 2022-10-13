// LAB STACK OPEARTIONS
#include<stdio.h>
#include<stdlib.h>
# define MAXSIZE = 10;
struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *s, int val){
    int x;
    x = isFull(s);
    if(x==1){
        printf("Stack is full\n");
    }
    else{
        printf("Enter element to be pushed\n");
        scanf("%d", &val);
        s->top++;
        s->arr[s->top] = val;
    }
}
int pop(struct stack *s){
    int y;
    y = isEmpty(s);
    if(y==1){
        printf("Stack is Empty\n");
        return -1;
    }
    else{
        int val = s->arr[s->top];
        printf("Popped element: %d\n", s->arr[s->top]);
        s->top--;
        return val;
    }
}

void display(struct stack *s){
    int i;
    int y;
    y = isEmpty(s);
    if(y==1){
        printf("Stack is Empty\n");
    }
    else{
        printf("Status of element in stack: \n");
        for(i=s->top;i>=0;i--){
            printf("%d\n", s->arr[i]);
        }
    }
}

int main(){
    int val;
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("Stack has been created succesfully\n");

    int option;
    while (option)
    {
        printf(" 1.Stack Push\n 2.Stack Pop\n 3. Display\n 4.Exit\n");
        printf("Enter your option: \n");
        scanf("%d", &option);
        switch (option) //Writing case statemnts for five options.
        {               // Stack push
        case 1:
            push(s, val);
            break;
        // Stack Pop()
        case 2:
            pop(s);
            break;
        // Exit
        case 3:
            display(s);
            break;
        case 4: 
             exit(0);
             break;
        default: printf("Select correct choice\n");
       }
   }
   return 0;
}    

    
    
    
 