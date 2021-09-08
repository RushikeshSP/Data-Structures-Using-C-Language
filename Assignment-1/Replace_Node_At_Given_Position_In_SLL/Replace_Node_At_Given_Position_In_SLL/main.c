/*

Que : 2. Write a C program to replace a node at given position in linked list.
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

void replaceNode(struct node** head)
{
	if (*head == NULL)
	{
		printf("Linked List is Empty. Try Inserting Node First.\n");
	}
	else
	{
		int position;

		printf("Please Enter an Position to Replace Node: ");
		scanf_s("%d", &position);

		int len = 0;
		struct node* tempnode = *head;
		struct node* newnode = NULL;

		while (tempnode != NULL)
		{
			len++;
			tempnode = tempnode->next;
		}

		if (position == 1)
		{
			// Logic to delete first node.
			tempnode = *head;
			*head = tempnode->next;
			free(tempnode);

			// Logic to add new first node.
			newnode = createNode();
			newnode->next = *head;
			*head = newnode;
		}
		else if (position == len)
		{
			newnode = tempnode = *head;

			// Logic to delete last node.
			for (int i = 1; i < len-1; i++)
			{
				tempnode = tempnode->next;
			}
			newnode = tempnode->next;
			tempnode->next = NULL;
			free(newnode);

			// Logic to add new last node.
			newnode = createNode();
			tempnode->next = newnode;
		}
		else if (position < 1 || position > len)
		{
			printf("Invalid Position. Please Enter Again...\n");
			replaceNode(head);
		}
		else
		{
			tempnode = newnode = *head;
			struct node* nextnode = NULL;
			
			// Logic to delete node of specific position of valid position.
			for (int i = 1; i < position-1; i++)
			{
				tempnode = tempnode->next;
			}
			newnode = tempnode->next;
			tempnode->next = newnode->next;
			free(newnode);

			// Logic to add new node at deleted position.
			newnode = createNode();
			nextnode = tempnode->next;
			tempnode->next = newnode;
			newnode->next = nextnode;
		}
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
		printf("3. Replace the Node At Position.\n");
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
			replaceNode(&first);
			break;
		default:
			printf("Please Enter a Valid Choice.\n");
			break;
		}

	} while (choice != 0);
}