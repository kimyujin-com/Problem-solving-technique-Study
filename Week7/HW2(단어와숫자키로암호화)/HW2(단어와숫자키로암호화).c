#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void remove_duplicated_char(char* word)
{
	int i, j, k = 0, flag = 0;
	char tmp[80];
	for (i = 0; i < strlen(word); i++) {
		flag = 0;
		for (j = 0; j < i; j++)
			if (tmp[j] == word[i]) {
				flag = 1;
				break;
			}
		if (!flag)
			tmp[k++] = word[i];
	}
	tmp[k] = '\0';
	for (i = 0; i < k; i++)
		word[i] = tmp[i];
	for (i = k; i < strlen(word); i++)
		word[i] = '\0';
}

void makeCode(char* code, char* key, int d)
{
	int i, j ,k = 0, flag = 0;
	char tmp[27];
	for (i = 0; i < strlen(key); i++)
		tmp[k++] = key[i];
	for (i = 0; i < 26; i++) {
		flag = 0;
		for (j = 0; j < k; j++)
			if ('A' + i == tmp[j]) {
				flag = 1;
				break;
			}
		if (!flag)
			tmp[k++] = 'A' + i;
	}
	tmp[k] = '\0';

	j = 0;
	for (i = d; i < 26; i++)
		code[i] = tmp[j++];
	code[i] = '\0';
	for (i = 0; i < d; i++)
		code[i] = tmp[j++];
}

void printCode(char* code)
{
	int i;
	for (i = 0; i < strlen(code); i++)
		printf("%c", code[i]);
	printf("\n");
}

void encode(char* code, char* sentence, char* encodedSentence)
{
	int i;
	for (i = 0; i < strlen(sentence) - 1; i++)
		if (sentence[i] != ' ')
			encodedSentence[i] = code[sentence[i] - 'A'];
		else
			encodedSentence[i] = ' ';
	encodedSentence[i] = '\0';
}

int main(void)
{
	char key[80], code[27]; // code[0]부터 'A'의 암호화문자를 넣음
	int distance;
	char sentence[80];
	char encodedSentence[80];

	printf("Enter a key to use for encoding:");
	scanf("%s", key);
	printf("Enter a distance for encoding:");
	scanf("%d", &distance);

	remove_duplicated_char(key);
	printf("%s\n", key);
	makeCode(code, key, distance);
	printCode(code);
	while (getchar() != '\n');

	printf("Enter a sentence to encode:");
	fgets(sentence, sizeof(sentence), stdin);
	encode(code, sentence, encodedSentence);
	printf("original sentence:\t");
	puts(sentence);
	printf("encoded sentence:\t");
	puts(encodedSentence);
}