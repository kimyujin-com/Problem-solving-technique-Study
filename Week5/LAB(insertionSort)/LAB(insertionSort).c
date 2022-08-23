#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int* box, int size)
{
	int i, j, k, tmp;
	for (i = 0; i < size; i++)
		for (j = 0; j < i; j++)
			if (box[i] < box[j]) {
				tmp = box[i];
				for (k = i - 1; k >= j; k--)
					box[k + 1] = box[k];
				box[j] = tmp;
			}
}

void printArray(int* box, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", box[i]);
	printf("\n");
}

int main(void)
{
	int i, n;
	int* box;

	scanf("%d", &n);

	box = (int*)malloc(sizeof(int) * n);
	srand(time(NULL));
	for (i = 0; i < n; i++)
		box[i] = rand() % 100;

	insertionSort(box, n);
	printArray(box, n);
}