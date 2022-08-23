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

int isMultipleOfThree(char n[])
{
	int i, sum = 0;
	for (i = 0; i < strlen(n); i++)
		sum += n[i] - '0';
	if (sum % 3 == 0)
		return 1;
	else
		return 0;

}

int isMultipleOfFour(char n[])
{
	int i, rem, len;
	len = strlen(n);
	rem = (n[len - 2] - '0') * 10 + n[len - 1] - '0';
	if (rem % 4 == 0)
		return 1;
	else
		return 0;
}

int isMultipleOfFive(char n[])
{
	int i, rem, len;
	len = strlen(n);
	if (n[len - 1] - '0' == 0 || n[len - 1] - '0' == 5)
		return 1;
	else
		return 0;
}

int main(void)
{
	int i;
	char n[51];

	scanf("%s", n);
	printf("%d", isMultipleOfTwo(n));
	printf("%d", isMultipleOfThree(n));
	printf("%d", isMultipleOfFour(n));
	printf("%d", isMultipleOfFive(n));
}