#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int pick(int* items, int itemSize, int* bucket, int bucketSize, int toPick, int k, int money)
{
	int i, item, lastIndex, smallest, sum = 0, cnt = 0;

	lastIndex = k - toPick - 1;
	for (i = 0; i < lastIndex + 1; i++)
		sum += items[bucket[i]];
	if (sum == money) {
		/**for (i = 0; i < lastIndex + 1; i++)
			printf("%d ", items[bucket[i]]);
		printf("\n");**/
		return ++cnt;
	}
	if (sum > money || toPick == 0)
		return cnt;

	if (toPick == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	for (item = smallest; item < itemSize; item++) {
		bucket[lastIndex + 1] = item;
		cnt += pick(items, itemSize, bucket, bucketSize, toPick - 1, k, money);
	}
	return cnt;
}

int main(void)
{
	int money, bucketSize;
	int items[4] = { 10, 50, 100, 500 };
	int* bucket;

	scanf("%d", &money);
	bucketSize = money / 10;
	bucket = (int*)malloc(sizeof(int) * bucketSize);
	printf("%d\n", pick(items, 4, bucket, bucketSize, bucketSize, bucketSize, money));
}