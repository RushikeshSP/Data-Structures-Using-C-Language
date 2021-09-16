/*

Que : 8. Write a C program to create circular linked list and it's various operations.
Owner: Rushikesh Sanjay Pokharkar
Batch: PPA9

*/

//                                        *********  Solution  *********


# include <stdio.h>
# include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* createNode()
{
	struct node* newnode = NULL;

	newnode = (struct node*)malloc(sizeof(struct node));

	if (newnode == NULL)
	{
		printf("Node Not Created.\n");
	}
	else
	{
		int val;
		printf("Enter a data: ");
		scanf_s("%d", &val);

		newnode->data = val;
		newnode->next = NULL;
	}

	return newnode;
}

void createLinkedList(struct node** tail)
{
	struct node* newnode = NULL;

	newnode = createNode();

	if (*tail == NULL)
	{
		*tail = newnode;
		(*tail)->next = newnode;
	}
	else
	{
		newnode->next = (*tail)->next;
		(*tail)->next = newnode;
		*tail = newnode;
	}
}

void displayLinkedList(struct node* tail)
{
	if (tail == NULL)
	{
		printf("Linked List is Empty. Try Inserting Node First..\n");
	}
	else
	{
		printf("Linked List: ");
		struct node* tempnode = tail->next;
		do
		{
			printf("%d => ", tempnode->data);
			tempnode = tempnode->next;
		} while (tempnode != tail->next);
		printf("\n");
	}
}

void insertAtFirst(struct node** tail)
{
	struct node* newnode = NULL;

	newnode = createNode();

	if (*tail == NULL)
	{
		*tail = newnode;
		(*tail)->next = newnode;
	}
	else
	{
		newnode->next = (*tail)->next;
		(*tail)->next = newnode;
	}
}

void insertAtLast(struct node** tail)
{
	createLinkedList(tail);
}

void main()
{
	int choice;
	struct node* last = NULL;

	do
	{
		printf("*****************************************************\n");
		printf("Enter Your Choice: \n");
		printf("0. Exit.\n");
		printf("1. Create Singly Circular Linked List.\n");
		printf("2. Display Linked List.\n");
		printf("3. Insert At First.\n");
		printf("4. Insert At Last.\n");
		printf("Choice = ");
		scanf_s("%d", &choice);
		printf("*****************************************************\n");

		switch (choice)
		{
		case 0:
			printf("Thank You...\n");
			break;
		case 1:
			createLinkedList(&last);
			break;
		case 2:
			displayLinkedList(last);
			break;
		case 3:
			insertAtFirst(&last);
			break;
		case 4:
			insertAtLast(&last);
			break;
		default:
			printf("Please Enter a Valid Choice.\n");
			break;
		}

	} while (choice != 0);
}