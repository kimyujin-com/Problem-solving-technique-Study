#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int fibo(int k, int n, int* M)
{
	int i, total = 0;
	if (n <= k)
		return 1;
	else
		for (i = 1; i <= k; i++) {
			if (M[n - i] == 0)
				M[n - i] = fibo(k, n - i, M);
			total += M[n - i];
		}
	return total;
}

int main(void) 
{
	int i, k, n;
	int* M;

	scanf("%d %d", &k, &n);
	M = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		M[i] = 0;
	printf("%d\n", fibo(k, n, M));
}