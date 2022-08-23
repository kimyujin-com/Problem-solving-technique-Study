#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void merge(int* A, int p, int q, int r)//☆시작점은 p
{
	int* tmp;
	int i = 0, j, k;
	tmp = (int*)malloc(sizeof(int) * (r - p + 1));

	j = p;
	k = q + 1;
	while (j < q + 1 && k < r + 1)
		if (A[j] < A[k])
			tmp[i++] = A[j++];
		else
			tmp[i++] = A[k++];
	while (j < q + 1)
		tmp[i++] = A[j++];
	while (k < r + 1)
		tmp[i++] = A[k++];

	i = 0;
	for (j = p; j <= r; j++)
		A[j] = tmp[i++];
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