/*

Que : Write a C program for Creation of Queue Using Linked List.
Owner: Rushikesh Sanjay Pokharkar
Batch: PPA9

*/

//                                        *********  Solution  *********


#include<stdio.h> //Include Necessary Header Files.
#include<stdlib.h>

struct Queue // Structure for Queue
{
	int data;
	struct Queue* front;
	struct Queue* rear;
};

struct Queue* createNode() // Function to create node for Queue.
{
	struct Queue* newnode = NULL;

	newnode = (struct Queue*) malloc(sizeof(struct Queue)); // Malloc function to allocate memory dynamically.

	if (newnode == NULL)
	{
		printf("Queue is full You can-not perform this operation.\n");
	}
	else
	{
		int data;
		printf("Enter a data: ");
		scanf_s("%d", &data); // Add data to the node.

		newnode->data = data;
		newnode->front = NULL;
		newnode->rear = NULL;
	}
}

void enQueue(struct Queue** Front, struct Queue** Rear) // Function to insert data into the queue.
{
	// Logic to insert data into the queue.
	struct Queue* newnode = NULL;

	newnode = createNode();

	if (*Rear == NULL) // If first node in Queue.
	{
		*Rear = newnode;
		*Front = newnode;
	}
	else // If not-First node into the Queue.
	{
		(*Rear)->rear = newnode;
		*Rear = newnode;
	}
}

int deQueue(struct Queue** Front, struct Queue** Rear) // Function to delete data from the queue.
{
	// Logic to delete data from the queue.
	int data;

	struct Queue* deletenode = *Front;
	data = (*Front)->data;

	if (*Front == *Rear) // If deleted node is the last node in Queue.
	{
		*Rear = NULL;
	}
	*Front = (*Front)->rear;
	free(deletenode); // Free the memory given to the node dynamically.
	
	return data; // Return the deleted data.
}

void main()
{
	int choice;
	struct Queue* Front = NULL; // Front pointer to access the Queue.
	struct Queue* Rear = NULL; // Rear pointer to access the Queue.

	do
	{
		printf("Please Enter Your Choice: \n");
		printf("0. For Exit.\n");
		printf("1. For Insert Element In Queue.\n");
		printf("2. For Delete Element From Queue.\n");
		printf("Choice = ");
		scanf_s("%d", &choice);

		// Switch case implementation for various operations of user input.
		switch (choice)
		{
		case 0:
			printf("Thank You!!!\n");
			break;
		case 1:
			enQueue(&Front, &Rear);
			break;
		case 2:

			if (!(Front == NULL)) // Check if queue is empty or not.
			{
				printf("The value %d removed from queue.\n", deQueue(&Front, &Rear));
			}
			else
			{
				printf("Queue is Empty you can-not perform this operation.\n");
			}
			break;
		default:
			printf("Please Enter a Valid Choice.\n");
		}
	} while (choice != 0);
}