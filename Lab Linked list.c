// C program for the all operations in
// the Singly nexted List
#include <stdio.h>
#include<stdlib.h>
// nexted List Node
struct node {
	int data;
	struct node* next;
};
struct node* start = NULL;

// Function to traverse the nexted list
void display()
{
	struct node* ptr;

	// List is empty
	if (start == NULL)
		printf("\nList is empty\n");

	// Else print the LL
	else {
		ptr = start;
		while (ptr != NULL) {
			printf("Data = %d\n",
				ptr->data);
			ptr = ptr->next;
		}
	}
}

// Function to insert at the front
// of the nexted list
void insertAtFront()
{
	int data;
	struct node* ptr;
	ptr = malloc(sizeof(struct node));
	printf("\nEnter number to"
		" be inserted : ");
	scanf("%d", &data);
	ptr->data = data;

	// Pointer of ptr will be
	// assigned to start
	ptr->next = start;
	start = ptr;
}

// Function to insert at the end of
// the nexted list
void insertAtEnd()
{
	int data;
	struct node *ptr, *head;
	ptr = malloc(sizeof(struct node));

	// Enter the number
	printf("\nEnter number to"
		" be inserted : ");
	scanf("%d", &data);

	// Changes nexts
	ptr->next = 0;
	ptr->data = data;
	head = start;
	while (head->next != NULL) {
		head = head->next;
	}
	head->next = ptr;
}

// Function to insert at any specified
// position in the nexted list
void insertAtPosition()
{
	struct node *ptr, *newnode;
	int pos, data, i = 1;
	newnode = malloc(sizeof(struct node));
	// Enter the position and data
	printf("\nEnter position and data :");
	scanf("%d %d", &pos, &data);

	// Change nexts
	ptr = start;
	newnode->data = data;
	newnode->next = 0;
	while (i < pos - 1) {
		ptr = ptr->next;
		i++;
	}
	newnode->next = ptr->next;
	ptr->next = newnode;
}

// Function to delete from the front
// of the nexted list
void deleteFirst()
{
	struct node* ptr;
	if (start == NULL)
		printf("\nList is empty\n");
	else {
		ptr = start;
		start = start->next;
		free(ptr);
	}
}

// Function to delete from the end
// of the nexted list
void deleteEnd()
{
	struct node *ptr, *prevnode;
	if (start == NULL)
		printf("\nList is Empty\n");
	else {
		ptr = start;
		while (ptr->next != 0) {
			prevnode = ptr;
			ptr = ptr->next;
		}
		free(ptr);
		prevnode->next = 0;
	}
}

// Function to delete from any specified
// position from the nexted list
void deletePosition()
{
	struct node *ptr, *position;
	int i = 1, pos;

	// If LL is empty
	if (start == NULL)
		printf("\nList is empty\n");

	// Otherwise
	else {
		printf("\nEnter index : ");

		// Position to be deleted
		scanf("%d", &pos);
		position = malloc(sizeof(struct node));
		ptr = start;

		// Traverse till position
		while (i < pos - 1) {
			ptr = ptr->next;
			i++;
		}

		// Change nexts
		position = ptr->next;
		ptr->next = position->next;

		// Free memory
		free(position);
	}
}

int search()  
{  
    struct node *ptr, *head;
	ptr = malloc(sizeof(struct node));  
    int num,pos=0,found = 0;
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter number which you want to search\n");   
        scanf("%d",&num);  
        for(ptr = start; ptr != NULL; ptr = ptr->next){
			pos = pos + 1;
			if(ptr->data == num){
				found = 1;
				break;
			}
		}  
        if(found==1)  
        {  
            printf("%d found at position %d\n", num, pos);  
        }
		else{
			printf("%d not found in the list\n", num);
		}
    }
}

// Driver Code
int main()
{
	int choice;
	while (1) {

		printf("\n\t1 To display list\n");
		printf("\t2 For insertion at"
			" starting\n");
		printf("\t3 For insertion at"
			" end\n");
		printf("\t4 For insertion at "
			"any position\n");
		printf("\t5 For deletion of "
			"first element\n");
		printf("\t6 For deletion of "
			"last element\n");
		printf("\t7 For deletion of "
			"element at any position\n");
		printf("\t8 Linear Search\n");
		printf("\t9 To exit\n");
		printf("\nEnter Choice :\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			display();
			break;
		case 2:
			insertAtFront();
			break;
		case 3:
			insertAtEnd();
			break;
		case 4:
			insertAtPosition();
			break;
		case 5:
			deleteFirst();
			break;
		case 6:
			deleteEnd();
			break;
		case 7:
			deletePosition();
			break;
		case 8:
			search();
            break;
		case 9:
			exit(1);
			break;
		default:
			printf("Incorrect Choice\n");
		}
	}
	return 0;
}
