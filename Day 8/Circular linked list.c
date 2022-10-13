// Circular linked list
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *start;

void createList(int n)
{
    int i, data;
    struct Node *prevNode, *newNode;

    if (n >= 1)
    {

        start = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data of Node 1: ");
        scanf("%d", &data);

        start->data = data;
        start->next = NULL;

        prevNode = start;

        /*
         * Creates and links rest of the n-1Nodes
         */
        for (i = 2; i <= n; i++)
        {
            newNode = (struct Node *)malloc(sizeof(struct Node));

            printf("Enter data of Node %d: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->next = NULL;

            // Link the previousNode with newly createdNode
            prevNode->next = newNode;

            // Move the previousNode astart
            prevNode = newNode;
        }

        // Link the lastNode with firstNode
        prevNode->next = start;

        printf("\nCIRCULAR LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

void display()
{
    struct Node *ptr;
    ptr = start;
    if (start == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        printf("Status of element in Circular Linked List: \n");

        while (ptr->next != start)
        {

            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n", ptr->data);
    }
}

void insertAtFront()
{
    struct Node *ptr, *trav;
    int data;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter the Node to be inserted: \n");
        scanf("%d", &data);
        ptr->data = data;
        if (start == NULL)
        {
            start = ptr;
            ptr->next = start;
        }
        else
        {
            trav = start;
            while (trav->next != start)
                trav = trav->next;
            ptr->next = start;
            trav->next = ptr;
            start = ptr;
        }
    }
    printf("Inserted element: %d\n", data);
}

void insertAtPosition()
{
    int data, position;
    struct Node *newNode, *ptr;
    int i;

    printf("Enter position: \n");
    scanf("%d", &position);

    if (start == NULL)
    {
        printf("List is empty.\n");
    }
    else if (position == 1)
    {
        insertAtFront();
    }
    else
    {
        printf("Enter number to be inserted: \n");
        scanf("%d", &data);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        /*
         * Traverse to n-1Node
         */
        ptr = start;
        for (i = 2; i <= position - 1; i++)
        {
            ptr = ptr->next;
        }

        /* Links newNode withNode astart of it and previous to it*/
        newNode->next = ptr->next;
        ptr->next = newNode;

        printf("NODE INSERTED SUCCESSFULLY.\n");
    }
    printf("Inserted element: %d\n", data);
}

void insertAtEnd()
{
    struct Node *ptr, *trav;
    int data;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("OVERFLOW\n");
    }
    else
    {
        printf("Enter Data: \n");
        scanf("%d", &data);
        ptr->data = data;
        if (start == NULL)
        {
            start = ptr;
            ptr->next = start;
        }
        else
        {
            trav = start;
            while (trav->next != start)
            {
                trav = trav->next;
            }
            trav->next = ptr;
            ptr->next = start;
        }
    }
    printf("Inserted element: %d\n", data);
}

void deleteAtFront()
{
    struct Node *ptr;
    if (start == NULL)
    {
        printf("List is Empty\n");
    }
    else if (start->next == start)
    {
        start = NULL;
        free(start);
        printf("Node deleted\n");
    }

    else
    {
        ptr = start;
        while (ptr->next != start)
            ptr = ptr->next;
        ptr->next = start->next;
        free(start);
        start = ptr->next;
        printf("Node deleted\n");
    }
}

void deleteAtEnd()
{
    struct Node *ptr, *position;
    if (start == NULL)
    {
        printf("List is Empty\n");
    }
    else if (start->next == start)
    {
        start = NULL;
        free(start);
        printf("Node deleted\n");
    }
    else
    {
        ptr = start;
        while (ptr->next != start)
        {
            position = ptr;
            ptr = ptr->next;
        }
        position->next = ptr->next;
        free(ptr);
        printf("Node deleted\n");
    }
}

int main()
{
    int n;
    int option;
    while (1)
    {
        printf("1.Create\n2.Display\n");
        printf("3.Insert in begining 4.Insert at Position 5.Insert at last\n");
        printf("6.Delete from Beginning 7.Delete from last\n");
        printf("8.Exit\n");
        printf("Enter your option: \n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the number of Nodes to be creatd: \n");
            scanf("%d", &n);
            createList(n);
            break;
        case 2:
            display();
            break;
        case 3:
            insertAtFront();
            break;
        case 4:
            insertAtPosition();
            break;
        case 5:
            insertAtEnd();
            break;
        case 6:
            deleteAtFront();
            break;
        case 7:
            deleteAtEnd();
            break;
        case 8:
            exit(0);
        default:
            printf("Select Correct option\n");
        }
    }
    return 0;
}