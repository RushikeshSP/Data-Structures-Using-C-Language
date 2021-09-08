/*

Que : 3. Write a C program to sort a given Linked list in ascending order.
Owner: Rushikesh Sanjay Pokharkar
Batch: PPA9

*/

//                                        *********  Solution  *********


#include <stdio.h>
#include <stdlib.h>

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
		int num;

		printf("Enter a data: ");
		scanf_s("%d", &num);

		newnode->data = num;
		newnode->next = NULL;
	}
	return newnode;
}

void createLinkedList(struct node** head)
{
	struct node* newnode = NULL;
	struct node* tempnode = *head;

	newnode = createNode();

	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		while (tempnode->next != NULL)
		{
			tempnode = tempnode->next;
		}
		tempnode->next = newnode;
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
		printf("Linked List: ");
		while (head != NULL)
		{
			printf("%d => ", head->data);
			head = head->next;
		}
		printf("NULL\n");
	}

}

void sortLinkedList(struct node* head)
{
	if (head == NULL)
	{
		printf("LInked List is Empty. Try Inserting Node First.\n");
	}
	else
	{
		int len = 0;
		struct node* tempnode = head;

		while (tempnode != NULL)
		{
			len++;
			tempnode = tempnode->next;
		}

		while (head != NULL)
		{
			tempnode = head->next;
			while (tempnode != NULL)
			{
				if (head->data > tempnode->data)
				{
					int temp = head->data;
					head->data = tempnode->data;
					tempnode->data = temp;
				}
				tempnode = tempnode->next;
			}
			head = head->next;
		}
		printf("Linked List Sorted Successfully..\n");
	}
}

void main()
{
	int choice;
	struct node* first = NULL;

	do
	{
		printf("**********************************************************\n");
		printf("Enter Your Choice: \n");
		printf("0. Exit.\n");
		printf("1. Create Linked List.\n");
		printf("2. Display Linked List.\n");
		printf("3. Sort Linked list In Ascending Order.\n");
		printf("Choice = ");
		scanf_s("%d", &choice);
		printf("**********************************************************\n");


		switch (choice)
		{
		case 0:
			printf("Thank You...\n");
			break;
		case 1:
			createLinkedList(&first);
			break;
		case 2:
			displayLinkedList(first);
			break;
		case 3:
			sortLinkedList(first);
			break;
		default:
			printf("Invalid Choice. Please Try Again...\n");
		}
	} while (choice != 0);
}


