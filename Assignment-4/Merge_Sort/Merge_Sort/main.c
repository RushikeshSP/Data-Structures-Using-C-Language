/*

Que : Write a C program for Merge Sort
Owner: Rushikesh Sanjay Pokharkar
Batch: PPA9

*/

//                                        *********  Solution  *********


#include<stdio.h> //Include Necessary Header Files.


void merge(int arr[], int low, int mid, int high) // Function to sort the array.
{
	int temp_arr[100] ;
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

	for (int i = low, j = 0; i <= high; i++,j++)
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

	printf("\nSorted Array In Ascending Order Using Merge Sort: ");

	mergeSort(arr, 0, n - 1); // Function call for Merge sort.

	for (int i = 0; i < n; i++) // For loop to print sorted array..
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
