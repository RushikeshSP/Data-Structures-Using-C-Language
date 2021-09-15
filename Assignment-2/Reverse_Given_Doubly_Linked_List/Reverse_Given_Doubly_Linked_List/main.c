/*

Que : Menu-driven Program of Doublly linked list to reverse it.
Owner: Rushikesh Sanjay Pokharkar
Batch: PPA9

*/

//                                        *********  Solution  *********


#include <stdio.h>
#include <stdlib.h>


struct node
{
	struct node* previous;
	int data;
	struct node* next;
};

struct node* createNode()
{
	struct node* newnode = NULL;
	newnode = (struct node*)malloc(sizeof(struct node));

	if (newnode == NULL)
	{
		printf("Node Not Created..\n");
	}
	else
	{
		int num;
		printf("Enter a data: ");
		scanf_s("%d", &num);

		newnode->previous = NULL;
		newnode->data = num;
		newnode->next = NULL;
	}
	return newnode;
}

void createLinkedList(struct node** head, struct node** tail)
{
	struct node* newnode = NULL;
	newnode = createNode();

	if (*head == NULL)
	{
		*head = newnode;
		*tail = newnode;
	}
	else
	{
		(*tail)->next = newnode;
		newnode->previous = *tail;
		*tail = newnode;
	}

}

void displayLinkedList(struct node* head)
{
	if (head == NULL)
	{
		printf("Linked List is Empty. Try Inserting Node First.\n");
	}
	else
	{
		printf("Linked List: NULL ");
		while (head != NULL)
		{
			printf("<= %d => ", head->data);
			head = head->next;
		}
		printf("NULL\n");
	}
}

void ReversedLinkedList(struct node** head, struct node** tail)
{
	if (*head == NULL)
	{
		printf("Linked List is Empty. Try Inserting Node First.\n");
	}
	else
	{
		struct node* tempnode = *head;
		struct node* previousnode = NULL;
		struct node* nextnode = NULL;

		*tail = tempnode;
		while (tempnode != NULL)
		{
			nextnode = tempnode->next;
			tempnode->next = previousnode;
			tempnode->previous = nextnode;
			previousnode = tempnode;
			tempnode = nextnode;
		}
		*head = previousnode;
		printf("Linked List reversed successfully...\n");
	}
}


void main()
{
	struct node* first = NULL;
	struct node* last = NULL;
	int choice;

	do
	{
		printf("*************************************************\n");
		printf("Please Enter Your Choice: \n");
		printf("0. Exit.\n");
		printf("1. Create Linked List.\n");
		printf("2. Display Linked List.\n");
		printf("3. Reversed Linked List.\n");
		printf("Choice = ");
		scanf_s("%d", &choice);
		printf("*************************************************\n");

		switch (choice)
		{
		case 0:
			printf("Thank You...\n");
			break;
		case 1:
			createLinkedList(&first, &last);
			break;
		case 2:
			displayLinkedList(first);
			break;
		case 3:
			ReversedLinkedList(&first, &last);
			break;
		default:
			printf("Invalid Choice. Please Enter It Again...\n");
			break;
		}
	} while (choice != 0);

}