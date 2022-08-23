#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int H(int* M, int n)
{
	int i, result = 0;
	if (n == 0 || n == 1)
		return 1;
	else
		for (i = 0; i < n; i++) {
			if (M[i] == 0)
				M[i] = H(M, i);
			if (M[n - i - 1] == 0)
				M[n - i - 1] = H(M, n - i - 1);
			result += M[i] * M[n - i - 1];
		}
	return result;
}

int main(void)
{
	int i, n;
	int* M;

	scanf("%d", &n);
	M = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		M[i] = 0;
	printf("%d\n", H(M, n - 1));
}