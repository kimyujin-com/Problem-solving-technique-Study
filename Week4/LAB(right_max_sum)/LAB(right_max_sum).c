#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

int right_max_sum(int A[], int left, int right) {
	int i, sum = 0, max = INT_MIN;
	for (i = left; i <= right; i++) {
		sum += A[i];
		if (max < sum)
			max = sum;
	}
	return max;
}
int main() {
	int A[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	//int max = right_max_sum(A, 3, 5);// A[3], A[3]+A[4], A[3]+A[4]+A[5] 중에서 최대값 즉, 5
	int max = right_max_sum(A, 3, 4);// A[3], A[3]+A[4] 중에서 최대값 즉, 4
	//int max = right_max_sum(A, 5, 7);// 최대값 3
	printf("max value = %d\n", max);
}