#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void selectionSort(int* A, int start, int end)
{
	int i, j, tmp, maxIndex;
	for (i = 0; i < end - start; i++) {
		maxIndex = start;
		for (j = start; j <= end - i; j++)
			if (A[maxIndex] < A[j])
				maxIndex = j;
		tmp = A[maxIndex];
		A[maxIndex] = A[end - i];
		A[end - i] = tmp;
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
	int i, n;
	int* box;

	scanf("%d", &n);

	box = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &box[i]);

	selectionSort(box, 0, n - 1);
	printArray(box, n);
}