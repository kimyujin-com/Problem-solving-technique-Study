#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i, j = 0, cnt = 0;
	char key;
	char bucket[80], newBucket[80];

	scanf("%s", bucket);
	
	key = bucket[0];
	for (i = 0; bucket[i] != '\0'; i++) {
		if (key == bucket[i])
			cnt++;
		else {
			if (cnt >= 2)
				newBucket[j++] = cnt + '0';
			newBucket[j++] = key;
			newBucket[j] = '\0';
			cnt = 1;
			key = bucket[i];
		}
	}
	if (cnt >= 2)
		newBucket[j++] = cnt + '0';
	newBucket[j++] = key;
	newBucket[j] = '\0';
	printf("%s\n", newBucket);
}