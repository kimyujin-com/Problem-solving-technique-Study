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

int winnerCheck(char board[][3], int x, int y, char player)
{
	int cnt = 1, tmpX, tmpY;
	//가로 체크
	tmpY = y - 1;
	while (tmpY >= 0)
		if (board[x][tmpY--] == player)
			cnt++;
	tmpY = y + 1;
	while (tmpY < 3)
		if (board[x][tmpY++] == player)
			cnt++;
	if (cnt == 3)
		return 1;
	//세로 체크
	cnt = 1;
	tmpX = x - 1;
	while (tmpX >= 0)
		if (board[tmpX--][y] == player)
			cnt++;
	tmpX = x + 1;
	while (tmpX < 3)
		if (board[tmpX++][y] == player)
			cnt++;
	if (cnt == 3)
		return 1;
	//우대각선 체크
	cnt = 1;
	tmpX = x - 1;
	tmpY = y - 1;
	while (tmpX >= 0 && tmpY >= 0) 
		if (board[tmpX--][tmpY--] == player)
			cnt++;
	tmpX = x + 1;
	tmpY = y + 1;
	while (tmpX < 3 && tmpY < 3)
		if (board[tmpX++][tmpY++] == player)
			cnt++;
	if (cnt == 3)
		return 1;
	//좌대각선 체크
	cnt = 1;
	tmpX = x + 1;
	tmpY = y - 1;
	while (tmpX < 3 && tmpY >= 0)
		if (board[tmpX++][tmpY--] == player)
			cnt++;
	tmpX = x - 1;
	tmpY = y + 1;
	while (tmpX >= 0 && tmpY < 3)
		if (board[tmpX--][tmpY++] == player)
			cnt++;
	if (cnt == 3)
		return 1;
	return 0;
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
		printf("Player %c<행 열>", player);
		scanf("%d %d", &x, &y);
		if (board[x][y] == ' ') {
			board[x][y] = player;
			display(board);
			if (winnerCheck(board, x, y, player)) {
				printf("player %c wins!", player);
				break;
			}
			cnt++;
		}
		else
			continue;
		player = (player == 'O') ? 'X' : 'O';
	}
}