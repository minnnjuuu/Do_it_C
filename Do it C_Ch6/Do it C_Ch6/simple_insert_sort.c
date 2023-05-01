#include <stdio.h>
#include <stdlib.h>

void insertion(int a[], int n) {
	int i, j;
	for (i = 1; i < n; i++) {
		int tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; j--)
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}

int main(void) {
	int i, nx;
	int* a;
	puts("�ܼ� ���� ����");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	a = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("a[%d] : ", i);
		scanf_s("%d", &a[i]);
	}

	insertion(a, nx);

	puts("������������ �����߽��ϴ�");
	for (int i = 0; i < nx; i++)
		printf("x[%d] : %d\n", i, a[i]);
	free(a);

	return 0;
}