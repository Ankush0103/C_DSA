#include <stdio.h>
#define N 5   // N = maxsize
int stack1[5], stack2[5]; // Declaration of two stacks
int top1 = -1, top2 = -1;
int count = 0;
// inserting the elements in stack1.
void push1(int data)
{
    if (top1 == N - 1)
    {
        printf("\n Stack is overflow...");
    }
    else
    {
        top1++;
        stack1[top1] = data; // pushing the data into stack1
    }
}
// Removing the elements from the stack1.
int pop1()
{
    if (top1 == -1)
    {
        printf("\nStack is empty..");
    }
    else
    {
        int a = stack1[top1]; // Assigning the topmost value of stack1 to 'a' variable.
        top1--;               // decrementing the value of top1.
        return a;
    }
}

void push2(int x)
{
    if (top2 == N - 1)
    {
        printf("\nStack is full..");
    }
    else
    {
        top2++;
        stack2[top2] = x; // assigning the 'x' value to the Stack2
    }
}
// Removing the elements from the Stack2
int pop2()
{
    int element = stack2[top2]; // assigning the topmost value to element
    top2--;                     // decrement the value of top2
    return element;
}

void enqueue(int x)
{
    push1(x);
    count++;
}

void dequeue()
{
    if ((top1 == -1) && (top2 == -1))
    {
        printf("\nQueue is empty");
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            int element = pop1();
            push2(element);
        }
        int b = pop2();
        printf("\nThe dequeued element is %d", b);
        printf("\n");
        count--;
        for (int i = 0; i < count; i++)
        {
            int a = pop2();
            push1(a);
        }
    }
}

void display()
{
    for (int i = 0; i <= top1; i++)
    {
        printf("Status of element in queue: %d\n", stack1[i]);
    }
}

void main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    enqueue(4);
    display();
}