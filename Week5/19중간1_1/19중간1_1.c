#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int isMultipleOfTwo(char n[])
{
	if ((n[strlen(n) - 1] - '0') % 2 == 0)
		return 1;
	else
		return 0;
}

int main(void)
{
	char n[51];
	scanf("%s", n);
	printf("%d\n", isMultipleOfTwo(n));
}