#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* items, int itemSize, int* bucket, int bucketSize, int toPick, int k)
{
	int i, item, smallest, lastIndex;

	if (toPick == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%d", items[bucket[i]]);
		printf("\n");
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
	int i, n;
	int* items, * bucket;

	scanf("%d", &n);
	items = (int*)malloc(sizeof(int) * 4);
	for (i = 0; i < 4; i++)
		items[i] = i;
	bucket = (int*)malloc(sizeof(int) * n);
	pick(items, 4, bucket, n, n, n);
}