#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_cycle_number(int n)
{
	if (n == 1)
		return 1; 
	else if (n % 2 == 0)
		return 1 + get_cycle_number(n / 2);
	else
		return 1 + get_cycle_number(n * 3 + 1);
}

int main(void)
{
	int n;

	scanf("%d", &n);
	printf("%d\n", get_cycle_number(n));
}