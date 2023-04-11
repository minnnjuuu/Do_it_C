//å ch2 67p ����
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define a 5
#define swap(type,x,y) do{type l = x;x = y;y = l;} while(0) //type �� x,y ���� ��ȯ

//��� ������ i�� �迭 h�� ����� �ִ� ���ϴ� �Լ�
int maxof(const int h[], int i) {
	int max = h[0];
	for (int j = 1; j < i; j++) {
		if (h[j] > max) {
			max = h[j];
		}
	}
	return max;
}

//��� ������ m�� �迭 n�� ��Ҹ� �������� ����
void array_reverse(int n[], int m) {
	for (int o = 0; o < m / 2; o++) {
		swap(int, n[o], n[m - o - 1]);
	}
}

int main(void) {
	//���� 5�� �Է¹޾� ���
	int b;
	int c[5];
	for (b = 0; b < a; b++) {
		printf("c[%d] : ", b);
		scanf_s("%d", &c[b]);
	}
	puts("�� ����� ��");
	for (b = 0; b < a; b++) {
		printf("c[%d] = %d\n", b, c[b]);
	}

	//int�� ��ü�� �������� �����ϰ� ����-���� ��ü
	int* d;
	d = calloc(1, sizeof(int));
	if (d == NULL) {
		puts("�޸� �Ҵ� ����");
	}
	else {
		*d = 57;
		printf("*d = %d\n", *d);
		free(d);
	}

	//int �� ��ü�� �������� �����ϰ� ����-�迭 ��ü
	int e;
	int* f; //�迭 ������
	int g;  //�迭�� ��� ����
	printf("��� ���� : ");
	scanf_s("%d", &g);
	f = calloc(g, sizeof(int));
	if (f == NULL) {
		printf("�޸� Ȯ�� ����");
	}
	else {
		printf("%d���� ������ �Է��ϼ���\n", g);
		for (e = 0; e < g; e++) {
			printf("f[%d] = ", e);
			scanf_s("%d", &f[e]);
		}
		printf("�� ����� ���� �Ʒ��� �����ϴ�.\n");
		for (e = 0; e < g; e++) {
			printf("f[%d] = %d\n", e, f[e]);
		}
		free(f);
	}

	//���� �Է¹��� �迭 ����� �ִ� ���ϱ�
	int* height; //�迭�� ù��° ����� ������
	int number; //�ο� = �迭 height�� ��� ����
	printf("��� �� : ");
	scanf_s("%d", &number);
	height = calloc(number, sizeof(int));
	if (height == NULL) {
		printf("�޸� Ȯ�� ����");
	}
	printf("%d ���� Ű�� �Է��ϼ��� \n", number);
	for (int h = 0; h < number; h++) {
		printf("height[%d] : ", h);
		scanf_s("%d", &height[h]);
	}
	printf("�ִ��� %d�Դϴ�.\n", maxof(height, number));
	free(height);

	//���� ����� �迭�� ��ڰ� �����ϱ�
	int* height_2;
	int number_2;
	printf("��� �� : ");
	scanf_s("%d", &number_2);
	height_2 = calloc(number_2, sizeof(int));
	srand(time(NULL));
	for (int k = 0; k < number_2; k++) {
		height_2[k] = 100 + rand() % 90;
		printf("height_2[%d} = %d\n", k, height_2[k]);
	}
	printf("�ִ��� %d�Դϴ�\n", maxof(height_2, number_2));
	free(height_2);

	//�迭 ��� �������� ����
	int* p; //�迭 ù ��° ����� ������
	int q;  //�迭 p�� ��� ����
	printf("��� ���� : ");
	scanf_s("%d", &q);
	p = calloc(q, sizeof(int));
	printf("%d���� ������ �Է��ϼ���\n", q);
	for (int i = 0; i < q; i++) {
		printf("p[%d] : ", i);
		scanf_s("%d", &p[i]);
	}
	array_reverse(p, q);
	printf("�迭�� ��Ҹ� �������� �����߽��ϴ�\n");
	for (int r = 0; r < q; r++) {
		printf("p[%d] = %d\n", r, p[r]);
	}
	free(p);
	return 0;
}