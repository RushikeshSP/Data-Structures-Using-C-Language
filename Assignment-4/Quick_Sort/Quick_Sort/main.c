/*

Que : Write a C program for Quick Sort
Owner: Rushikesh Sanjay Pokharkar
Batch: PPA9

*/

//                                        *********  Solution  *********


#include<stdio.h> //Include Necessary Header Files.

void quickSort(int arr[], int L, int H)
{
	// Logic to sort array in ascending order Using Quick Sort.
	int low = L + 1;
	int high = H;
	int pivot = arr[L];

	while (low <= high)
	{
		while (arr[low] < pivot)
		{
			low++;
		}
		while (arr[high] > pivot)
		{
			high--;
		}
		if (low <= high)
		{
			int temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
			low++;
			high--;
		}
	}
	int temp = arr[L];
	arr[L] = arr[high];
	arr[high] = temp;

	if (L<high && L != high-1)
	{
		quickSort(arr, L, high - 1);
	}
	if (low<H && low != H)
	{
		quickSort(arr, low, H);
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

	printf("\nSorted Array In Ascending Order Using Quick Sort: ");

	quickSort(arr, 0, n-1); // Function call for Insertion sort.

	for (int i = 0; i < n; i++) // For loop to print sorted array..
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
