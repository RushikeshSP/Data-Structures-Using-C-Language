/*

Que : Write a C program for Creation of Stack.
Owner: Rushikesh Sanjay Pokharkar
Batch: PPA9

*/

//                                        *********  Solution  *********


#include<stdio.h> //Include Necessary Header Files.
#define MAX 5

struct STACK
{
	int arr[MAX];
	int top;
};

int isFull(struct STACK* stackptr)
{
	if (stackptr->top == MAX - 1)
	{
		return 1;
	}
	return 0;
}

int isEmpty(struct STACK* stackptr)
{
	return (stackptr->top == -1);
}

void initStack(struct STACK* stackptr)
{
	stackptr->top = -1;
}

void push(struct STACK* stackptr, int data)
{
	(stackptr->top)++;
	stackptr->arr[stackptr->top] = data;
}

int pop(struct STACK* stackptr)
{
	int num = stackptr->arr[stackptr->top];
	(stackptr->top)--;
	return num;
}

void main()
{
	int choice;
	struct STACK stack;
	initStack(&stack);

	do
	{
		printf("Enter Your Choice: \n");
		printf("0. Exit.\n");
		printf("1. Push.\n");
		printf("2. Pop.\n");
		printf("3. Display.\n");
		printf("Choice = ");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 0:
			printf("Thank You!!!\n");
			break;
		case 1:
			if (isFull(&stack))
			{
				printf("Stack is FULL You can not perform PUSH Operation on it.\n");
			}
			else
			{
				int data;
				printf("Enter a data: ");
				scanf_s("%d", &data);
				push(&stack, data);
			}
			break;
		case 2:
			if (isEmpty(&stack))
			{
				printf("Stack is Empty You can not perform POP Operation on it.\n");
			}
			else
			{
				printf("The value %d is Poped From Stack.\n", pop(&stack));
			}
			break;
		default:
			printf("Please Enter a Valid Choice.\n");
		}
	} while (choice != 0);
}



