#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int f(int* bucket, int* input, int k)
{
	int tmp, max = INT_MIN;

	if (k == 0)
		return bucket[k];
	else if (k == 1)
		return bucket[k] + bucket[k - 1];
	//현재 잔과 다음 잔을 마시는 경우
	if (k >= 3) {
		if (input[k - 3] == 0)
			input[k - 3] = f(bucket, input, k - 3);
		tmp = bucket[k] + bucket[k - 1] + input[k - 3];
	}
	else
		tmp = bucket[k] + bucket[k - 1];
	if (max < tmp) max = tmp;
	//바로 다음 잔을 마시지 않는 경우
	if (input[k - 2] == 0)
		input[k - 2] = f(bucket, input, k - 2);
	tmp = bucket[k] + input[k - 2];
	if (max < tmp) max = tmp;
	//현재 잔을 안 마시는 경우
	if (input[k - 1] == 0)
		input[k - 1] = f(bucket, input, k - 1);
	tmp = input[k - 1];
	if (max < tmp) max = tmp;
	return max;
}

int main(void)
{
	int i, n;
	int* bucket, *input;

	scanf("%d", &n);
	bucket = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &bucket[i]);
	input = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		input[i] = 0;
	printf("%d\n", f(bucket, input, n - 1));
}
/*
10

0
0
10
0
5
10
0
0
1
10
ans: 36 // output: 31
https://blog.naver.com/tmdalstjdgh/222706596813
*/