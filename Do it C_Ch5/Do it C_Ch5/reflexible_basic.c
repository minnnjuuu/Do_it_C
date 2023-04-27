#include <stdio.h>
#include <stdlib.h>

//���� n�� �������� ���� ��ȯ
int factorial(int n) {
	if (n > 0)
		return n * factorial(n - 1);
	else
		return 1;
}

//��Ŭ���� ȣ������ ���� �ִ������� ���ϴ� �Լ�
int gcd(int x, int y) {
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}

//�迭 a�� ��� ����� �ִ����� ���ϴ� �Լ�
int gcd_array(const int a[], int n) {
	if (n == 1)
		return a[0];
	else if (n == 2)
		return gcd(a[0], a[1]);
	else
		return gcd(a[0], gcd_array(&a[1], n - 1));
}

int main(void) {
	//��������
	int a;
	printf("������ �Է��ϼ��� : ");
	scanf_s("%d", &a);
	printf("%d�� �������� ���� %d�Դϴ�\n", a, factorial(a));

	//�ִ����� ���ϱ�
	int b, c;
	puts("�� ������ �ִ������� ���մϴ�");
	printf("������ �Է��ϼ��� : ");
	scanf_s("%d", &b);
	printf("������ �Է��ϼ��� : ");
	scanf_s("%d", &c);
	printf("�ִ������� %d�Դϴ�\n", gcd(b, c));

	//�������� ������ �ִ����� ���ϱ�
	int d;
	int* f;
	printf("����� ���� : ");
	scanf_s("%d", &d);
	f = calloc(d, sizeof(int));
	for (int i = 0; i < d; i++) {
		printf("���� �Է� : ");
		scanf_s("%d", &f[i]);
	}
	printf("�ִ������� %d�Դϴ�\n", gcd_array(f, d));











	return 0;
}