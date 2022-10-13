// C program for the above operation
#include <stdio.h>
#include <stdlib.h>

// Structure of a linked list node
struct node {
	int data;
	struct node* next;
};

// Pointer to last node in the list
struct node* last = NULL;

// Function to insert a node in the
// starting of the list
void insertAtFront()
{
	// Stores the number to be inserted
	int data;

	// Initialize a new node
	struct node* ptr;
	ptr = (struct node*)malloc(sizeof(struct node));

	// Input data
	printf("\nEnter data to be "
		"inserted: \n");
	scanf("%d", &data);

	// If the new node is the only
	// node in the list
	if (last == NULL) {
		ptr->data = data;
		ptr->next = ptr;
		last = ptr;
	}

	// Else last node contains the
	// reference of the new node and
	// new node contains the reference
	// of the previous first node
	else {
		ptr->data = data;
		ptr->next = last->next;

		// last node now has reference
		// of the new node ptr
		last->next = ptr;
	}
}

// Function to print the list
void viewList()
{
	// If list is empty
	if (last == NULL)
		printf("\nList is empty\n");

	// Else print the list
	else {
		struct node* ptr;
		ptr = last->next;

		// While first node is not
		// reached again, print,
		// since the list is circular
		do {
			printf("\nData = %d", ptr->data);
			ptr = ptr->next;
		} while (ptr != last->next);
	}
}

// Driver Code
int main()
{
	// Function Call
	insertAtFront();
	insertAtFront();
	insertAtFront();

	// Print list
	viewList();

	return 0;
}
