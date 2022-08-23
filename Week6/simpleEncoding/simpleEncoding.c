#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
	int i, N, max = INT_MIN, maxIndex = -1;
	double tmp;
	int* bucket;

	scanf("%d", &N);

	bucket = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++)
		scanf("%d", &bucket[i]);

	for (i = 0; i < N; i++) {
		tmp = (double)((bucket[i] + 1) / bucket[i]);
		if (max < tmp) {
			max = tmp;
			maxIndex = i;
		}
	}
	printf("%d\n", maxIndex);
}