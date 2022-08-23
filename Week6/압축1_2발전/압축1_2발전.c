#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	int j = 0, cnt = 0;
	char key[3], tmp[3], bucket[80], newBucket[80];
	char* q = bucket;

	scanf("%s", bucket);

	strncpy(key, q, 2);
	key[2] = '\0';
	for (; *q != '\0' && *(q + 1) != '\0'; q += 2) {
		strncpy(tmp, q, 2);
		tmp[2] = '\0';
		if (strcmp(key, tmp) == 0)
			cnt++;
		else {
			if (cnt >= 10)
				while (cnt > 0) {
					newBucket[j++] = cnt / 10 + '0';
					cnt /= 10;
				}
			else if (cnt >= 2)
				newBucket[j++] = cnt + '0';
			newBucket[j] = '\0';
			strcat(newBucket, key);
			j += 2;
			cnt = 1;
			strcpy(key, tmp);
		}
	}
	if (cnt >= 10)
		while (cnt > 0) {
			newBucket[j++] = cnt / 10 + '0';
			cnt /= 10;
		}
	else if (cnt >= 2)
		newBucket[j++] = cnt + '0';
	newBucket[j] = '\0';
	strcat(newBucket, key);
	j += 2;
	while (*q != '\0')
		newBucket[j++] = *q++;
	newBucket[j] = '\0';

	//printf("%s\n", newBucket);
	printf("%d\n", strlen(newBucket));
}