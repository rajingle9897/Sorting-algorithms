#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void insertionsort()
{
	int i, j, k, temp, n;
	printf("Enter the no of elements");
	scanf("%d", &n);
	int a[n];
	clock_t t;
	t = clock();
	for (int i = 0; i < n; i++)
		a[i] = (n - 1) - i;

	for (k = 1; k < n; k++)
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

	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC;

	printf("\nSorted sequence:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}


	printf("\nInsertion sort took %f seconds to execute \n", time_taken);
}


int main()
{
	insertionsort();
	return 0;
}