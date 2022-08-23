#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int pick(int* items, int itemSize, int* bucket, int bucketSize, int k, int toPick)
{
	int i, item, cnt = 0, smallest, lastIndex, lastSelect = -1, flag;

	if (toPick == 0)
		return ++cnt;

	lastIndex = k - toPick - 1;
	smallest = 0;

	for (item = smallest; item < itemSize; item++) {
		flag = 0;
		for (i = 0; i < lastIndex + 1; i++)
			if (bucket[i] == item) {
				flag = 1;
				break;
			}
				
		if (flag == 0 && lastSelect != items[item]) {
			bucket[lastIndex + 1] = item;//일부러 인덱스를 넣어주자
			lastSelect = items[item];
			cnt += pick(items, itemSize, bucket, bucketSize, k, toPick - 1);
		}
	}
	return cnt;
}

int main(void)
{
	int i, j, k = 0, N, numOf00, cnt = 0;
	int* items, *bucket;

	scanf("%d", &N);

	numOf00 = N / 2;

	for (i = 0; i <= numOf00; i++) {
		k = 0;
		items = (int*)malloc(sizeof(int) * (N - i));
		bucket = (int*)malloc(sizeof(int) * (N - i));
		for (j = 0; j < i; j++)
			items[k++] = 0; //00대신에
		for (j = 0; j < N - 2 * i; j++)
			items[k++] = 1; 
		cnt += pick(items, N - i, bucket, N - i, N - i, N - i);
	}
	printf("%d\n", cnt);
}