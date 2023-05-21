#include <stdio.h>
#include <stdlib.h>

//������ ��������
void merge(const int a[], int na, const int b[], int nb, int c[]) {
	int pa = 0;
	int pb = 0;
	int pc = 0;
	while (pa < na && pb < nb)
		c[pc++] = (a[pa] <= b[pb]) ? a[pa++] : b[pb++];
	while (pa < na)
		c[pc++] = a[pa++];
	while (pb < nb)
		c[pc++] = b[pb++];
}

//���� ���� �˰���

static int* buff; //�۾��� �迭

static void __mergesort(int a[], int left, int right) {
	if (left < right) {
		int center = (left + right) / 2;
		int p = 0;
		int i;
		int j = 0;
		int k = left;
		__mergesort(a, left, center);
		__mergesort(a, center + 1, right);
		for (i = left; i <= center; i++)
			buff[p++] = a[i];
		while (i <= right && j < p)
			a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
		while (j < p)
			a[k++] = buff[j++];
	}
}

int mergesort(int a[], int n) {
	if ((buff = calloc(n, sizeof(int))) == NULL)
		return -1;
	__mergesort(a, 0, n - 1);
	free(buff);
	return 0;
}

int main(void) {
	int i, na, nb;
	int* a, * b, * c;
	printf("a�� ��� ���� : ");
	scanf_s("%d", &na);
	printf("b�� ��� ���� : ");
	scanf_s("%d", &nb);

	a = calloc(na, sizeof(int));
	b = calloc(nb, sizeof(int));
	c = calloc(na + nb, sizeof(int));

	printf("a[0] : ");
	scanf_s("%d", &a[0]);
	for (i = 1; i < na; i++) {
		do {
			printf("a[%d] : ", i);
			scanf_s("%d", &a[i]);
		} while (a[i] < a[i - 1]);
	}
	printf("b[0] : ");
	scanf_s("%d", &b[0]);
	for (i = 1; i < nb; i++) {
		do {
			printf("b[%d] : ", i);
			scanf_s("%d", &b[i]);
		} while (b[i] < b[i - 1]);
	}

	puts("���� �迭");
	puts("�迭 a�� b�� �����Ͽ� �迭 c�� �����߽��ϴ�");
	merge(a, na, b, nb, c);
	for (i = 0; i < na + nb; i++) {
		printf("c[%2d] = %2d\n", i, c[i]);
	}
	free(a);
	free(b);
	free(c);


	int nx;
	int* x;
	puts("���� ����");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	mergesort(x, nx);
	puts("������������ ���� ���� �߽��ϴ�");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}