#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int tenMultiple(int n)
{
	int result = 1;
	while (n > 0) {
		result *= 10;
		n /= 10;
	}
	return result / 10;
}

void printNineMultiple(int n)
{
	int nineMultiple, tmpMultiple;
	nineMultiple = 9 * n;
	tmpMultiple = tenMultiple(nineMultiple);
	while (tmpMultiple > 0) {
		printf("%d ", nineMultiple / tmpMultiple);
		nineMultiple %= tmpMultiple;
		tmpMultiple /= 10;
	}
	printf("\n");
}

int main(void)
{
	int n;

	scanf("%d", &n);
	printNineMultiple(n);
}