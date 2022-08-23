#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void makeCode(char* code, int d)
{
	int i, j = 0;
	for (i = 26 - d; i < 26; i++)
		code[i] = 'A' + j++;
	code[i] = '\0';
	for (i = 0; i < 26 - d; i++)
		code[i] = 'A' + j++;;
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

void decode(char* code, char* encodedSentence, char* decodedSentence, int d)
{
	int i;
	for (i = 0; i < strlen(encodedSentence); i++)
		if (encodedSentence[i] == ' ')
			decodedSentence[i] = ' ';
		else if (encodedSentence[i] - 'A' > d)
			decodedSentence[i] = encodedSentence[i] - d;
		else
			decodedSentence[i] = 'Z' - d + encodedSentence[i] - 'A' + 1;
	decodedSentence[i] = '\0';
}

int main(void)
{
	char code[27]; // code[0]부터 'A'의 암호화문자를 넣음
	int distance;
	char sentence[80];
	char encodedSentence[80];
	char decodedSentence[80];

	printf("Enter a distance for encoding:");
	scanf("%d", &distance);
	makeCode(code, distance);
	printCode(code);
	while (getchar() != '\n');
	//fflush(stdin);
	printf("Enter a sentence to encode:");
	fgets(sentence, sizeof(sentence), stdin);
	encode(code, sentence, encodedSentence);
	printf("original sentence:\t");
	puts(sentence);
	printf("encoded sentence:\t");
	puts(encodedSentence);
	decode(code, encodedSentence, decodedSentence, distance);
	printf("decoded sentence:\t");
	puts(decodedSentence);
}