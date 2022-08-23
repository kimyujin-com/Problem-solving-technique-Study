#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int isSequence(int* A, int start, int end)
{
	int i;
	i = start;
	for (i = start; i < end; i++)
		if (A[i] < A[i + 1])
			return 0;
	return 1;
}

int pivotIndex(int* A, int size)
{
	int i;
	for (i = -1; i < size; i++)
		if (isSequence(A, i + 1, size - 1))
			return i;
}

void bubbleSort(int* A, int start, int end)
{
	int i, j, tmp;
	for (i = 0; i < end - start; i++)
		for (j = start; j < end - i; j++)
			if (A[j + 1] < A[j]) {
				tmp = A[j + 1];
				A[j + 1] = A[j];
				A[j] = tmp;
			}
}

void printArray(int* A, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");

}
int main(void)
{
	int i, n, pivot, min = INT_MAX, minIndex, tmp;
	int* bucket;

	scanf("%d", &n);
	bucket = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &bucket[i]);

	pivot = pivotIndex(bucket, n);
	if (pivot != -1) {
		for (i = pivot + 1; i < n; i++)
			if (bucket[pivot] < bucket[i] && bucket[i] < min) {
				min = bucket[i];
				minIndex = i;
			}

		tmp = bucket[pivot];
		bucket[pivot] = bucket[minIndex];
		bucket[minIndex] = tmp;

		bubbleSort(bucket, pivot + 1, n - 1);
		printArray(bucket, n);
	}
	else
		printf("-1\n");
}