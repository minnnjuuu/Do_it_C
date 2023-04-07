#include <stdio.h>
void piramid(int m) {
	for (int num = 1; num <= m; num++) {
		for (int x = 0; x <= m - num; x++) {
			printf(" ");
		}
		for (int y = 1; y <= 2 * num - 1; y++) {
			printf("*");
		}
		printf("\n");
	}
}
int main(void) {
	//1���� n������ ���� �� ���ϱ�
	int n, sum = 0;
	puts("1���� n������ ���� ���մϴ�");//puts : ����ϴ� ���ڿ� �ڿ� �ڵ����� �ٹٲ� ����
	do {
		printf("���� n �Է� : ");
		scanf_s("%d", &n);
	} while (n <= 0);
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	printf("1���� %d������ ���� %d�Դϴ�\n", n, sum);

	//1���� m���� ���� �� ��wjd Ǯ���
	int m, sum1=0;
	puts("1���� m������ ���� ���մϴ�");
	printf("���� m �Է� : ");
	scanf_s("%d", &m);
	for (int x = 1; x <= m; x++) {
		if (x != m) {
			printf("%d + ", x);
		}
		else {
			printf("%d = ", x);
		}
		sum1 += x;
	}
	printf("%d\n", sum1);
	//���� ���� �ڸ��� ���ϱ�
	int y, digits = 0;
	puts("���� ���� y�� �ڸ����� ����մϴ�");
	do {
		printf("���� y �Է� : ");
		scanf_s("%d", &y);
	} while (y <= 0);
	while (y>0) {
		y = y / 10;
		digits++;
	}
	printf("����� %d �ڸ��� �Դϴ�\n",digits);
	//����ǥ ���
	printf("    |");
	for (int num = 1; num <= 9; num++) {
		printf("%3d", num);
	}
	printf("\n");
	printf("---+-----------------------------\n");
	for (int num1 = 1; num1 <= 9; num1++) {
		printf("%3d |", num1);
		for (int num2 = 1; num2 <= 9; num2++) {
			printf("%3d", num1 * num2);
		}
		printf("\n");
	}
	//n�� �Ƕ��Ʈ ���
	int z;
	do {
		printf("�� �� �Ƕ�̵带 ����ðڽ��ϱ�? ");
		scanf_s("%d", &z);
	} while (z <= 0);
	piramid(z);
	return 0;
}