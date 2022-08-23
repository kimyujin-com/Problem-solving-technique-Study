#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void readMatrix(int a[][3], int b[][3])
{
	int i, j;
	printf("<3 x 3> 행렬 A 입력: \n");
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &a[i][j]);
	printf("<3 x 3> 행렬 B 입력: \n");
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &b[i][j]);
}

void matrixAdd(int a[][3], int b[][3], int x[][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			x[i][j] = a[i][j] + b[i][j];
}

void printMatrix(int a[][3]) 
{
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int a[3][3], b[3][3], x[3][3];

	readMatrix(a, b);
	matrixAdd(a, b, x);
	printf("행렬합\n");
	printMatrix(x);
}