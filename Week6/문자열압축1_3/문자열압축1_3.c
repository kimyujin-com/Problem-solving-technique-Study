#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <limits.h>

int main(void)
{
	int i, j = 0, cnt = 0, min = INT_MAX, len;
	char key[80], tmp[80], bucket[80], newBucket[80];
	char* q = bucket;

	scanf("%s", bucket);

	for (i = 1; i <= strlen(bucket) / 2; i++) {
		cnt = 0; j = 0;
		char *q = bucket;
		strncpy(key, q, i);
		key[i] = '\0';
		for (;*(q + i - 1) >= 'a' && *(q + i - 1) <= 'z'; q += i) {
			strncpy(tmp, q, i);
			tmp[i] = '\0';
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
				j += i;
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
		j += i;
		while (*q != '\0')
			newBucket[j++] = *q++;
		newBucket[j] = '\0';
		if ((len = strlen(newBucket)) < min)
			min = len;
	}

	//printf("%s\n", newBucket);
	printf("%d\n", min);
}