#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void bubbleSort1(int** A, int start, int end)
{
	int i, j, tmp;

	for (i = 0; i < end - start; i++)
		for (j = start; j < end - i; j++)
			if (A[j + 1][0] < A[j][0]) {
				tmp = A[j + 1][0];
				A[j + 1][0] = A[j][0];
				A[j][0] = tmp;
				tmp = A[j + 1][1];
				A[j + 1][1] = A[j][1];
				A[j][1] = tmp;
			}
}

void bubbleSort2(int** A, int start, int end)
{
	int i, j, tmp;

	for (i = 0; i < end - start; i++)
		for (j = start; j < end - i; j++)
			if (A[j + 1][1] < A[j][1]) {
				tmp = A[j + 1][1];
				A[j + 1][1] = A[j][1];
				A[j][1] = tmp;
			}
}

void printList(int** a, int size)
{
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < 2; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int i, j, n, tmpN;
	int** box;

	scanf("%d", &n);
	box = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
		box[i] = (int*)malloc(sizeof(int) * 2);

	for (i = 0; i < n; i++)
		for (j = 0; j < 2; j++)
			scanf("%d", &box[i][j]);

	bubbleSort1(box, 0, n - 1);
	i = 0;
	while (i < n) {
		tmpN = box[i][0];
		j = i;
		while (box[j][0] == tmpN) {
			j++;
			if (j >= n)
				break;
		}
		if (i < j - 1)
			bubbleSort2(box, i, j - 1);
		i = j;
	}
	printList(box, n);
}