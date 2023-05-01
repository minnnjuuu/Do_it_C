#include <stdio.h>
#include <stdlib.h>

#define swap(type,x,y) do{type t=x;x=y;y=t;} while(0)

void selection(int a[], int n) {
	int i, j;
	for (i = 0; i < n-1; i++) {
		int min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		swap(int, a[i], a[min]);
	}
}

void selection_2(int a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		int min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		for (j = 0; j < n; j++)
			printf((j == i) ? "* " : (j == min) ? "+ " : "  ");
		printf("\n");
		for (j = 0; j < n; j++)
			printf("%d ", a[j]);
		printf("\n");
		swap(int, a[i], a[min]);
	}
}






int main(void) {
	int i, nx;
	int* a;
	printf("단순 선택 정렬\n");
	printf("요소개수 : ");
	scanf_s("%d", &nx);
	a = calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++) {
		printf("a[%d] : ", i);
		scanf_s("%d", &a[i]);
	}
	puts("오름차순으로 정렬합니다");
	selection(a, nx);
	for (i = 0; i < nx; i++)
		printf("a[%d] : %d\n", i, a[i]);

	int nxx;
	int* b;
	printf("요소개수 : ");
	scanf_s("%d", &nxx);
	b = calloc(nxx, sizeof(int));
	for (i = 0; i < nxx; i++) {
		printf("b[%d] : ", i);
		scanf_s("%d", &b[i]);
	}
	puts("오름차순으로 상세 정렬합니다");
	selection_2(b, nxx);

	free(a);
	free(b);
	return 0;
}