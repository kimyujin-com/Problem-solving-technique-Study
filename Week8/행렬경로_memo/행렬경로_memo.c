#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int path(int** M, int** m, int row, int col)
{
	if (row == 0 && col == 0)
		return m[row][col];
	else if (row == 0) {
		if (M[row][col - 1] == 0)
			M[row][col - 1] = path(M, m, row, col - 1);
		return M[row][col - 1] + m[row][col];
	}
	else if (col == 0) {
		if (M[row - 1][col] == 0)
			M[row - 1][col] = path(M, m, row - 1, col);
		return M[row - 1][col] + m[row][col];
	}
	else {
		if (M[row - 1][col] == 0)
			M[row - 1][col] = path(M, m, row - 1, col);
		if (M[row][col - 1] == 0)
			M[row][col - 1] = path(M, m, row, col - 1);
		if (M[row - 1][col] < M[row][col - 1])
			return M[row - 1][col] + m[row][col];
		else
			return M[row][col - 1] + m[row][col];
	}
}

int main(void)
{
	int** m, ** M;
	int i, j, r, c;
	r = c = 4;

	m = (int**)malloc(sizeof(int*) * r);
	M = (int**)malloc(sizeof(int*) * r);

	for (i = 0; i < r; i++) {
		m[i] = (int*)malloc(sizeof(int) * c);
		M[i] = (int*)malloc(sizeof(int) * c);
	}

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++) {
			scanf("%d", &m[i][j]);
			M[i][j] = 0;
		}

	printf("%d\n", path(M, m, r - 1, c - 1));
}