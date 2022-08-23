#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int pick(int* items, int itemSize, int* bucket, int bucketSize, int k, int toPick)
{
	int i, item, smallest, lastIndex, lastSelect = -1, cnt = 0;

	if (toPick == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%d ", items[bucket[i]]);
		printf("\n");
		return ++cnt;
	}

	lastIndex = k - toPick - 1;
	if (toPick == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for (item = smallest; item < itemSize; item++) {
		if (lastSelect == -1 || lastSelect != items[item]) {
			lastSelect = items[item];
			bucket[lastIndex + 1] = item;
			cnt += pick(items, itemSize, bucket, bucketSize, k, toPick - 1);
		}
	}
	return cnt;
}

int main(void)
{
	int i, N, M;
	int* items, *bucket;

	scanf("%d %d", &N, &M);
	items = (int*)malloc(sizeof(int) * N);
	bucket = (int*)malloc(sizeof(int) * M);
	for (i = 0; i < N; i++)
		scanf("%d", &items[i]);
	printf("%d\n", pick(items, N, bucket, M, M, M));
}