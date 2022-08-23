#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void reverse(char src_s[], char s[])
{
	int i, len;
	len = strlen(src_s);
	for (i = 0; i < len; i++)
		s[i] = src_s[len - i - 1];
	s[i] = '\0';
	return;
}

int cnt_carry(char* s1, char* s2, int carry)
{
	if (*s1 != '\0' && *s2 != '\0')
		if (*s1 - '0' + *s2 - '0' >= 10)
			return 1 + cnt_carry(++s1, ++s2, 1);
		else
			return cnt_carry(++s1, ++s2, 0);
	else if (*s1 != '\0')
		if (*s1 - '0' + carry >= 10)
			return 1 + cnt_carry(++s1, s2, 1);
		else
			return cnt_carry(++s1, s2, 0);
	else if (*s2 != '\0')
		if (*s2 - '0' + carry >= 10)
			return 1 + cnt_carry(s1, ++s2, 1);
		else
			return cnt_carry(s1, ++s2, 0);
	else
		return 0;
}

int main(void)
{
	char src_s[101], src_s2[101];
	char s1[101], s2[101];

	scanf("%s", src_s);
	scanf("%s", src_s2);
	reverse(src_s, s1);
	reverse(src_s2, s2);
	printf("%d\n", cnt_carry(s1, s2, 0));
}