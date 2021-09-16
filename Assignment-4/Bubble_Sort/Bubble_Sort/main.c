/*

Que : Write a C program for Bubble Sort
Owner: Rushikesh Sanjay Pokharkar
Batch: PPA9

*/

//                                        *********  Solution  *********


#include<stdio.h> //Include Necessary Header Files.

void bubbleSort(int arr[], int n)
{
	// Logic to sort array in ascending order Using Bubble Sort.
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void main() {

	int arr[100], n; // Declaration of required varibales.

	printf("How many Elements do you want in array?\n");
	scanf_s("%d", &n); // Take input - Number of array elements.

	printf("Enter Array Elements: \n");
	for (int i = 0; i < n; i++) // For loop to take input array elements.
	{
		scanf_s("%d", &arr[i]);
	}

	printf("Unsorted Array Elements are: ");

	for (int i = 0; i < n; i++) // For loop to print array elements.
	{
		printf("%d ", arr[i]);
	}

	printf("\nSorted Array In Ascending Order Using Bubble Sort: ");

	bubbleSort(arr, n); // function call for bubble sort

	for (int i = 0; i < n; i++) // For loop to print sorted array..
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}