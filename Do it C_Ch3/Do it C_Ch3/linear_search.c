#include <stdio.h>
#include <stdlib.h>

int search(const int a[], int n, int key) {
	int i = 0;
	while (n) {
		if (i == n)
			return -1; //검색 실패
		if (a[i] == key)
			return i;  //검색 성공
		i++;
	}
}

int search_2(int a[], int n, int key) {
	int i = 0;
	a[n] = key;
	while (n + 1) {
		if (a[i] == key)
			return i;
		if (i == n)
			return -1;
		i++;
	}
}

int main(void) {
	//선형 검색
	int i, nx, ky, idx;
	int* x;
	printf("선형 검색\n");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	printf("검색값 : ");
	scanf_s("%d", &ky);
	idx = search(x, nx, ky);
	if (idx == -1)
		puts("검색 실패");
	else
		printf("%d(은)는 x[%d]에 있습니다\n", ky, idx);
	free(x);

	//보초법
	int a, cnt, key, index;
	int* y;
	puts("선형검색(보초법)");
	printf("요소 개수 : ");
	scanf_s("%d", &cnt);
	y = calloc(cnt + 1, sizeof(int));
	for (a = 0; a < cnt; a++) {
		printf("y[%d] : ", a);
		scanf_s("%d", &y[a]);
	}
	printf("검색값 : ");
	scanf_s("%d", &key);
	index = search_2(y, cnt, key);
	if (index == -1)
		puts("검색 실패");
	else
		printf("%d(은)는 x[%d]에 있습니다\n", key, index);
	free(y);
	return 0;
}