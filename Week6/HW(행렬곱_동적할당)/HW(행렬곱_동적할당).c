#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void readMatrix(int** a, int** b, int rowA, int colA, int rowC, int colC)
{
	int i, j;
	printf("<%d x %d> 행렬 A 입력: \n", rowA, colA);
	for (i = 0; i < rowA; i++)
		for (j = 0; j < colA; j++)
			scanf("%d", &a[i][j]);
	printf("<%d x %d> 행렬 B 입력: \n", rowC, colC);
	for (i = 0; i < rowC; i++)
		for (j = 0; j < colC; j++)
			scanf("%d", &b[i][j]);
}

void matrixMul(int** a, int** b, int** x, int rowA, int colA, int colB)
{
	//m x n , n x q => m x q
	int i, j, k;
	for (i = 0; i < rowA; i++)
		for (j = 0; j < colB; j++)
			for (k = 0; k < colA; k++)
				x[i][j] += a[i][k] * b[k][j];
}

void printMatrix(int** a, int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int i, j, rowA, colA, rowC, colC;
	int** A, ** C, **X;
	
	printf("Enter 행렬 A의 행과 열의 개수: ");
	scanf("%d %d", &rowA, &colA);
	A = (int**)malloc(sizeof(int*) * rowA);
	for (i = 0; i < rowA; i++)
		A[i] = (int*)malloc(sizeof(int) * colA);

	printf("Enter 행렬 C의 행과 열의 개수: ");
	scanf("%d %d", &rowC, &colC);
	C = (int**)malloc(sizeof(int*) * rowC);
	for (i = 0; i < rowC; i++)
		C[i] = (int*)malloc(sizeof(int) * colC);
	readMatrix(A, C, rowA, colA, rowC, colC);

	X = (int**)malloc(sizeof(int*) * rowA);
	for (i = 0; i < rowA; i++)
		X[i] = (int*)malloc(sizeof(int) * colC);
	for (i = 0; i < rowA; i++)
		for (j = 0; j < colC; j++)
			X[i][j] = 0;

	matrixMul(A, C, X, rowA, colA, colC);

	printf("행렬곱:\n");
	printMatrix(X, rowA, colC);
	printf("전치행렬:\n");
	for (i = 0; i < colA; i++) {
		for (j = 0; j < rowA; j++)
			printf("%3d", A[j][i]);
		printf("\n");
	}
}