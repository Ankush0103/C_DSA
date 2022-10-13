#include <stdio.h>
 
#define MAXSIZE 7
#define TRUE 1
#define FALSE 0 
 
// structure defining stack data sructure
struct stack {
    int top;
    int array[MAXSIZE];
} s;
 
/*
Initializes the top index to -1
*/
void initialize() {
 s.top = -1;
}
 
/*
 Checks if stack is Full or not 
*/
int isFull() {   
    if(s.top >= MAXSIZE-1)
        return TRUE;
    else
        return FALSE;
}
 
/*
 Checks if stack is Empty or not
*/
int isEmpty() {
 if(s.top == -1)
     return TRUE;
 else
     return FALSE;
}
 

void push(int num) {
    if (isFull())
        printf("stack is Full...\n");
    else {
        s.array[s.top + 1] = num;
        s.top++;
    }
}
 
int pop() {
    if (isEmpty())
        printf("stack is Empty...\n");
    else {
     s.top = s.top - 1;
        return s.array[s.top+1];
    }
}
 
void printstack(){
 if(!isEmpty()){
     int temp = pop();
     printstack();
     printf(" %d ", temp);
     push( temp);
    }
}

void insertAtBottom(int item) {
    if (isEmpty()) {
        push(item);
    } else {
        int top = pop();
        insertAtBottom(item);

        push(top);
    }
}
 
void reverse() {
    if (!isEmpty()) {
        /* keep on popping top element of stack in 
        every recursive call till stack is empty  */
        int top = pop();
        reverse();
  
        /* Now, insead of inserting element back on top 
        of stack, we will insert it at the bottom of stack */
        insertAtBottom(top);
    }
}
/*
Returns the number of elements in stack
*/
int getSize(){
 return s.top+1;
}
 
int main() {
    initialize(s);
    push(14);
    push(15);
    push(16);
    push(17);
    push(18);
    printf("Original pushed elements in  stack\n");
    printstack();
    // Reversed stack
    reverse();
    printf("\nReversed stack\n");
    printstack();
    return 0;
}