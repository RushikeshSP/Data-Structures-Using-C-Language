/*

Que : 7. Write a C program to clear the given linked list (delete all nodes).
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
		printf("Given Linked List: ");
		while (head != NULL)
		{
			printf("%d => ", head->data);
			head = head->next;
		}
		printf("NULL\n");
	}
}

void clearLinkedList(struct node** head)
{
	if (*head == NULL)
	{
		printf("Linked List is Empty. Try Inserting Node First.\n");
	}
	else
	{
		struct node* tempnode = *head;

		while(tempnode != NULL)
		{
			tempnode = tempnode->next;
			free(*head);
			*head = tempnode;
		}
		printf("Linked List Deleted Successfully...\n");
	}
}

void main()
{
	int choice;
	struct node* first = NULL;

	do
	{
		printf("*****************************************************\n");
		printf("Enter Your Choice: \n");
		printf("0. Exit.\n");
		printf("1. Create Linked List.\n");
		printf("2. Display Linked List.\n");
		printf("3. Clear Linked List(Delete All Nodes).\n");
		printf("Choice = ");
		scanf_s("%d", &choice);
		printf("*****************************************************\n");

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
			clearLinkedList(&first);
			break;
		default:
			printf("Please Enter a Valid Choice.\n");
			break;
		}

	} while (choice != 0);
}