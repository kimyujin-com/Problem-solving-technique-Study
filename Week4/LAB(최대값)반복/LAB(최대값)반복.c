#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max1(int list[], int low, int high)
{
	int i, maxIndex = low;
	if (low < high){
		for (i = low; i <= high; i++)
			if (list[maxIndex] < list[i])
				maxIndex = i;
		return list[maxIndex];
	}
	return -1;
}

int main(void)
{
	int list[] = { 10, 20, 100, 4, 5, 45, 3, 99, 11, 22 };

	printf("���� ū ���� %d\n", max1(list, 0, 9));
	printf("���� ū ���� %d\n", max1(list, 5, 9));
	printf("���� ū ���� %d\n", max1(list, 3, 6));
}