#include <stdio.h>
#include <stdlib.h>

// Function to merge the subarrays of a[]
void merge(int arr[], int beg, int mid, int end)
{
	int i, j, k;
	int n1 = mid - beg + 1;
	int n2 = end - mid;
	int *leftArray = malloc(n1 * sizeof(int));	// Temporary arrays
	int *rightArray = malloc(n2 * sizeof(int)); // Temporary arrays
	if (!leftArray || !rightArray)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		exit(1);
	}

	// Copy data to temp arrays
	for (int i = 0; i < n1; i++)
	{
		leftArray[i] = arr[beg + i];
	}
	for (int j = 0; j < n2; j++)
	{
		rightArray[j] = arr[mid + 1 + j];
	}
	i = 0;	 // Initial index of first sub-array
	j = 0;	 // initial index of second sub-array
	k = beg; // initial index of merged sub-array
	while (i < n1 && j < n2)
	{
		if (leftArray[i] <= rightArray[j])
		{
			arr[k] = leftArray[i];
			i++;
		}
		else
		{
			arr[k] = rightArray[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = leftArray[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = rightArray[j];
		j++;
		k++;
	}
	free(leftArray);
    free(rightArray);
}

void mergeSort(int arr[], int beg, int end)
{
	if (beg < end)
	{
		int mid = beg + (end - beg) / 2;
		mergeSort(arr, beg, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, beg, mid, end);
	}
}

void print_array(int arr[], int n)
{
	printf("|");
	for (int i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
		if (i != n - 1)
		{
			printf("\t");
		}
	}
	printf("|\n");
}

int main()
{
	int arr[] = {12, 31, 25, 8, 32, 17, 40, 42};
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Before sorting array elements are:\n");
	print_array(arr, n);

	mergeSort(arr, 0, n - 1);
	printf("After sorting array elements are:\n");
	print_array(arr, n);

	return 0;
}