#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int A[], int p, int q, int r)
{
	int i, j, k;
	int* tmp;

	tmp = (int*)malloc(sizeof(int) * (r - p + 1));

	i = p, j = q + 1, k = 0;
	while (i <= q && j <= r)
		if (A[i] < A[j])
			tmp[k++] = A[i++];
		else
			tmp[k++] = A[j++];

	while (i <= q)
		tmp[k++] = A[i++];
	while (j <= r)
		tmp[k++] = A[j++];

	i = p, k = 0;
	while (i <= r)
		A[i++] = tmp[k++];
}

void mergeSort(int* A, int p, int r)
{
	int q;
	if (p < r) {
		q = (p + r) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

void printArray(int* A, int p, int r)
{
	int i;
	for (i = p; i <= r; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main(void)
{
	int i, n;
	int* bucket;

	scanf("%d", &n);

	bucket = (int*)malloc(sizeof(int) * n);
	srand(time(NULL));
	for (i = 0; i < n; i++)
		bucket[i] = rand() % 1000;

	printArray(bucket, 0, n - 1);
	mergeSort(bucket, 0, n - 1);
	printArray(bucket, 0, n - 1);
}