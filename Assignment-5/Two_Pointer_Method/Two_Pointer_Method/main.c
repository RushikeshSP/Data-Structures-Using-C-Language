/*

Que : Write a C program for Two Pointer Method for searching of element in array.
Owner: Rushikesh Sanjay Pokharkar
Batch: PPA9

*/

//                                        *********  Solution  *********


#include<stdio.h> //Include Necessary Header Files.


int twoPointerMethod(int arr[], int n, int num)
{
	// Logic of Two Pointer Method
	int low = 0, high = n-1;
	while (low <= high)
	{
		if (arr[low] == num || arr[high] == num)
		{
			return 1;
		}
		low++, high--;
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

	int result = twoPointerMethod(arr, n, num); // Function call for Two Pointer Method

	if (result)
	{
		printf("Given element %d is present in the array.\n", num);
	}
	else
	{
		printf("Given element %d is not present in the array.\n", num);
	}

}
