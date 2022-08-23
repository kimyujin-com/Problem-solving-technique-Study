#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void printArray(int* A, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

void bubbleSort(int* A, int start, int end)
{
	int i, j, tmp, flag;
	for (i = 0; i < end - start; i++) {
		flag = 0;
		for (j = start; j < end - i; j++)
			if (A[j + 1] < A[j]) {
				flag = 1;
				tmp = A[j + 1];
				A[j + 1] = A[j];
				A[j] = tmp;
			}
		if (flag == 0)
			return;
		printf("i = %d: ", i);
		printArray(A, end + 1);
	}
}

int main(void)
{
	int i, n;
	int* box;

	scanf("%d", &n);

	printf("초기: ");
	box = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &box[i]);

	bubbleSort(box, 0, n - 1);
	printf("정렬: ");
	printArray(box, n);
}