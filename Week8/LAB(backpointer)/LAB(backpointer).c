#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int matrixPath(int i, int j, int** M, int** m, char** BP)
{
	if (i == 0 && j == 0) {
		BP[i][j] = 'S';
		return m[i][j];
	}
	else if (i == 0) {
		BP[i][j] = 'L';
		if (M[i][j - 1] == 0)
			M[i][j - 1] = matrixPath(i, j - 1, M, m, BP);
		return M[i][j - 1] + m[i][j];
	}
	else if (j == 0) {
		BP[i][j] = 'U';
		if (M[i - 1][j] == 0)
			M[i - 1][j] = matrixPath(i - 1, j, M, m, BP);
		return M[i - 1][j] + m[i][j];
	}
	else {
		if (M[i][j - 1] == 0)
			M[i][j - 1] = matrixPath(i, j - 1, M, m, BP);
		if (M[i - 1][j] == 0)
			M[i - 1][j] = matrixPath(i - 1, j, M, m, BP);
		if (M[i][j - 1] < M[i - 1][j]) {
			BP[i][j] = 'L';
			return M[i][j - 1] + m[i][j];
		}
		else {
			BP[i][j] = 'U';
			return M[i - 1][j] + m[i][j];
		}
	}
}

void print_path(int i, int j, int** m, char** BP)
{
	if (BP[i][j] == 'S') {
		printf("%c ", BP[i][j]);
		return;
	}
	else if (BP[i][j] == 'U')
		print_path(i - 1, j, m, BP);
	else if (BP[i][j] == 'L')
		print_path(i, j - 1, m, BP);
	printf("%c ", BP[i][j]);
}

int main(void)
{
	int i, j, r, c;
	int** M, ** m;
	char** BP;

	scanf("%d %d", &r, &c);

	M = (int**)malloc(sizeof(int*) * r);
	m = (int**)malloc(sizeof(int*) * r);
	BP = (char**)malloc(sizeof(char*) * r);
	for (i = 0; i < r; i++) {
		M[i] = (int*)malloc(sizeof(int) * c);
		m[i] = (int*)malloc(sizeof(int) * c);
		BP[i] = (char*)malloc(sizeof(char) * c);
	}

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			scanf("%d", &m[i][j]);

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++) {
			M[i][j] = 0;
			BP[i][j] = 0;
		}

	printf("%d\n", matrixPath(r - 1, c - 1, M, m, BP));
	print_path(r - 1, c - 1, m, BP);
}