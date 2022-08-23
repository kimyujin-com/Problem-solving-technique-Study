#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int f(int* bucket, int* input, int k, int size)
{
	int i, flag = 0, min = INT_MAX, minIndex;
	//input에는 뒤에 나보다 큰 애가 몇 개 있는지 파악
	// 1 4 2 3 5 // 5 1 2 3 4 // 4 2 6 2 8 2
	if (k == size - 1)
		return 1;
	for (i = k + 1; i < size; i++) {
		if (input[i] == 1)
			input[i] = f(bucket, input, i, size);
		if (bucket[k] < bucket[i]) {// 2 6 4 5
			if (bucket[i] < min) {
				flag = 1;
				min = bucket[i];
				minIndex = i;
			}
		}
	}
	if (flag)
		return 1 + input[minIndex];
	else
		return input[k];
}

int main(void)
{
	int i, N, max = -1;
	int* bucket, *input;

	scanf("%d", &N);
	bucket = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++)
		scanf("%d", &bucket[i]);

	if (N == 1)
		printf("1\n");
	else{
		input = (int*)malloc(sizeof(int) * N);
		for (i = 0; i < N; i++)
			input[i] = 1;
		input[0] = f(bucket, input, 0, N);
		for (i = 0; i < N; i++)
			if (max < input[i])
				max = input[i];
		//for (i = 0; i < N; i++)
			//printf("%d ", input[i]);
		printf("%d\n", max);
	}
}