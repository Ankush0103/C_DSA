// LAB STACK Delete mid OPEARTIONS
#include<stdio.h>
#include<stdlib.h>
# define MAXSIZE = 10;
struct stack{
    int size;
    int top;
    int *arr;
};

struct stack *create(unsigned size)
{
	struct stack *s = (struct stack *)malloc(sizeof(struct stack));

	s->size = size;

	s->top = -1;

	s->arr = (int *)malloc(s->size * sizeof(int));

	return s;
}

int isEmpty(struct stack *s)
{k
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
        s->top--;
        return val;
    }
}

int peek(struct stack *s)

{

	if (isEmpty(s))

		return INT_MIN;

	return s->arr[s->top];

}

void deletemid(struct stack *s, int n,int curr)
{

    if (isEmpty(s) || curr == n)

	    return;

    int a =peek(s);

    pop(s);

    deletemid(s, n, curr+1);

    if (curr != n/2)

	    push(s,a);

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
    struct stack *s = create(100);

	printf("Enter no of elements you want to store initially\n");

	int n;

	scanf("%d",&n);

	printf("Enter the elements\n");

	int a[n];

	for(int i=0;i<n;i++)

    {
        scanf("%d",&a[i]);
        push(s,a[i]);
    }
    printf("Stack has been created succesfully\n");
    int val;
    int curr;
    int y;
    int option;
    while (1)
    {
        printf(" 1.Stack Push\n 2.Stack Pop\n 3.DeleteMid\n 4.Display\n 5.Exit\n");
        printf("Enter your option: \n");
        scanf("%d", &option);
        switch (option) //Writing case statemnts for five options.
        {               // Stack push
        case 1:
            printf("Enter element to be pushed\n");
            scanf("%d", &val);
            push(s, val);
            printf("Pushed element: %d\n", val);
            break;
        
        case 2:
            y = pop(s);
            printf("Popped element: %d\n", val);
            break;
        case 3:
            deletemid(s, n, curr);
            printf("Middle element deleted succefully\n");
            break;
        case 4:
            display(s);
            break;
        case 5: 
             exit(0);
        default: printf("Select correct option\n");
       }
   }
   return 0;
}