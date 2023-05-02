#include <stdio.h>
#include <stdlib.h>

//셸 정렬 함수
void shell(int a[], int n) {
	int i, j, h;
	for (h = n / 2; h > 0; h /=2) {
		for (i = h; i < n; i++) {
			int tmp = a[i];
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {
				a[j + h] = a[j];
			}
			a[j + h] = tmp;
		}
	}
}

//셸 정렬 함수2
int shell_2(int a[], int n) {
	int i, j, h;
	int chg = 0;
	for (h = 1; h < n / 9; h = 3 * h + 1);
	for (;h>0;h/=3)
		for (i = h; i < n; i++) {
			int tmp = a[i];
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {
				a[j + h] = a[j];
				chg++;
			}
			a[j + h] = tmp;
			chg++;
		}
	return chg;
}



int main(void) {
	int i, nx;
	int* x;
	puts("셸 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	shell(x, nx);
	puts("오름차순으로 정렬");
	for (i = 0; i < nx; i++)
		printf("x[%d] : %d\n", i, x[i]);
	free(x);

	int ii, nxx;
	int* y;
	int chg;
	puts("셸 정렬 2");
	printf("요소 개수 : ");
	scanf_s("%d", &nxx);
	y = calloc(nxx, sizeof(int));
	for (ii = 0; ii < nxx; ii++) {
		printf("y[%d] : ", ii);
		scanf_s("%d", &y[ii]);
	}
	puts("오름차순으로 정렬");
	int change = shell_2(y, nxx);
	for (ii = 0; ii < nxx; ii++)
		printf("y[%d] : %d\n", ii, y[ii]);
	printf("교환 횟수는 %d입니다", change);
	free(y);
	return 0;
}