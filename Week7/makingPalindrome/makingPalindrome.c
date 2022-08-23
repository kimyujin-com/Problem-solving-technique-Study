#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int isPalindrome(char* s)
{
	int i, len;

	len = strlen(s);
	for (i = 0; i < len / 2; i++)
		if (s[i] != s[len - i - 1])
			return 0;
	return 1;
}

int main(void)
{
	int i, j, k;
	char s[80], tmp[80];

	scanf("%s", s);

	strcpy(tmp, s);
	for (i = 0; i < strlen(s); i++) {
		k = strlen(s);
		for (j = i; j >= 0; j--)
			tmp[k++] = s[j];
		tmp[k] = '\0';
		if (isPalindrome(tmp)) {
			printf("%s\n", tmp);
			break;
		}
	}
}