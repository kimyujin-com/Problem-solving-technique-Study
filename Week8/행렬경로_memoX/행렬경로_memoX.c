#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int matrix_path_sum(int** m, int row, int col)
{
	if (row == 0 && col == 0)
		return m[row][col];
	else if (row == 0)
		return matrix_path_sum(m, row, col - 1) + m[row][col];
	else if (col == 0)
		return matrix_path_sum(m, row - 1, col) + m[row][col];
	else
		if (matrix_path_sum(m, row - 1, col) < matrix_path_sum(m, row, col - 1))
			return  matrix_path_sum(m, row - 1, col) + m[row][col];
		else
			return  matrix_path_sum(m, row, col - 1) + m[row][col];
}

int main(void)
{
	int** m;
	int i, j, r, c;
	r = c = 4;

	m = (int**)malloc(sizeof(int*) * r);

	for (i = 0; i < r; i++)
		m[i] = (int*)malloc(sizeof(int) * c);

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			scanf("%d", &m[i][j]);

	printf("%d\n", matrix_path_sum(m, r - 1, c - 1));
}