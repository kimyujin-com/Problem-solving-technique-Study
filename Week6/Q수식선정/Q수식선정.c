#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int pick(int* items, int itemSize, int* bucket, int bucketSize, int k, int toPick, int N)
{
	int i, item, lastIndex, smallest, sum = 0, cnt = 0;

	lastIndex = k - toPick - 1;
	for (i = 0; i < lastIndex + 1; i++)
		sum += bucket[i] * (i + 1);
	if (sum == N) 
		return 1;
	if (toPick == 0)
		return 0;
	
	smallest = 0;
	for (item = smallest; item < itemSize; item++) {
		bucket[lastIndex + 1] = items[item];
		cnt += pick(items, itemSize, bucket, bucketSize, k, toPick - 1, N);
		if (cnt == 1)
			break;
	}
	return cnt;
}

int main(void)
{
	int i, j, n, sum = 0;
	int items[2] = { 1, -1 };
	int* bucket;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		bucket = (int*)malloc(sizeof(int) * i);
		if (pick(items, sizeof(items) / sizeof(int), bucket, i, i, i, n)) {
			for (j = 0; j < i; j++) {
				if (bucket[j] == 1)
					printf("+%d", bucket[j] * (j + 1));
				else
					printf("%d", bucket[j] * (j + 1));
				sum += bucket[j] * (j + 1);
			}
			//printf(" = %d\n", sum);
			break;
		}
	}

}