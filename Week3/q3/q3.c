#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n, result = 1, cnt = 1;

	scanf("%d", &n);

	while (result % n != 0) {
		result = result * 10 + 1;
		cnt++;
	}
	printf("%d\n", cnt);
}