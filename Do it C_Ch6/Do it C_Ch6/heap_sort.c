#include <stdio.h>
#include <stdlib.h>

#define swap(type,x,y) do {type t = x;x = y;y = t;} while(0)

//a[left] ~ a[right] 를 힙으로 만드는 함수
static void downheap(int a[], int left, int right) {
	int temp = a[left]; //루트
	int child, parent;
	for (parent = left; parent < (right + 1) / 2; parent = child) {
		int cl = parent * 2 + 1;
		int cr = cl + 1;
		child = (cr <= right && a[cr] > a[cl]) ? cr : cl;
		if (temp >= a[child])
			break;
		a[parent] = a[child];
	}
	a[parent] = temp;
}

//힙 정렬 함수
void heapsort(int a[], int n) {
	int i;
	for (i = (n - 1) / 2; i >= 0; i--)
		downheap(a, i, n - 1);
	for (i = n - 1; i > 0; i--) {
		swap(int, a[0], a[i]);
		downheap(a, 0, i - 1);
	}
}


int main(void) {
	int nx;
	int* x; //배열의 첫번째 요소에 대한 포인터
	puts("힙 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));
	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	puts("오름차순으로 정렬했습니다");
	heapsort(x, nx);
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}