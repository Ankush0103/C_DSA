#include <stdio.h>
#include <stdlib.h>
 
struct stack
{
    int size;
    int top;
    int *arr; // integer pointer by which we dynamically aloocate memory.
};


int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}


int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}



void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot Push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}



int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int main(){
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1; // At the startting there is no element in stack so top = -1
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created succesfully\n");

    printf("Before pushing, Empty: %d\n", isEmpty(sp)); // Stack is empty at the beginning
    printf("Before pushing, Full: %d\n", isFull(sp));  // Stack is not full at the beginning
    push(sp, 36);
    push(sp, 66);
    push(sp, 76);
    push(sp, 86);
    push(sp, 96);
    push(sp, 38);
    push(sp, 69);
    push(sp, 75);
    push(sp, 47);
    push(sp, 56); // --->pushed 10 values
    push(sp, 46); // Stack oveflow since the size of stack is 10.
    printf("After pushing, Empty: %d\n", isEmpty(sp)); // Stack is not empty after pop operation
    printf("After pushing, Full: %d\n", isFull(sp));  // Stack is  full after 10 operations because size is 10 but if operation was not done 10 times it was not full.
    
    printf("Popped %d from stack\n", pop(sp)); // --> Last In First Out (LIFO)
    printf("Popped %d from stack\n", pop(sp)); // --> Last In First Out (LIFO)
    printf("Popped %d from stack\n", pop(sp)); // --> Last In First Out (LIFO)
    return 0;
}