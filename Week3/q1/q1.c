#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int H(int a, int b, int carry)
{
	if (a == 0) {
		if (carry + b % 10 >= 10) return 1;
		else return 0;
	}
	else if (b == 0) {
		if (carry + a % 10 >= 10) return 1;
		else return 0;
	}
	// �� �� ����ִ� ���
	else if (a % 10 + b % 10 >= 10)//ĳ�� �߻�O
		return H(a / 10, b / 10, 1) + 1;
	else//ĳ�� �߻�X
		return H(a / 10, b / 10, 0);
}

int main(void)
{
	int n1, n2;

	scanf("%d %d", &n1, &n2);
	printf("%d\n", H(n1, n2, 0));
}