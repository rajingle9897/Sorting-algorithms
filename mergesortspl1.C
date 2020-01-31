#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void mergesort(int[], int, int);
void merge(int[], int, int, int);
int i, n, m;
void mergesort(int a[], int beg, int end)
{
	int mid;
	if (beg < end)
	{
		mid = (beg + end) / 2;
		mergesort(a, beg, mid);
		mergesort(a, mid + 1, end);
		merge(a, beg, mid, end);
	}

}
void merge(int a[], int beg, int mid, int end)
{
	int i = beg, j = mid + 1, k, x = beg;
	int temp[m];
	while (i <= mid && j <= end)
	{
		if (a[i] < a[j])
		{
			temp[x] = a[i];
			i = i + 1;
		}
		else
		{
			temp[x] = a[j];
			j = j + 1;
		}
		x++;
	}
	if (i > mid)
	{
		while (j <= end)
		{
			temp[x] = a[j];
			x++;
			j++;
		}
	}
	else
	{
		while (i <= mid)
		{
			temp[x] = a[i];
			x++;
			i++;
		}
	}
	k = beg;
	while (k < x)
	{
		a[k] = temp[k];
		k++;
	}
}
int main ()
{	int n;
	printf("Enter the no of elements");
	scanf("%d", &n);
	int a[n];
	m = n;
	clock_t t;
	t = clock();
	for (int i = 0; i < n; i++)
		a[i] = i;
	mergesort(a, 0, n - 1);

	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC;
	printf("\nSorted sequence:\n");
	for (i = 0; i < n; i++)
	{
		printf(" %d ", a[i]);
	}
	printf("\nMerge Sort took %f seconds to execute \n", time_taken);
	return 0;

}
