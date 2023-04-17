#include <stdio.h>
#include <stdlib.h>

int search(const int a[], int n, int key) {
	int i = 0;
	while (n) {
		if (i == n)
			return -1; //�˻� ����
		if (a[i] == key)
			return i;  //�˻� ����
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
	//���� �˻�
	int i, nx, ky, idx;
	int* x;
	printf("���� �˻�\n");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	printf("�˻��� : ");
	scanf_s("%d", &ky);
	idx = search(x, nx, ky);
	if (idx == -1)
		puts("�˻� ����");
	else
		printf("%d(��)�� x[%d]�� �ֽ��ϴ�\n", ky, idx);
	free(x);

	//���ʹ�
	int a, cnt, key, index;
	int* y;
	puts("�����˻�(���ʹ�)");
	printf("��� ���� : ");
	scanf_s("%d", &cnt);
	y = calloc(cnt + 1, sizeof(int));
	for (a = 0; a < cnt; a++) {
		printf("y[%d] : ", a);
		scanf_s("%d", &y[a]);
	}
	printf("�˻��� : ");
	scanf_s("%d", &key);
	index = search_2(y, cnt, key);
	if (index == -1)
		puts("�˻� ����");
	else
		printf("%d(��)�� x[%d]�� �ֽ��ϴ�\n", key, index);
	free(y);
	return 0;
}