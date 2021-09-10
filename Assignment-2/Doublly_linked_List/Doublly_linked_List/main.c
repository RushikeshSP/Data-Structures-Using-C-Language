/*

Que : Menu-driven Program of Doublly linked list operations.
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

void displayReversedLinkedList(struct node* tail)
{
	if (tail == NULL)
	{
		printf("Linked List is Empty. Try Inserting Node First.\n");
	}
	else
	{
		printf("Reversed Linked List: NULL ");
		while (tail != NULL)
		{
			printf("<= %d => ", tail->data);
			tail = tail->previous;
		}
		printf("NULL\n");
	}
}

void insertAtFirst(struct node** head, struct node** tail)
{
	struct node* newnode = NULL;
	newnode = createNode();

	if (*head == NULL)
	{
		*head = *tail = newnode;
	}
	else
	{
		(*head)->previous = newnode;
		newnode->next = *head;
		*head = newnode;
	}
}

void insertAtLast(struct node** head, struct node** tail)
{
	createLinkedList(head, tail);
}

int calculateNode(struct node* head)
{
	int count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}

void insertAtPosition(struct node** head, struct node** tail)
{
	int pos;
	printf("Please Enter a Position: ");
	scanf_s("%d", &pos);

	int len = calculateNode(*head);

	if (pos == 1)
	{
		insertAtFirst(head, tail);
	}
	else if (pos == len + 1)
	{
		insertAtLast(head, tail);
	}
	else if (pos < 1 || pos > len + 1)
	{
		printf("Invalid Position. Please Try Again...\n");
		insertAtPosition(head, tail);
	}
	else
	{
		struct node* tempnode = *head;
		struct node* newnode = NULL;
		newnode = createNode();

		for (int i = 1; i < pos-1; i++)
		{
			tempnode = tempnode->next;
		}

		newnode->previous = tempnode;
		newnode->next = tempnode->next;
		tempnode->next = newnode;
		newnode->next->previous = newnode;
	}
}

void deleteAtFirst(struct node** head, struct node** tail)
{
	if (*head == NULL)
	{
		printf("Linked List is empty. Try Inserting Node First.\n");
	}
	else
	{
		if (*head == *tail)
		{
			free(*head);
			*head = *tail = NULL;
		}
		else
		{
			struct node* tempnode = *head;
			
			*head = (*head)->next;
			(*head)->previous = NULL;
			free(tempnode);
		}
		printf("Node Deleted Successflly... \n");
	}
}

void deleteAtLast(struct node** head, struct node** tail)
{
	if (*tail == NULL)
	{
		printf("Linked List is Empty. Try Inserting Node First..\n");
	}
	else
	{
		if (*tail == *head)
		{
			free(*tail);
			*head = *tail = NULL;
		}
		else
		{
			struct node* tempnode = *tail;

			*tail = (*tail)->previous;
			(*tail)->next = NULL;
			free(tempnode);
		}
		printf("Node Deleted Successfully...\n");
	}
}

void deleteAtPosition(struct node** head, struct node** tail)
{
	if (*head == NULL)
	{
		printf("Linked List is Empty. Try Inserting Node First.\n");
	}
	else
	{
		int pos;
		printf("Please Enter a Position: ");
		scanf_s("%d", &pos);

		int len = calculateNode(*head);

		if (pos == 1)
		{
			deleteAtFirst(head, tail);
		}
		else if (pos == len)
		{
			deleteAtLast(head, tail);
		}
		else if (pos < 1 || pos > len)
		{
			printf("Invalid Position. Please Try Again...\n");
			deleteAtPosition(head, tail);
		}
		else
		{
			struct node* tempnode = *head;
			struct node* deletenode = NULL;

			for (int i = 1; i < pos-1; i++)
			{
				tempnode = tempnode->next;
			}

			deletenode = tempnode->next;
			tempnode->next = deletenode->next;
			deletenode->next->previous = deletenode->previous;
			free(deletenode);

			printf("Node Deleted Successfully...\n");
		}
	}
}

void clearLinkedList(struct node** head, struct node** tail)
{
	if (*head == NULL)
	{
		printf("Linked List is Empty. Try Inserting Node First.\n");
	}
	else
	{
		struct node* tempnode = *head;

		while (*head != *tail)
		{
			tempnode = tempnode->next;
			free(*head);
			*head = tempnode;
		}
		free(tempnode);
		*head = *tail = NULL;

		printf("Linked List Deleted Successfully...\n");
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
		printf("3. Display Reversed Linked List.\n");
		printf("4. Insert At First.\n");
		printf("5. Insert At Last.\n");
		printf("6. Insert At Any Postion.\n");
		printf("7. Delete At First.\n");
		printf("8. Delete At Last.\n");
		printf("9. Delete At Any Postion.\n");
		printf("10. Clear Linked List(Delete All Nodes).\n");
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
			displayReversedLinkedList(last); 
			break;
		case 4:
			insertAtFirst(&first, &last);
			break;
		case 5:
			insertAtLast(&first, &last);
			break;
		case 6:
			insertAtPosition(&first, &last);
			break;
		case 7:
			deleteAtFirst(&first, &last);
			break;
		case 8:
			deleteAtLast(&first, &last);
			break;
		case 9:
			deleteAtPosition(&first, &last);
			break;
		case 10:
			clearLinkedList(&first, &last);
			break;
		default:
			printf("Invalid Choice. Please Enter It Again...\n");
			break;
		}
	} while (choice != 0);

}