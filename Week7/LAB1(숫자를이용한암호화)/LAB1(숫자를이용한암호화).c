#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void makeEncoded(char* encoded, char* A, char* encodedSentence, int size)
{
	int i;
	for (i = 0; i < size; i++)
		if (A[i] != ' ')
			encodedSentence[i] = encoded[A[i] - 'A'];
		else
			encodedSentence[i] = ' ';
	encodedSentence[i] = '\0';
}

void printArray(char* A, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%c", A[i]);
	printf("\n");
}

int main(void)
{
	int i, j, d;
	char alp[27], tmp[27], encoded[27], sentence[80], encodedSentence[80];

	printf("Enter a distance for encoding:");
	scanf("%d", &d);
	while (getchar() != '\n');

	for (i = 0; i < 26; i++)
		alp[i] = 'A' + i;

	j = 0;
	for (i = 26 - d; i < 26; i++)
		tmp[i] = alp[j++];
	tmp[i] = '\0';
	for (i = 0; i < 26 - d; i++)
		tmp[i] = alp[j++];
	for (i = 0; i < 26; i++)
		encoded[i] = tmp[i];

	printf("-------------------------------------\n");
	printf("alphabet: ");
	printArray(alp, 26);
	printf("encoded: ");
	printArray(encoded, 26);
	printf("-------------------------------------\n");
	printf("Enter a sentence to encode: ");
	gets(sentence);
	printf("original sentence: ");
	printArray(sentence, strlen(sentence));
	printf("encoded sentence: ");
	makeEncoded(encoded, sentence, encodedSentence, strlen(sentence));
	printArray(encodedSentence, strlen(sentence));
}