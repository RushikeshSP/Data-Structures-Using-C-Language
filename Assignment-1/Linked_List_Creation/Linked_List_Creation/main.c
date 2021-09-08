/*

Que : Menu-driven Program of linked list operations.
Owner: Rushikesh Sanjay Pokharkar
Batch: PPA9

*/

//                                        *********  Solution  *********


#include<stdio.h> // Include necessary header files.
#include<stdlib.h>

struct node // Declare the structure of the linked list node.
{
	int data; // data to stored in the node.
	struct node* next; // next pointer to store the address of the next node.
};

struct node* createNode() // Funcation to create nodes.
{
	int temp;
	struct node* newnode = NULL;
	newnode = (struct node*)malloc(sizeof(struct node)); // Given memory to created newnode on heap.

	if (newnode == NULL) // Check if memory is allocated or not.
	{
		printf("Memory Not Allocated. Please Try Again..");
	}
	else // If memory is allocated then give value to the data of created node.
	{
		printf("Enter a data: ");
		scanf_s("%d", &temp); // Take input data from user.
		newnode->data = temp; // Assigne value to the data of node.
		newnode->next = NULL; // Make the next pointer of created new node as NULL;
	}

	printf("Node Created Successfully.....\n");

	return newnode; // return the address of the new node.
}

void createLinkedList(struct node** head) // Funcation to create linked list.
{
	struct node* newnode = NULL;
	struct node* tempnode = *head; // Create a temperary node to store the address of first node. 
	newnode = createNode(); // first create newnode to create linked list.

	if (*head == NULL) // Check if given node is first node in the linked list.
	{
		*head = newnode; // Add the address of the first newnode to the *head(first) pointer to save it.
	}
	else // If node is not a first node then add it at the last of linked list.
	{
		while (tempnode->next != NULL) // Traverse the linked list to get the last node.
		{
			tempnode = tempnode->next;
		}
		tempnode->next = newnode; // Added the new node at the last node.
	}

}

void insertAtFirst(struct node** head) // Function to insert node at the first position.
{
	struct node* newnode = NULL;

	newnode = createNode(); // First create new node to add it on first position.

	newnode->next = *head; // Make a link of created newnode and the previous first node.

	*head = newnode; // Make new node as the first node of the linked list.
}

void insertAtLast(struct node** head) // Function to insert node at the last position.
{
	// The logic of inserting node at the last is same as the logic to create linked list.
	createLinkedList(head);
}

int calculateLength(struct node* head) // Function to calculate length of the linked list.
{
	int count = 0;
	while (head != NULL) // Loop to calculate length of linked list.
	{
		count++;
		head = head->next;
	}

	return count; // Return count of linked list.
}

void insertAtPosition(struct node** head) // Function to insert node at any position.
{
	int position;
	struct node* newnode = NULL;
	struct node* tempnode = *head;

	printf("Enter a Position: ");
	scanf_s("%d", &position); // Take user input- Position.

	int len = calculateLength(*head); // Take length of linked list in len variable.

	if (position == 1) // For position one call insert at first function.
	{
		insertAtFirst(head);
	}
	else if (position == len + 1) // For last + one position call insert at last function.
	{
		insertAtLast(head);
	}
	else if (position < 1 || position > len + 1) // Check for invalid positions.
	{
		printf("Please Enter a Valid Position.\n");
		insertAtPosition(head); // if invalid position- call insertAtPosition function recursivelly.
	}
	else // For position between 2 to len create linking.
	{
		newnode = createNode();

		for (int i = 1; i < position-1; i++) // For loop to iterate upto secondlast position.
		{
			tempnode = tempnode->next;
		}
		newnode->next = tempnode->next; // Create linking..
		tempnode->next = newnode;
	}
}

void deleteAtFirst(struct node** head) // Function to delete first node of linked list.
{
	if (*head == NULL) // Check if linked list is empty or not.
	{
		printf("Linked List is empty. Try inserting Node first.\n");
	}
	else // If linked list is not empty.
	{
		struct node* first = *head; // Make one extra first pointer to point the first node.
		*head = first->next; // Make the second node as the first node of linked list.
		free(first); // Free the memory given to node first on heap.
		printf("Node Deleted Successfully.....\n");
	}
}

/* 
	Delete at last function by using two pointer concept.
*/
/*
void deleteAtLast(struct node** head) // Function to delete last node of linked list.
{
	if (*head == NULL) // Check if linked list is empty or not.
	{
		printf("Linked List is empty. Try inserting Node first.\n");
	}
	else
	{
		struct node* first = *head; // Create pointer to point first node of linked list.
		struct node* second = *head;

		if (first->next == NULL) // Check if only one node is present in the linked list.
		{
			*head = NULL; // Make the *head(first of main fuction) as NULL i.e. remove first node.
			free(first); // Free the memory given to node first on heap.
		}
		else // If more then one node are present in the linked list.
		{
			while (second->next != NULL) // Travel to first node upto the previous node of last node.
			{
				first = first->next;
				second = first->next;
			}
			free(first->next); // Free the memory given to the last node of linked list on heap.
			first->next = NULL; // Make the previous node as the last node of linked list.
		}
		printf("Node Deleted Successfully.....\n");
	}
}
*/

void deleteAtLast(struct node** head) // Function to delete last node of linked list.
{
	if (*head == NULL) // Check if linked list is empty or not.
	{
		printf("Linked List is empty. Try inserting Node first.\n");
	}
	else
	{
		struct node* first = *head; // Create pointer to point first node of linked list.

		if (first->next == NULL) // Check if only one node is present in the linked list.
		{
			*head = NULL; // Make the *head(first of main fuction) as NULL i.e. remove first node.
			free(first); // Free the memory given to node first on heap.
		}
		else // If more then one node are present in the linked list.
		{
			while (first->next->next != NULL) // Travel to first node upto the previous node of last node.
			{
				first = first->next;
			}
			free(first->next); // Free the memory given to the last node of linked list on heap.
			first->next = NULL; // Make the previous node as the last node of linked list.
		}
		printf("Node Deleted Successfully.....\n");
	}
}

void deleteAtPosition(struct node** head) // Function to delete any position node of linked list.
{
	if (*head == NULL) // Check if linked list is empty or not.
	{
		printf("Linked List is Empty. Please Try Inserting Node First...\n");
	}
	else // If linked list is not empty.
	{
		int position;
		struct node* tempnode = *head;
		struct node* nextnode = NULL;

		printf("Please Enter a Position: ");
		scanf_s("%d", &position); // Take user input- position.

		int len = calculateLength(*head); // Take length of the linked list in len variable.

		if (position == 1) // If position is one then call delete at first function.
		{
			deleteAtFirst(head);
		}
		else if (position == len) // If position is equal to length then call delete at last function.
		{
			deleteAtLast(head);
		}
		else if (position < 1 || position > len) // Check for invalid positions.
		{
			printf("Invalid Position. Please Try Again...\n");
			deleteAtPosition(head);
		}
		else // If positions are valid..
		{
			for (int i = 1; i < position-1; i++) // Loop to iterate upto the second last postion.
			{
				tempnode = tempnode->next;
			}
			nextnode = tempnode->next; // Take the delete node into the nextnode pointer.

			tempnode->next = nextnode->next; // Make the linking..
			free(nextnode); // Free the memory allocated by pointer on heap dynamically.

			printf("Node Deleted Successfully.....\n");
		}
	}
}

void deleteLinkedList(struct node** head) // Function to delete Whole linked list.
{
	if (*head == NULL) // Check if linked list is empty or not.
	{
		printf("Linked List is Empty. Try Inserting Node First.\n");
	}
	else // If linked list is not empty.
	{
		struct node* tempnode = *head;
		int len = calculateLength(*head); // Take length of linked list.

		for (int i = 1; i <= len; i++) // Iterate over the linked list.
		{
			tempnode = tempnode->next; // Increase tempnode..
			free(*head); // Free the previous node of tempnode..
			*head = tempnode; // Make first node as tempnode.
		}

		printf("Linked List Deleted Successfully.....\n");
	}
}

void displayLinkedList(struct node* head) // Function to display linked list.
{
	printf("Linked List: ");
	if (head == NULL) // Check if linked list is empty or not.
	{
		printf("\n");
		printf("Linked List is Empty. Try Inserting Node First...\n");
	}
	else
	{
		while (head != NULL) // Loop to iterate over the linked list.
		{
			printf("%d => ", head->data); // Print data of each node.
			head = head->next;
		}
		printf("NULL\n");
	}
}

void main()
{
	int choice;
	struct node* first = NULL; // Pointer to store the address of first node.

	do
	{
		// Menu of Operations.
		printf("*****************************************\n");
		printf("Please Enter your Choice: \n");
		printf("0. Exit.\n");
		printf("1. Create Linked List.\n");
		printf("2. Display Linked List.\n");
		printf("3. Insert At First.\n");
		printf("4. Insert At Last.\n");
		printf("5. Insert At Any Position.\n");
		printf("6. Delete At First.\n");
		printf("7. Delete At Last.\n");
		printf("8. Delete At Any Position.\n");
		printf("9. Delete Linked List.\n");
		printf("Choice = ");
		scanf_s("%d", &choice);
		printf("*****************************************\n");

		switch (choice)
		{
		case 0:
			printf("Thank You..\n");
			break;
		case 1:
			// While function call address of first pointe is pass to function - As change in the address of first
			// pointer is going to happen in the create linked list function.
			createLinkedList(&first);
			break;
		case 2:
			// While function call only first pointer is pass to function - As no change in the address of first
			// pointer is going to happen in the disply function.
			displayLinkedList(first);
			break;
		case 3:
			insertAtFirst(&first);
			break;
		case 4:
			insertAtLast(&first);
			break;
		case 5:
			insertAtPosition(&first);
			break;
		case 6:
			deleteAtFirst(&first);
			break;
		case 7:
			deleteAtLast(&first);
			break;
		case 8:
			deleteAtPosition(&first);
			break;
		case 9:
			deleteLinkedList(&first);
			break;
		default:
			printf("Invalid Choice. Please Enter Again...\n");
			break;
		}
	} while (choice != 0);
}