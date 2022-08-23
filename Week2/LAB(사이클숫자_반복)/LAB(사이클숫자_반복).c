#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_cycle_number(int n)
{
	int cnt = 1;
	while (n != 1) {
		if (n % 2 == 0)
			n /= 2;
		else
			n = n * 3 + 1;
		cnt++;
	}
	return cnt;
}

int main(void)
{
	int n;

	scanf("%d", &n);
	printf("%d\n", get_cycle_number(n));
}