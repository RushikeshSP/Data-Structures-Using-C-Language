/*

Que : 5. Write a C program to find out maximum element from first half of the linked list and
minimum from second half of the linked list.
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

void displayMaxMin(struct node* head)
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

		int half = len / 2;
		int count = 1;

		int max = head->data;
		int min = head->data;
		tempnode = head->next;

		
		while (tempnode != NULL)
		{
			count++;
			if (count <= half)
			{
				if (tempnode->data > max)
				{
					max = tempnode->data;
				}
			}
			else
			{
				if (count == half + 1)
				{
					min = tempnode->data;
					tempnode = tempnode->next;
					if (tempnode == NULL)
					{
						break;
					}
				}
				if (tempnode->data < min)
				{
					min = tempnode->data;
				}
			}
			tempnode = tempnode->next;
		}
		printf("The Maximum Element From First Half is: %d\n", max);
		printf("The Minimum Element From Second Half is: %d\n", min);
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
		printf("3. Find Max and Min From First and Second Half.\n");
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
			displayMaxMin(first);
			break;
		default:
			printf("Invalid Choice. Please Try Again...\n");
		}
	} while (choice != 0);
}


