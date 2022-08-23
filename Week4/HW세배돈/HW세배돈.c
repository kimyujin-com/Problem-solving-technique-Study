#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* items, int itemSize, int* bucket, int bucketSize, int toPick, int k, int money)
{
	int i, item, smallest, lastIndex, sum = 0;

	lastIndex = k - toPick - 1;
	for (i = 0; i < lastIndex + 1; i++)
		sum += items[bucket[i]];
	if (sum == money) {
		for (i = 0; i < lastIndex + 1; i++)
			printf("%d ", items[bucket[i]]);
		printf("\n");
		return;
	}
	if (sum > money || toPick == 0)
		return;

	if (toPick == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	for (item = smallest; item < itemSize; item++) {
		bucket[lastIndex + 1] = item;
		pick(items, itemSize, bucket, bucketSize, toPick - 1, k, money);
	}
}

int main(void)
{
	int money, bucketSize;
	int items[3] = { 1000, 5000, 10000 };
	int * bucket;

	scanf("%d", &money);
	bucketSize = money / 1000;
	bucket = (int*)malloc(sizeof(int) * bucketSize);
	pick(items, 3, bucket, bucketSize, bucketSize, bucketSize, money);
}