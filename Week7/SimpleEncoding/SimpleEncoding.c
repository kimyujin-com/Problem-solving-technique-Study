#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int getEncodedNumber(int array[], int size)
{
	int i, j, total = 1, max = INT_MIN;
	for (i = 0; i < size; i++) {
		array[i]++;
		total = 1;
		for (j = 0; j < size; j++)
			total *= array[j];
		if (max < total)
			max = total;
		array[i]--;
	}
	return max;
}

int main(void)
{
	int i, n;
	int* bucket;

	scanf("%d", &n);
	bucket = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &bucket[i]);
	printf("%d\n", getEncodedNumber(bucket, 3));
}