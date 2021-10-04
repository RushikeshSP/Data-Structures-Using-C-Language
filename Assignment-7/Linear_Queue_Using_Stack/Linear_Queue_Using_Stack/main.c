/*

Que : Write a C program for Creation of Linear Queue Using Stack.
Owner: Rushikesh Sanjay Pokharkar
Batch: PPA9

*/

//                                        *********  Solution  *********


#include<stdio.h> //Include Necessary Header Files.
#define MAX 5

struct Queue // Structure for Queue
{
	int arr[MAX];
	int front;
	int rear;
};

void initQueue(struct Queue* queueptr) // Function to initialize the Queue variables.
{
	queueptr->front = queueptr->rear = -1;
}

int isFull(struct Queue* queueptr) // Function to check queue is full or not.
{
	return queueptr->rear == MAX - 1;
}

int isEmpty(struct Queue* queueptr) // Function to check queue if empty or not.
{
	return queueptr->rear == queueptr->front;
}

void enQueue(struct Queue* queueptr) // Function to insert data into the queue.
{
	if (!isFull(queueptr)) // Check if queue is full or not 
	{
		// Logic to insert data into the queue.
		int data;
		printf("Enter a data: ");
		scanf_s("%d", &data);

		queueptr->rear++;
		queueptr->arr[queueptr->rear] = data;
	}
	else
	{
		printf("Queue is Full You cannot perform this operation.\n");
	}
}

int deQueue(struct Queue* queueptr) // Function to delete data from the queue.
{ 
	if (!isEmpty(queueptr)) // Check if queue is empty or not.
	{
		// Logic to delete data from the queue.
		int data;

		queueptr->front++;
		data = queueptr->arr[queueptr->front];

		return data;
	}
	else
	{
		printf("Queue is Empty You cannot perform this operation.\n");
	}
}

void main()
{
	int choice;
	struct Queue q; // Created the pointer of structure queue.

	initQueue(&q);

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
			enQueue(&q);
			break;
		case 2:
			printf("The value %d removed from queue.\n", deQueue(&q));
			break;
		default:
			printf("Please Enter a Valid Choice.\n");
		}
	} while (choice != 0);
}