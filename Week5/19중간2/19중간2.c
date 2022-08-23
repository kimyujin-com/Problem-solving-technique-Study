#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int tenMultiple(int n)
{
	int result = 1;
	while (n > 0) {
		result *= 10;
		n /= 10;
	}
	return result / 10;
}

int main(void)
{
	int i, n, cnt = 0, tmpMultiple, tmpN, k = 0;
	scanf("%d", &n);
	for (i = 1; cnt < n; i++) {
		tmpN = i * 3;
		tmpMultiple = tenMultiple(tmpN);//10ÀÇ ÀÚ¸´¼ö ½Â
		while (tmpMultiple > 0 && cnt < n) {
			k = tmpN / tmpMultiple;
			tmpN %= tmpMultiple;
			tmpMultiple /= 10;
			cnt++;
		}
	}
	printf("%d\n", k);
}