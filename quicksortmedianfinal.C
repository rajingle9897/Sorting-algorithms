#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void *__gxx_personality_v0;

void insertionsort(int a[], int left, int right);

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
	return ;
}

int median(int a[], int left, int right)
{
	int center = (left + right) / 2;
	if (a[center] < a[left])
		swap(&a[left], &a[center]);
	if (a[right] < a[left])
		swap(&a[left], &a[right]);
	if (a[right] < a[center])
		swap(&a[center], &a[right]);

	swap(&a[center], &a[right - 1]);
	return a[right - 1];
}

void quicksort(int a[], int left, int right)
{
	if (left + 10 <= right)
	{
		int pivot = median(a, left, right);
		if (left == right - 1) return;
		int i = left;
		int j = right - 1;
		for ( ; ;)
		{
			while (a[++i] < pivot) {}
			while (pivot < a[--j]) {}
			if ( i < j)
				swap(&a[i], &a[j]);
			else
				break ;
		}
		swap(&a[i], & a[right - 1]);
		quicksort(a, left, i - 1);
		quicksort(a, i + 1, right);
	}
	else
	{
		insertionsort(a, left, right);
	}
	return ;
}

void insertionsort(int a[], int left, int right)
{
	int i, j, k, temp;

	for (k = left + 1; k <= right; k++)
	{
		temp = a[k];
		j = k - 1;
		while (j >= 0 && temp <= a[j])
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = temp;
	}
}


int main()
{
	int i, n;
	printf("Enter no of elements");
	scanf("%d", &n);
	clock_t t;
	t = clock();
	int a[n];
	for (i = 0; i < n; i++)
		a[i] = rand();
	quicksort(a, 0, n - 1);
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC;

	printf("Sorted sequence:");
	for (i = 0 ; i < n ; i++)
		printf("%d ", a[i]);


	printf("\nSorting took %f seconds to execute \n", time_taken);
}