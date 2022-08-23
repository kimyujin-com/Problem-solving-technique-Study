#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i, col, row, startPosition, rowPosition = 0, colPosition;
	char box[10][10];

	scanf("%d %d", &col, &row);
	scanf("%d", &startPosition);
	getchar();
	for (i = 0; i < row; i++)
		gets(box[i]);

	colPosition = startPosition;
	while (rowPosition < row) {
		if (colPosition == 0) {
			if (box[colPosition][rowPosition] == '1')
				colPosition++;
			rowPosition++;
		}
		else {
			if (box[colPosition - 1][rowPosition] == '1')
				colPosition--;
			else if (box[colPosition][rowPosition] == '1')
				colPosition++;
			rowPosition++;
		}
	}
	printf("%d\n", colPosition);
}