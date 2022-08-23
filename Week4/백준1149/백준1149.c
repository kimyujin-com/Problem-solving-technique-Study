#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int min = INT_MAX;
/**void calculateMin(int** paint, int size, int* choice)
{
	int i, j, minIndex;
	for (i = 0; i < size; i++) {
		minIndex = 0;
		if (i == 0) {
			for (j = 0; j < 3; j++)
				if (paint[i][j] < paint[i][minIndex])
					minIndex = j;
		}
		else {
			minIndex = 
			for (j = 0; j < 3; j++)
				if (choice[i - 1] != j && paint[i][j] < paint[i][minIndex])
					minIndex = j;
		}
		choice[i] = minIndex;
	}
}

int main(void)
{
	int i, j, n, total = 0;
	int** paint;
	int* choice;

	scanf("%d", &n);
	paint = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < 3; i++)
		paint[i] = (int*)malloc(sizeof(int) * 3);
	choice = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &paint[i][j]);
	calculateMin(paint, n, choice);

	for (i = 0; i < n; i++)
		total += choice[i];
	printf("%d\n", total);
}**/
int pick(int** items, int itemSize, int* bucket, int bucketSize, int toPick, int k)
{
	int i, item, lastIndex, sum = 0, minItem = INT_MAX, minIndex = 0;

	if (toPick == 0) {
		for (i = 0; i < bucketSize; i++)
			sum += items[i][bucket[i]];
		return sum;
	}
	lastIndex = k - toPick - 1;
	for (item = 0; item < itemSize; item++) {
		if (lastIndex != -1) {
			for (i = 0; i < itemSize; i++)
				if (bucket[lastIndex] != i && items[lastIndex + 1][i] < minItem) {
					minItem = items[lastIndex + 1][i];
					minIndex = i;
				}
		}
		else
			for (i = 0; i < itemSize; i++)
				if (items[lastIndex + 1][i] < minItem) {
					minItem = items[lastIndex + 1][i];
					minIndex = i;
				}
		bucket[lastIndex + 1] = minIndex;
		sum = pick(items, itemSize, bucket, bucketSize, toPick - 1, k);
		if (sum < min)
			min = sum;
	}
	return min;
}

int main(void)
{
	int i, j, n;
	int** items;
	int* bucket;

	scanf("%d", &n);

	items = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
		items[i] = (int*)malloc(sizeof(int) * 3);
	bucket = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &items[i][j]);
	printf("%d\n", pick(items, 3, bucket, n, n, n));
}