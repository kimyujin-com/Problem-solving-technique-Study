#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int* A, int n)
{
	int i, j, tmp;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (A[j + 1] < A[j]) {
				tmp = A[j + 1];
				A[j + 1] = A[j];
				A[j] = tmp;
			}
}

int main(void)
{
	int i, j, k, n, tmp, flag;
	int* box, *tmpBox;
	int order[1000001];

	scanf("%d", &n);
	tmpBox = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &tmpBox[i]);
	box = (int*)malloc(sizeof(int) * n);

	k = 0;
	for (i = 0; i < n; i++) {
		tmp = tmpBox[i];
		flag = 0;
		for (j = 0; j < k; j++)
			if (box[j] == tmp) {
				flag = 1;
				break;
			}
		if (!flag)
			box[k++] = tmp;
	}
	bubbleSort(box, k);
	for (i = 0; i < k; i++)
		order[box[i]] = i;
	for (i = 0; i < n; i++)
		printf("%d ", order[tmpBox[i]]);
}