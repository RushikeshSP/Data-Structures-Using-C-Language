/*

Que : Write a C program for Linear Search
Owner: Rushikesh Sanjay Pokharkar
Batch: PPA9

*/

//                                        *********  Solution  *********


#include<stdio.h> //Include Necessary Header Files.


int linearSearch(int arr[], int n, int num) 
{
	// Logic of linear search
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == num)
		{
			return 1;
		}
	}
	return 0;
}

void main() {

	int arr[100], n, num; // Declaration of required varibales.

	printf("How many Elements do you want in array?\n");
	scanf_s("%d", &n); // Take input - Number of array elements.

	printf("Enter Array Elements: \n");
	for (int i = 0; i < n; i++) // For loop to take input array elements.
	{
		scanf_s("%d", &arr[i]);
	}

	printf("Array Elements are: ");

	for (int i = 0; i < n; i++) // For loop to print array elements.
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("Enter a number to search in given array: ");
	scanf_s("%d", &num);

	int result = linearSearch(arr, n, num); // Function call for Linear Search
	
	if (result)
	{
		printf("Given element %d is present in the array.\n", num);
	}
	else
	{
		printf("Given element %d is not present in the array.\n", num);
	}

}
