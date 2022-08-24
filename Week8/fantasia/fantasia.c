#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fantasia(int n, int m, int leftN, int leftM, int rightN, int rightM)
{
	if (n * (leftM + rightM) == m * (leftN + rightN))
		return;
	else if (n * (leftM + rightM) < m * (leftN + rightN)) {
		rightN = leftN + rightN;
		rightM = leftM + rightM;
		printf("L");
	}
	else {
		leftN = leftN + rightN;
		leftM = leftM + rightM;
		printf("R");
	}
	fantasia(n, m, leftN, leftM, rightN, rightM);
}

int main(void)
{
	int m, n;
	
	scanf("%d %d", &n, &m);
	fantasia(n, m, 0, 1, 1, 0);
}