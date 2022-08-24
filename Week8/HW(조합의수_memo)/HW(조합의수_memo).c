#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int comb(int** M, int n, int r)
{
	if (r == 0 || r == n)
		return 1;
	else {
		if (M[n - 1][r - 1] == 0)
			M[n - 1][r - 1] = comb(M, n - 1, r - 1);
		if (M[n - 1][r] == 0)
			M[n - 1][r] = comb(M, n - 1, r);
		return M[n - 1][r - 1] + M[n - 1][r];
	}
}

int main(void)
{
	int i, j, n, r;
	int** M;

	scanf("%d %d", &n, &r);

	M = (int**)malloc(sizeof(int*) * n + 1);
	for (i = 0; i < n + 1; i++)
		M[i] = (int*)malloc(sizeof(int) * r + 1);
	for (i = 0; i < n + 1; i++)
		for (j = 0; j < r + 1; j++)
			M[i][j] = 0;
	printf("%d\n", comb(M, n, r));
}