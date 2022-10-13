#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node *deleteAtFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deleteAtlast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory from nodes in the linked list is in Heap not in stack
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 8;
    third->next = fourth;

    //Terminate the list at the fourth node
    fourth->data = 1;
    fourth->next = NULL;

    int option;
    while (option != 3)
    {
        printf(" 1.insertion\n 2.Deletion\n 3.Exit\n");
        printf("Enter your option: \n");
        scanf("%d", &option);
        switch (option) // Writing case statements
        {
        case 1: //Insertion at head
            printf("Linked list before insertion\n");
            linkedListTraversal(head);
            head = insertAtFirst(head, 56); // 56 inserted at head
            printf("Linked List after insertion\n");
                linkedListTraversal(head);

            // Insertion at end
            printf("Linked list before insertion\n");
            linkedListTraversal(head);
            head = insertAtEnd(head, 66);
            printf("Linked List after insertion\n");
            linkedListTraversal(head);

            // Insertion at Index
            printf("Linked list before insertion\n");
            linkedListTraversal(head);
            head = insertAtIndex(head, 76, 1);
            printf("Linked List after insertion\n");
            linkedListTraversal(head);
            break;

        case 2: // Deletion at head
            printf("Linked list before deletion\n");
            linkedListTraversal(head);
            head = deleteFirst(head); // delete first element
            printf("Linked list after deletion\n");
            linkedListTraversal(head);

            // Deletion at Last
            printf("Linked list before deletion\n");
            linkedListTraversal(head);
            head = deleteAtLast(head); // delete first element
            printf("Linked list after deletion\n");
            linkedListTraversal(head);

            // Deletion at Index
            printf("Linked list before deletion\n");
            linkedListTraversal(head);

            head = deleteAtIndex(head, 2); // delete element at index 2
            printf("Linked list after deletion\n");
            linkedListTraversal(head);
            break;

        case 3: // Exit
            printf("Exit\n");
        }
    }
    return 0;
}
