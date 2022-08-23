#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define WIDTH 10
#define HEIGHT 10

int screen[WIDTH][HEIGHT] = {
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1, 0, 0,-1,-1,-1, 0,-1,-1,
-1,-1,-1, 0, 0, 0, 0, 0,-1,-1,
-1,-1,-1, 0,-1,-1,-1,-1,-1,-1,
-1,-1,-1, 0, 0, 0, 0, 0,-1,-1,
-1,-1,-1, 0,-1, 0,-1,-1,-1,-1,
-1,-1,-1, 0,-1, 0,-1,-1,-1,-1,
-1,-1,-1, 0,-1, 0, 0, 0,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
};

void flood_fill(int x, int y)
{
	static int cnt = 0;
	if (screen[x][y] == 0)
	{
		screen[x][y] = ++cnt;
		flood_fill(x, y + 1); 
		flood_fill(x + 1, y);
		flood_fill(x, y - 1); 
		flood_fill(x - 1, y); 
	}
}void display(int s[][WIDTH], int width)
{
	int i, j;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < width; j++)
			printf("%3d", s[i][j]);
		printf("\n");
	}
}

int main(void)
{
	flood_fill(4, 3);
	display(screen, WIDTH);

}