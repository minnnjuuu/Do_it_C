#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntStack.h"


#define swap(type,x,y) do{type t = x ; x = y ; y = t ;}while (0)

//배열 나누는 함수
void partition(int a[], int n) {
	int i, pl = 0, pr = n - 1, x = a[n / 2];
	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;
		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);
	printf("피벗의 값은 %d입니다\n", x);
	printf("피벗 이하의 그룹\n");
	for (i = 0 ; i < pl; i++) 
		printf("%d", a[i]);
	printf("\n");
	if (pl > pr + 1) {
		printf("피벗과 일치하는 그룹\n");
		for (i = pr + 1; i < pl; i++)
			printf("%d", a[i]);
		printf("\n");
	}
	printf("피벗 이상의 그룹\n");
	for (i = pr + 1; i < n; i++)
		printf("%d", a[i]);
	printf("\n");
}

//퀵 정렬 함수
void quick(int a[],int left,int right) {
	int pl = left;
	int pr = right;
	int x = a[(pr + pl) / 2];

	//배열 분할 과정 출력

	int i;
	printf("a[%d] - a[%d] : {", left, right);
	for (i = left; i < right; i++)
		printf("%d, ", a[i]);
	printf("%d }\n",a[right]);

	do {
		while (a[pl] < x)pl++;
		while (a[pr] > x)pr--;
		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (left < pr) quick(a, left, pr);
	if (pl < right) quick(a, pl, right);
}

void quick2(int a[], int left, int right) {
	IntStack lstack;
	IntStack rstack;

	Initialize(&lstack, right - left + 1);
	Initialize(&rstack, right - left + 1);

	Push(&lstack, left);
	Push(&rstack, right);

	while (!IsEmpty(&lstack)) {
		int pl = (Pop(&lstack, &left), left);
		int pr = (Pop(&rstack, &right), right);
		int x = a[(left + right) / 2];
		do {
			while (a[pl] < x) pl++;
			while (a[pr] > x) pr--;
			if (pl <= pr) {
				swap(int, a[pl], a[pr]);
				pl++;
				pr--;
			}
		} while (pl <= pr);

		if (left < pr) {
			Push(&lstack, left);
			Push(&rstack, pr);
		}

		if (pl < right) {
			Push(&lstack, pl);
			Push(&rstack, right);
		}
	}
	Terminate(&lstack);
	Terminate(&rstack);
}

int int_cmp(const int* a, const int* b) {
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;
}

typedef struct {
	char name[10];  //이름
	int height;     //키
	int weight;     //몸무게
}Person;

//Person형 비교함수 by 이름
int npcmp(const Person* x, const Person* y) {
	return strcmp(x->name, y->name);
}

//Person형 비교함수 by 키
int hpcmp(const Person* x, const Person* y) {
	return x->height < y->height ? -1 : x->height>y->height ? 1 : 0;
}

//Person형 비교함수 by 몸무게
int wpcmp(const Person* x, const Person* y) {
	return x->weight<y->weight ? 1 : x->weight>y->weight ? -1 : 0;
}

void print_person(const Person x[], int no) {
	int i;
	for (i = 0; i < no; i++)
		printf("%-10s %dcm %dg\n", x[i].name, x[i].height, x[i].weight);
}


int main(void) {
	int i, nx;
	int* x;
	puts("배열을 나눕니다");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	//배열 분할
	//partition(x, nx);

	//퀵 정렬
	quick2(x, 0, nx - 1);
	puts("오름차순 정렬");
	for (i = 0; i < nx; i++)
		printf("x[%d] : %d\n", i, x[i]);
	free(x);

	int a; //요소 개수
	int* y;
	puts("qsort에 의한 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &a);
	y = calloc(nx, sizeof(int));
	for (int i = 0; i < a; i++) {
		printf("y[%d] : ", i);
		scanf_s("%d", &y[i]);
	}
	qsort(y, a, sizeof(int), (int(*)(const void*, const void*))int_cmp);
	puts("오름차순으로 정렬했습니다");
	for (int i = 0; i < a; i++)
		printf("y[%d] = %d\n", i, y[i]);
	free(y);

	Person z[] = {
		{"sunmi",170,52},
		{"yoobin",180,70},
		{"sohee",172,63},
		{"jina",165,50}
	};
	int c = sizeof(z) / sizeof(z[0]);
	puts("정렬 전");
	print_person(z, c);

	//이름 오름차순으로 정렬
	qsort(z, c, sizeof(Person), (int(*)(const void*, const void*))npcmp);
	puts("\n이름 오름차순으로 정렬 후");
	print_person(z, c);

	//키 오름차순으로 정렬
	qsort(z, c, sizeof(Person), (int(*)(const void*, const void*))hpcmp);
	puts("\n키 오름차순으로 정렬 후");
	print_person(z, c);

	//몸무게 오름차순으로 정렬
	qsort(z, c, sizeof(Person), (int(*)(const void*, const void*))wpcmp);
	puts("\n몸무게 오름차순으로 정렬 후");
	print_person(z, c);


	return 0;
}






