#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max2(int list[], int low, int high)
{
	int mid, leftMax, rightMax;
	if (low < high) {
		mid = (low + high) / 2;
		leftMax = max2(list, low, mid);
		rightMax = max2(list, mid + 1, high);
		if (leftMax < rightMax)
			return rightMax;
		else
			return leftMax;
	}
	else
		return list[low];
}

int main(void)
{
	int list[] = { 10, 20, 100, 4, 5, 45, 3, 99, 11, 22 };

	printf("가장 큰 수는 %d\n", max2(list, 0, 9));
	printf("가장 큰 수는 %d\n", max2(list, 5, 9));
	printf("가장 큰 수는 %d\n", max2(list, 3, 6));
}