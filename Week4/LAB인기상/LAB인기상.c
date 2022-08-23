#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(char items[][10], int itemSize, int* bucket, int bucketSize, int toPick, int k)
{
	int i, item, smallest, lastIndex;

	if (toPick == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%8s ", items[bucket[i]]);
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
	int n;
	char items[5][10] = { "공유", "김수현", "송중기", "지성", "현빈" };
	int * bucket;

	scanf("%d", &n);
	bucket = (int*)malloc(sizeof(int) * n);
	pick(items, 5, bucket, n, n, n);
}