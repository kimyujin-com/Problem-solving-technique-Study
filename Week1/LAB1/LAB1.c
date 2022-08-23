#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void display(char board[][3])
{
	int i;
	for (i = 0; i < 3; i++) {
		printf("---|---|---\n");
		printf("%c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
	}
	printf("---|---|---\n");
}

int main(void)
{
	int i, j, x, y, cnt = 0;
	char player = 'O';
	char board[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			board[i][j] = ' ';
	while (cnt < 9) {
		printf("Player %c<За ї­>", player);
		scanf("%d %d", &x, &y);
		if (board[x][y] == ' ') {
			board[x][y] = player;
			display(board);
			cnt++;
		}
		else
			continue;
		player = (player == 'O') ? 'X' : 'O';
	}
}