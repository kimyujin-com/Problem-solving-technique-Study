#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct member
{
	int id;
	int eng;
	int math;
	int kor;
}Member;

void bubbleSort(Member* A, int subject, int start, int end)
{
	int i, j;
	Member tmp;
	if (subject == 1) {
		for (i = 0; i < end - start; i++)
			for (j = start; j < end - i; j++)
				if (A[j + 1].kor > A[j].kor) {
					tmp = A[j + 1];
					A[j + 1] = A[j];
					A[j] = tmp;
				}
	}
	else if(subject == 2) {
		for (i = 0; i < end - start; i++)
			for (j = start; j < end - i; j++)
				if (A[j + 1].math > A[j].math) {
					tmp = A[j + 1];
					A[j + 1] = A[j];
					A[j] = tmp;
				}
	}
	else if (subject == 3) {
		for (i = 0; i < end - start; i++)
			for (j = start; j < end - i; j++)
				if (A[j + 1].eng > A[j].eng) {
					tmp = A[j + 1];
					A[j + 1] = A[j];
					A[j] = tmp;
				}
	}
	else if (subject == 4) {
		for (i = 0; i < end - start; i++)
			for (j = start; j < end - i; j++)
				if (A[j + 1].id < A[j].id) {
					tmp = A[j + 1];
					A[j + 1] = A[j];
					A[j] = tmp;
				}
	}
}

void printArray(Member* A, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		printf("%4d", A[i].id);
		printf("%4d", A[i].kor);
		printf("%4d", A[i].math);
		printf("%4d\n", A[i].eng);
	}
}

int main(void)
{
	int i, n, subject, cnt = 1;
	Member* mem;

	printf("학생 수를 입력하세요: ");
	scanf("%d", &n);

	mem = (Member*)malloc(sizeof(Member) * n);
	for (i = 0; i < n; i++) {
		mem[i].id = cnt++;
		mem[i].eng = rand() % 100;
		mem[i].math = rand() % 100;
		mem[i].kor = rand() % 100;
	}
	printArray(mem, n);
	printf("정렬 기준 선택<1:국어, 2:수학, 3:영어, 4:id<오름차순>, 0:끝내기> : ");
	scanf("%d", &subject);
	while (subject != 0) {
		bubbleSort(mem, subject, 0, n - 1);
		printArray(mem, n);
		printf("정렬 기준 선택<1:국어, 2:수학, 3:영어, 4:id<오름차순>, 0:끝내기> : ");
		scanf("%d", &subject);
	}
}