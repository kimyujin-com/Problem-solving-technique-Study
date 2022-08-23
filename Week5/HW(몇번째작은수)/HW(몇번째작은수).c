#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int A[], int p, int r) {
	int i, j, k, tmp;
	i = p - 1, j = p;
	for (k = p; k < r; k++)
		if (A[k] > A[r]) {
			j++;
		}
		else if (A[k] < A[r]) {
			tmp = A[++i];
			A[i] = A[k];
			A[k] = tmp;
			j++;
		}
	tmp = A[++i];
	A[i] = A[r];
	A[r] = tmp;
	return i;
}

int quickSort(int A[], int p, int r, int smallN)
{
	int q;
	if (p <= r) {
		q = partition(A, p, r);
		if (smallN == q)
			return A[q];
		else if (smallN < q)
			quickSort(A, p, q - 1, smallN);
		else
			quickSort(A, q + 1, r, smallN);
	}
}

void printList(int A[], int s, int e)
{
	int i;
	for (i = s; i <= e; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main(void)
{
	int i, n, smallN;
	int* bucket;

	scanf("%d", &n);
	scanf("%d", &smallN);

	bucket = (int*)malloc(sizeof(int) * n);
	srand(time(NULL));
	for (i = 0; i < n; i++)
		bucket[i] = rand() % 100;

	printList(bucket, 0, n - 1);
	printf("%d\n", quickSort(bucket, 0, n - 1, smallN - 1));
}