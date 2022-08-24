#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int fibo(int* M, int k)
{
	if (k == 1)
		return 1;
	else if (k == 2)
		return 1;
	else {
		if (M[k - 1] == 0)
			M[k - 1] = fibo(M, k - 1);
		if (M[k - 2] == 0)
			M[k - 2] = fibo(M, k - 2);
		return M[k - 1] + M[k - 2];
	}
}

int main(void)
{
	int i, n;
	int* M;

	printf("몇 번째까지의 피보나치 수열: ");
	scanf("%d", &n);
	M = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		M[i] = 0;
	for (i = 1; i <= n; i++)
		printf("%d ", fibo(M, i));
}