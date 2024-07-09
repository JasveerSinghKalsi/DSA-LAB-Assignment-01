#include <stdio.h>

// function to sort an array with insertion sort
void insertion_sort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = arr[i];
		int j = i - 1;

		//  Move the elements greater than temp to one position ahead from their current position
		while (j >= 0 && temp <= arr[j])
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = temp;
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
	int a[] = {12, 31, 25, 8, 32, 17};
	int n = sizeof(a) / sizeof(a[0]);

	printf("Before sorting array elements are:\n");
	print_array(a, n);

	insertion_sort(a, n);
	printf("\nAfter sorting array elements are:\n");
	print_array(a, n);

	return 0;
}