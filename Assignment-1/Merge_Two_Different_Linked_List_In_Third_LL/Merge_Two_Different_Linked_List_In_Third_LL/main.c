/*

Que : 6. Write a C program to merge two different linked list in third linked list.
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
		printf("Enter a Data: ");
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
		while (head != NULL)
		{
			printf("%d => ", head->data);
			head = head->next;
		}
		printf("NULL\n");
	}
}

int countNode(struct node* head)
{
	int count = 0;

	while (head != NULL) 
	{
		count++;
		head = head->next;
	}
	return count;
}

void deleteLinkedList(struct node** head)
{
	struct node* tempnode = *head;

	while (tempnode != NULL)
	{
		tempnode = tempnode->next;
		free(*head);
		*head = tempnode;
	}
}

void mergeLinkedLists(struct node** head_3, struct node* head_1, struct node* head_2)
{
	if (*head_3 == NULL)
	{
		int n1 = countNode(head_1);
		int n2 = countNode(head_2);

		for (int i = 0; i < n1 + n2; i++)
		{
			createLinkedList(head_3);
		}
		struct node* tempnode = *head_3;
		while (head_1 != NULL)
		{
			tempnode->data = head_1->data;
			head_1 = head_1->next;
			tempnode = tempnode->next;
		}
		while (head_2 != NULL)
		{
			tempnode->data = head_2->data;
			head_2 = head_2->next;
			tempnode = tempnode->next;
		}
	}
	else 
	{
		deleteLinkedList(head_3);
		mergeLinkedLists(head_3, head_1, head_2);
	}
}

void main()
{
	int choice;
	struct node* first_1 = NULL;
	struct node* first_2 = NULL;
	struct node* first_3 = NULL;

	do
	{
		printf("**********************************************************\n");
		printf("Please Enter Your Choice: \n");
		printf("0. Exit.\n");
		printf("1. Create Linked List_1.\n");
		printf("2. Create Linked List_2.\n");
		printf("3. Display Linked List_1.\n");
		printf("4. Display Linked List_2.\n");
		printf("5. Merge Linked List_1 and Linked List_2.\n");
		printf("6. Display Merged Linked List.\n");
		printf("Choice = ");
		scanf_s("%d", &choice);
		printf("**********************************************************\n");

		switch (choice)
		{
		case 0:
			printf("Thank You...\n");
			break;
		case 1:
			createLinkedList(&first_1);
			break;
		case 2:
			createLinkedList(&first_2);
			break;
		case 3:
			printf("Linked List_1: ");
			displayLinkedList(first_1);
			break;
		case 4:
			printf("Linked List_2: ");
			displayLinkedList(first_2);
			break;
		case 5:
			mergeLinkedLists(&first_3, first_1, first_2);
			break;
		case 6:
			printf("Merged Linked List_3: ");
			displayLinkedList(first_3);

		}
	} while (choice != 0);
}