#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i, n;
	int* box;

	scanf("%d", &n);
	box = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		box[i] = rand() % 1000;
	for (i = 0; i < n; i++)
		printf("%d ", box[i]);
}