#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct set {
	char word[20001];
	int length;
}Set;

void bubbleSort(Set* s, int n)
{
	int i, j;
	Set tmp;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (s[j + 1].length == s[j].length) {
				if (strcmp(s[j].word, s[j + 1].word) == 1) {
					tmp = s[j];
					s[j] = s[j + 1];
					s[j + 1] = tmp;
				}
			}
			else if (s[j + 1].length < s[j].length) {
				tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}

}

int main(void)
{
	Set* p;
	int i, n;

	scanf("%d", &n);
	p = (Set*)malloc(sizeof(Set) * (n + 1));

	for (i = 0; i < n; i++) {
		scanf("%s", p[i].word);
		p[i].length = strlen(p[i].word);
	}

	bubbleSort(p, n);
	for (i = 0; i < n; i++)
		printf("%s\n", p[i].word);
}