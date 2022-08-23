#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int reverse(int n)
{
	int result = 0;
	while (n > 0) {
		result = result * 10 + n % 10;
		n /= 10;
	}
	return result;
}

int main(void) 
{
	int n, reverseN, cnt = 0, flag = 0;
	scanf("%d", &n);
	
	while (n != (reverseN = reverse(n))) {
		n = n + reverseN;
		if (n < 0) {
			flag = 1;
			break;
		}
		cnt++;
	}

	if (flag)
		printf("Overflow\n");
	else
		printf("%d %d\n", cnt, n);
}