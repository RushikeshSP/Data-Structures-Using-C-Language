/*

Que : Write a C program for selection Sort
Owner: Rushikesh Sanjay Pokharkar
Batch: PPA9

*/

//                                        *********  Solution  *********


#include<stdio.h> //Include Necessary Header Files.

void selectionSort(int arr[], int n)
{
	// Logic to sort array in ascending order Using Selection Sort.
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
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

	printf("\nSorted Array In Ascending Order Using Selection Sort: ");

	selectionSort(arr, n); // Function call for selection sort.

	for (int i = 0; i < n; i++) // For loop to print sorted array..
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}