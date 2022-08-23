#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int is_in(int* cards, int cardSize, int* set, int setSize)
{
	int i, j, k = 0, flag;
	int tmp[80];
	for (i = 0; i < cardSize; i++) {
		flag = 0;
		for (j = 0; j < setSize; j++)
			if (cards[i] == set[j]) {
				flag = 1;
				break;
			}
		if (flag)
			tmp[k++] = cards[i];
	}
	for (i = 0; i < k; i++)
		cards[i] = tmp[i];
	return k;
}

int is_not_in(int* cards, int cardSize, int* set, int setSize)
{
	int i, j, k = 0, flag;
	int tmp[80];
	for (i = 0; i < cardSize; i++) {
		flag = 0;
		for (j = 0; j < setSize; j++)
			if (cards[i] == set[j]) {
				flag = 1;
				break;
			}
		if (!flag)
			tmp[k++] = cards[i];
	}
	for (i = 0; i < k; i++)
		cards[i] = tmp[i];
	return k;
}

int main(void)
{
	int i, cardSize;
	char ans;
	int cards[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	int card[4][8] = { { 1, 2, 3, 4, 5, 6, 7, 8 }, { 1, 2, 3, 4, 9, 10 ,11, 12 },
			{ 1, 2, 5, 6, 9, 10, 13, 14 }, { 1, 3, 5, 7, 9, 11, 13, 15 } };

	cardSize = 9;
	for (i = 0; i < 4; i++) {
		scanf("%c", &ans);
		while (getchar() == '\0');
		if (ans == 'Y')
			cardSize = is_in(cards, cardSize, card[i], 8);
		else
			cardSize = is_not_in(cards, cardSize, card[i], 8);
	}
	printf("%d\n", cards[0]);
}