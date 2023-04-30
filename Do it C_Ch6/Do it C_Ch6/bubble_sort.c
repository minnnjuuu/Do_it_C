#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{ type t = x; x = y; y = t;} while (0)

//���� ���� �Լ�(�����ʺ��� ����)
void bubble(int a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				swap(int, a[j - 1], a[j]);
	}
}

//���� ���� �Լ�(���ʺ��� ����)
void bubble_2(int a[], int n) {
	int i, j;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++)
			if (a[j - 1] > a[j])
				swap(int, a[j - 1], a[j]);
	}
}

//���� ���� - ��ȯ Ƚ���� ���� �����۾� ����
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

//���� ���� - ��ĵ ���� ����
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
	puts("���� ����");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	bubble(x, nx);
	puts("�����ʺ��� ���� ����");
	puts("������������ �����߽��ϴ�");
	for (i = 0; i < nx; i++) {
		printf("x[%d] : %d\n", i, x[i]);
	}

	//���� 1��
	//���ʺ��� ���������ϴ� ���α׷� �ۼ�
	bubble_2(x, nx);
	puts("���ʺ��� ���� ����");
	puts("������������ �����߽��ϴ�");
	for (i = 0; i < nx; i++) {
		printf("x[%d] : %d\n", i, x[i]);
	}

	//��ȯ Ƚ���� ���� ���� �۾� ����
	bubble_3(x, nx);
	puts("��ȯ Ƚ���� ���� ����");
	puts("������������ �����߽��ϴ�");
	for (i = 0; i < nx; i++) {
		printf("x[%d] : %d\n", i, x[i]);
	}

	//��ĵ ���� ����
	bubble_4(x, nx);
	puts("��ĵ ���� ���� ����");
	puts("������������ �����߽��ϴ�");
	for (i = 0; i < nx; i++)
		printf("x[%d] : %d\n", i, x[i]);
	
	free(x);
	return 0;
}
