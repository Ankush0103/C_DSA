#include<stdio.h>
#include<stdlib.h>

struct Node *f = NULL; // f = front element
struct Node *r = NULL; // r = rear element i.e last element

struct Node{
    int data;
    struct Node *next;
};



void linkedListTraversal(struct Node *ptr){
    printf("Printing the elements of this linked list\n");
    while(ptr!=NULL){
        printf("Elements: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val){
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue is Full\n");
    } 
    else{
        n->data = val;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next = n;
            r=n;
        }
    }
}

int dequeue(){
    int val = -1;
    struct Node *ptr = f; 
    if(f==NULL){
        printf("Queue is Empty\n");
    } 
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}



int main(){
    printf("Dequeuing element %d\n", dequeue());
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    printf("Again printing element in linked list\n");
    linkedListTraversal(f);
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    return 0;
}