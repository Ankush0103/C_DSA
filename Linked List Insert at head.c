#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node* ptr){
    while(ptr != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    
}

struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    // Allocate memory from nodes in the linked list is in Heap not in stack
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    
    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 416;
    third->next = fourth;

    //Terminate the list at the fourth node
    fourth->data = 66;
    fourth->next = NULL;

    linkedListTraversal(head);
    head = insertAtFirst(head, 56); // 56 inserted at head
    linkedListTraversal(head);
    
    return 0;
}