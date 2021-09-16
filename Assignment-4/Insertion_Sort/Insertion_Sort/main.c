/*

Que : Write a C program for Insertion Sort
Owner: Rushikesh Sanjay Pokharkar
Batch: PPA9

*/

//                                        *********  Solution  *********


#include<stdio.h> //Include Necessary Header Files.

void insertionSort(int arr[], int n)
{
	// Logic to sort array in ascending order Using Insertion Sort.
	for (int i = 1; i < n; i++)
	{
		int temp = arr[i];
		int empty = i;

		while (empty > 0 && arr[empty - 1] > temp)
		{
			arr[empty] = arr[empty - 1];
			empty--;
		}
		arr[empty] = temp;
	}
}

void main() {

	int arr[100], n, min; // Declaration of required varibales.

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

	printf("\nSorted Array In Ascending Order Using Insertion Sort: ");

	insertionSort(arr, n); // Function call for Insertion sort.

	for (int i = 0; i < n; i++) // For loop to print sorted array..
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
