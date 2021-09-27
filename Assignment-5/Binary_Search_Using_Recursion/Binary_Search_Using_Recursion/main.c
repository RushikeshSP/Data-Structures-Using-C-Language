/*

Que : Write a C program for Binary Search Using Recursion
Owner: Rushikesh Sanjay Pokharkar
Batch: PPA9

*/

//                                        *********  Solution  *********


#include<stdio.h> //Include Necessary Header Files.


void merge(int arr[], int low, int mid, int high) // Function to sort the array.
{
	int temp_arr[100];
	int i = low, j = mid + 1, k = 0;

	while (i <= mid && j <= high)
	{
		if (arr[i] < arr[j])
		{
			temp_arr[k] = arr[i];
			i++, k++;
		}
		else
		{
			temp_arr[k] = arr[j];
			j++, k++;
		}
	}
	while (i <= mid)
	{
		temp_arr[k] = arr[i];
		i++, k++;
	}while (j <= high)
	{
		temp_arr[k] = arr[j];
		j++, k++;
	}

	for (int i = low, j = 0; i <= high; i++, j++)
	{
		arr[i] = temp_arr[j];
	}
}

void mergeSort(int arr[], int low, int high)
{
	// Logic to sort array in ascending order Using Merge Sort.
	if (low < high)
	{
		int mid = (low + high) / 2;
		if (low != mid)
		{
			mergeSort(arr, low, mid); // function call to divide first half of array.
		}
		if (mid + 1 != high)
		{
			mergeSort(arr, mid + 1, high); // Function call to divide second half of array.
		}
		merge(arr, low, mid, high);	// Function call to merge to sorted halfs of the array.
	}
}


int binarySearch(int arr[], int low, int high, int num)
{
	// Logic of binary search Using recursion.
	if (num >= arr[low] && num <= arr[high])
	{
		int mid = (low + high) / 2;
		if (arr[mid] == num)
		{
			return 1;
		}
		else if (num < arr[mid])
		{
			return binarySearch(arr, low, mid - 1, num);
		}
		else
		{
			return binarySearch(arr, mid + 1, high, num);
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


	mergeSort(arr, 0, n - 1); // Function call to sort the array.

	printf("Sorted Array Elements are: ");

	for (int i = 0; i < n; i++) // For loop to print array elements.
	{
		printf("%d ", arr[i]);
	}
	printf("\n");


	printf("Enter a number to search in given array: ");
	scanf_s("%d", &num);

	int result = binarySearch(arr, 0, n - 1, num); // Function call for binary Search using recursion.

	if (result)
	{
		printf("Given element %d is present in the array.\n", num);
	}
	else
	{
		printf("Given element %d is not present in the array.\n", num);
	}

}
