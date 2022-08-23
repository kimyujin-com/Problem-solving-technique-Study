#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* items, int itemSize, int* bucket, int bucketSize, int toPick, int k)
{
	int i, item, smallest, lastIndex;
	
	if (toPick == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%d ", bucket[i]);
		printf("\n");
		return;
	}

	lastIndex = k - toPick - 1;
	if (toPick == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for (item = smallest; item < itemSize; item++) {
		bucket[lastIndex + 1] = item;
		pick(items, itemSize, bucket, bucketSize, toPick - 1, k);
	}
}

int main(void)
{
	int i, n, m;
	int* items, *bucket;

	scanf("%d %d", &n, &m);

	items = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		items[i] = i;
	bucket = (int*)malloc(sizeof(int) * m);
	pick(items, n, bucket, m, m, m);
}