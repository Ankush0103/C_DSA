// C program for the all operations in the Doubly linked List
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *prev, *next;
};

struct Node *start = NULL;
struct Node *last;

void createList(int n)
{
	int i, data;
	struct Node *newNode;

	if (n >= 1)
	{
		start = (struct Node *)malloc(sizeof(struct Node));

		if (start != NULL)
		{
			printf("Enter data of 1 Node: ");
			scanf("%d", &data);

			start->data = data;
			start->prev = NULL;
			start->next = NULL;

			last = start;

			for (i = 2; i <= n; i++)
			{
				newNode = (struct Node *)malloc(sizeof(struct Node));

				if (newNode != NULL)
				{
					printf("Enter data of %d Node: ", i);
					scanf("%d", &data);

					newNode->data = data;
					newNode->prev = last; // Links new Node with the previous Node
					newNode->next = NULL;

					last->next = newNode; // Links previous Node with the new Node
					last = newNode;
				}
				else
				{
					printf("Unable to allocate memory.");
					break;
				}
			}

			printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
		}
		else
		{
			printf("Unable to allocate memory");
		}
	}
}

void display()
{
	// List is empty
	if (start == NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	// Else print the Data
	struct Node *ptr;
	ptr = start;
	while (ptr != NULL)
	{
		printf("Data = %d\n", ptr->data);
		ptr = ptr->next;
	}
}

void insertAtFront()
{
	int data;
	struct Node *ptr;
	ptr = (struct Node *)malloc(sizeof(struct Node));
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	ptr->data = data;
	ptr->prev = NULL;
	ptr->next = start;
	start = ptr;
}

void insertAtEnd()
{
	int data;
	struct Node *ptr, *trav;
	ptr = (struct Node *)malloc(sizeof(struct Node));
	ptr->prev = NULL;
	ptr->next = NULL;
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	ptr->data = data;
	ptr->next = NULL;
	trav = start;

	// If start is NULL
	if (start == NULL)
	{

		start = ptr;
	}

	else
	{
		while (trav->next != NULL)
		{
			trav = trav->next;
		}
		ptr->prev = trav;
		trav->next = ptr;
	}
}

void insertAtPosition()
{
	int data, pos, i = 1;
	struct Node *ptr, *newNode;
	newNode = malloc(sizeof(struct Node));
	newNode->next = NULL;
	newNode->prev = NULL;

	printf("\nEnter position : ");
	scanf("%d", &pos);

	if (start == NULL)
	{
		start = newNode;
		newNode->prev = NULL;
		newNode->next = NULL;
	}

	else if (pos == 1)
	{
		newNode->next = start;
		newNode->next->prev = newNode;
		newNode->prev = NULL;
		start = newNode;
	}

	else
	{
		printf("\nEnter number to be inserted: ");
		scanf("%d", &data);
		newNode->data = data;
		ptr = start;
		while (i < pos - 1)
		{
			ptr = ptr->next;
			i++;
		}
		newNode->next = ptr->next;
		newNode->prev = ptr;
		ptr->next = newNode;
		ptr->next->prev = newNode;
	}
}

void deleteFirst()
{
	struct Node *ptr;
	if (start == NULL)
		printf("\nList is empty\n");
	else
	{
		ptr = start;
		start = start->next;
		if (start != NULL)
			start->prev = NULL;
		free(ptr);
	}
}

void deleteEnd()
{
	struct Node *ptr;
	if (start == NULL)
		printf("\nList is empty\n");
	ptr = start;
	while (ptr->next != NULL)
		ptr = ptr->next;
	if (start->next == NULL)
		start = NULL;
	else
	{
		ptr->prev->next = NULL;
		free(ptr);
	}
}

void deletePosition()
{
	int pos, i = 1;
	struct Node *ptr, *position;
	ptr = start;

	if (start == NULL)
		printf("\nList is empty\n");

	else
	{

		printf("\nEnter position : ");
		scanf("%d", &pos);

		if (pos == 1)
		{
			deleteFirst();
			if (start != NULL)
			{
				start->prev = NULL;
			}
			free(position);
			return;
		}

		while (i < pos - 1)
		{
			ptr = ptr->next;
			i++;
		}
		position = ptr->next;
		if (position->next != NULL)
		{
			position->next->prev = ptr;		}
		ptr->next = position->next;
		free(position);
	}
}

int main()
{
	int n;
	int choice;
	while (1)
	{

		printf("1.Create\n2.Display\n");
		printf("3.Insert in begining 4.Insert at last 5.Insert at Position\n");
		printf("6.Delete from Beginning 7.Delete from last 8.Delete at Position\n");
		printf("9.Exit\n");
		printf("\nEnter Choice :\n");
		scanf("%d", &choice);

		switch (choice)
		{

		case 1:
			printf("Enter the number of Nodes you want to create: ");
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
			insertAtEnd();
			break;
		case 5:
			insertAtPosition();
			break;
		case 6:
			deleteFirst();
			break;
		case 7:
			deleteEnd();
			break;
		case 8:
			deletePosition();
			break;
		case 9:
			exit(0);
		default:
			printf("Select correct choice\n");
		}
	}
	return 0;
}