#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(char* items, int itemSize, char* bucket, int bucketSize, int toPick, int k)
{
	int i, item, smallest, lastIndex;

	if (toPick == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%c ", items[bucket[i]]);
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
	int i;
	char* items, * bucket;

	items = (char*)malloc(sizeof(char) * 7);
	for (i = 0; i < 7; i++)
		items[i] = 'A' + i;
	bucket = (char*)malloc(sizeof(char) * 3);
	pick(items, 7, bucket, 3, 3, 3);
}