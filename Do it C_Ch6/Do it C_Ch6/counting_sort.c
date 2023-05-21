#include <stdio.h>
#include <stdlib.h>

//도수 정렬 함수
void fsort(int a[], int n, int max) {
	int i;
	int* f = calloc(max + 1, sizeof(int)); //누적 도수
	int* b = calloc(n, sizeof(int));       //작업용 목적 배열
	for (i = 0; i <= max; i++)
		f[i] = 0;
	for (i = 0; i < n; i++)
		f[a[i]]++;
	for (i = 1; i <= max; i++)
		f[i] += f[i - 1];
	for (i = n - 1; i >= 0; i--)
		b[--f[a[i]]] = a[i];
	for (i = 0; i < n; i++)
		a[i] = b[i];

	free(b);
	free(f);
}

int main(void) {
	int i, nx;
	int* x;
	const int max = 100;
	puts("도수 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));
	printf("0부터 %d 사이의 정수를 입력하세요\n", max);
	for (i = 0; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf_s("%d", &x[i]);
		} while (x[i]<0 || x[i]>max);
	}

	fsort(x, nx, max);
	puts("오름차순으로 정렬합니다");
	for (i = 0; i < nx; i++)
		printf("x[%d] : %d\n", i, x[i]);

	free(x);

	return 0;
}