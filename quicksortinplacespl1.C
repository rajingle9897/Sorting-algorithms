#include <stdio.h>
#include<time.h>
#include<stdlib.h>

int partition(int a[], int beg, int end);
void quicksort(int a[], int beg, int end);

int partition(int a[], int beg, int end)
{

	int left, right, temp, piv, c;
	piv = left = beg;
	right = end;
	c = 0;
	while (c != 1)
	{
		while ((a[piv] <= a[right]) && (piv != right))
			right--;
		if (piv == right)
			c = 1;
		else if (a[piv] > a[right])
		{
			temp = a[piv];
			a[piv] = a[right];
			a[right] = temp;
			piv = right;
		}
		if (c != 1)
		{
			while ((a[piv] >= a[left]) && (piv != left))
				left++;
			if (piv == left)
				c = 1;
			else if (a[piv] < a[left])
			{
				temp = a[piv];
				a[piv] = a[left];
				a[left] = temp;
				piv = left;
			}
		}
	}
	return piv;
}
void quicksort(int a[], int beg, int end)
{

	int piv;
	if (beg < end)
	{
		piv = partition(a, beg, end);
		quicksort(a, beg, piv - 1);
		quicksort(a, piv + 1, end);
	}
}


int main()
{
	int i, n;
	printf("Enter the no of elements");
	scanf("%d", &n);
	int arr[n];
	clock_t t;
	t = clock();
	for (i = 0; i < n; i++)
		arr[i] = i;
	quicksort(arr, 0, n - 1);


	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC;
	printf("\nSorted sequence:\n");

	for (i = 0; i < n; i++)
		printf(" %d\t", arr[i]);
	printf("\nQuicksortinplace took %f seconds to execute \n", time_taken);

	return 0;
}

