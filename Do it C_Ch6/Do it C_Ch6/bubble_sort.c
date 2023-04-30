#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{ type t = x; x = y; y = t;} while (0)

//버블 정렬 함수(오른쪽부터 수행)
void bubble(int a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				swap(int, a[j - 1], a[j]);
	}
}

//버블 정렬 함수(왼쪽부터 수행)
void bubble_2(int a[], int n) {
	int i, j;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++)
			if (a[j - 1] > a[j])
				swap(int, a[j - 1], a[j]);
	}
}

//버블 정렬 - 교환 횟수에 따라 정렬작업 멈춤
void bubble_3(int a[], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		int exchg = 0;
		for (j = n - 1; j > i; j--) {
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				exchg++;
			}
		}
		if (exchg == 0) break;
	}
}

//버블 정렬 - 스캔 범위 제한
void bubble_4(int a[], int n) {
	int k = 0;
	while(k < n - 1) {
		int j;
		int last = n - 1;
		for (j = n - 1; j > k; j--) 
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				last = j;
			}
		k = last;
	}
}

int main(void) {
	int i, nx;
	int* x;
	puts("버블 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	bubble(x, nx);
	puts("오른쪽부터 버블 정렬");
	puts("오름차순으로 정렬했습니다");
	for (i = 0; i < nx; i++) {
		printf("x[%d] : %d\n", i, x[i]);
	}

	//문제 1번
	//왼쪽부터 버블정렬하는 프로그램 작성
	bubble_2(x, nx);
	puts("왼쪽부터 버블 정렬");
	puts("오름차순으로 정렬했습니다");
	for (i = 0; i < nx; i++) {
		printf("x[%d] : %d\n", i, x[i]);
	}

	//교환 횟수에 따라 정렬 작업 멈춤
	bubble_3(x, nx);
	puts("교환 횟수에 따른 정렬");
	puts("오름차순으로 정렬했습니다");
	for (i = 0; i < nx; i++) {
		printf("x[%d] : %d\n", i, x[i]);
	}

	//스캔 범위 제한
	bubble_4(x, nx);
	puts("스캔 범위 제한 정렬");
	puts("오름차순으로 정렬했습니다");
	for (i = 0; i < nx; i++)
		printf("x[%d] : %d\n", i, x[i]);
	
	free(x);
	return 0;
}
