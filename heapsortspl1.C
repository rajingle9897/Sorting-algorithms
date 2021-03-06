#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int temp;

void heapify(int arr[], int size, int i)
{
	int largest = i;
	int left = 2 * i;
	int right = 2 * i + 1;

	if (left < size && arr[left] > arr[largest])
		largest = left;

	if (right < size && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		heapify(arr, size, largest);
	}
}

void heapSort(int arr[], int size)
{
	int i;
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i);
	for (i = size - 1; i >= 0; i--)
	{
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr, i, 0);
	}
}

int main()
{
	int i, n;
	printf("Enter the no of elements");
	scanf("%d", &n);
	clock_t t;
	t = clock();
	int arr[n];
	for (int i = 0; i < n; i++)
		arr[i] = i;
	int size = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, size);



	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC;

	printf("printing sorted elements\n");
	for (i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	printf("\nHeapsort() took %f seconds to execute \n", time_taken);
}