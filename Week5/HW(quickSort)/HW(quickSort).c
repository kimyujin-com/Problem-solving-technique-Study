#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct student {
	int id;
	int kor;
	int math;
	int eng;
}Student;

int partition(Student A[], int p, int r) {
	int i, j, k;
	Student tmp;
	i = p - 1, j = p;
	for (k = p; k < r; k++)
		if (A[k].kor < A[r].kor) {
			j++;
		}
		else if (A[k].kor > A[r].kor) {
			tmp = A[++i];
			A[i] = A[k];
			A[k] = tmp;
			j++;
		}
	tmp = A[++i];
	A[i] = A[r];
	A[r] = tmp;
	return i;
}

descendingByKor(Student* A, int p, int r)
{
	int q;
	if (p < r) {
		q = partition(A, p, r);
		descendingByKor(A, p, q - 1);
		descendingByKor(A, q + 1, r);
	}
}

printMember(Student* A, int p, int q) 
{
	int i;
	for (i = p; i <= q; i++)
		printf("id = %3d, kor = %3d, math = %3d, eng = %3d\n", A[i].id, A[i].kor, A[i].math, A[i].eng);
}

int main(void)
{
	int i, n;
	Student* member;

	scanf("%d", &n);
	member = (Student*)malloc(sizeof(Student) * n);
	for (i = 0; i < n; i++) {
		member[i].id = i + 1;
		member[i].kor = rand() % 100;
		member[i].math = rand() % 100;
		member[i].eng = rand() % 100;
	}
	descendingByKor(member, 0, n - 1);
	printMember(member, 0, n - 1);
}