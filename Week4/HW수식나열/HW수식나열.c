#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* items, int itemSize, int* bucket, int bucketSize, int toPick, int k)
{
	int i, item, smallest, lastIndex, sum = 0;

	if (toPick == 0) {
		for (i = 0; i < bucketSize; i++)
			if (bucket[i] == 0) {
				printf("+%d", (i + 1));
				sum += (i + 1);
			}
			else {
				printf("-%d", (i + 1));
				sum -= (i + 1);
			}
		printf(" = %d\n", sum);
		return;
	}

	lastIndex = k - toPick - 1;
	smallest = 0;

	for (item = smallest; item < itemSize; item++) {
		bucket[lastIndex + 1] = item;
		pick(items, itemSize, bucket, bucketSize, toPick - 1, k);
	}
}

int main(void)
{
	int n;
	int items[2] = { 0, 1 };
	int *bucket;

	scanf("%d", &n);
	bucket = (int*)malloc(sizeof(int) * n);
	pick(items, 2, bucket, n, n, n);
}