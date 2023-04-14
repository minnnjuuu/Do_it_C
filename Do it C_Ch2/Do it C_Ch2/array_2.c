#include <time.h>
#include <stdio.h>
#include <stdlib.h>

//68p ~ 75p
//2~36���� ��� ��ȯ �Լ�
//���� �� x�� n������ ��ȯ�Ͽ� �迭 d�� �Ʒ��ڸ����� ����
int card_convr(unsigned x, int n, char d[]) {
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0;
	if (x == 0) {
		d[digits++] = dchar[0];
	}
	else {
		while (x) {
			d[digits++] = dchar[x % n];
			x /= n;
		}
	}
	return digits;
}

//Ű(cm) �հ� ���ϴ� �Լ�
int sumof(const int a[], int n) {
	int sum = a[0];
	for (int i = 1; i < n; i++) {
		sum += a[i];
	}
	return sum;
}

//��Ұ����� n�� �迭 a�� ����� �ִ� ���ϱ�
int maxof(const int a[], int n) {
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}

//�������� �����ϴ� ���� ������ ����ϴ� �Լ�
void ary_reverse(int a[], int n) {
	int t;
	for (int i = 0; i < n / 2; i++) {
		t = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = t;
		printf("a[%d]��(��) a[%d]�� ��ȯ�մϴ�\n",i,n-i-1);
		for (int m = 0; m < n; m++) {
			printf("%d ", a[m]);
		}
		printf("\n");
	}
}

//��� ��ȯ ���� �� ��� �Լ�
#define swap(type,x,y) do {type t=x;x=y;y=t;} while(0)

int card_conv(unsigned x, int n, char d[]) {
	int digits = 0;
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (x == 0) {
		d[digits++] = dchar[0];
	}
	else {
		while (x) {
			printf("%2d | %7d ... %c\n", n, x, dchar[x % n]);
			printf("   + --------\n");
			d[digits++] = dchar[x % n];
			x /= n;
		}
		printf("%12d\n", x);
	}
	for (int i = 0; i < digits / 2; i++) {
		swap(char, d[i], d[digits - i - 1]);
	}
	return digits;
}

int main(void) {
	//��� ��ȯ�ϱ�
	unsigned no; //��ȯ�� ����
	int cd; //���
	int dno; //��ȯ�� �ڸ���
	char cno[512]; //��ȯ�� ���� �� �ڸ��� ���ڸ� �����ϴ� ���ڹ迭
	int retry; //��� ���� ����
	printf("10������ ��� ��ȯ�մϴ�.\n");
	do {
		printf("��ȯ�ϴ� ���� �ƴ� ���� �Է� : ");
		scanf_s("%u", &no);
		do {
			printf("� ������ ��ȯ�ұ��? ");
			scanf_s("%d", &cd);
		} while (cd < 2 || cd>36);
		dno = card_convr(no, cd, cno);
		printf("%d�����δ� ", cd);
		for (int i = dno - 1; i >= 0; i--) {
			printf("%c", cno[i]);
		}
		printf("�Դϴ�\n");
		printf("�ѹ� �� �ұ��? 1��: �� / 0�� : �ƴϿ�    ");
		scanf_s("%d", &retry);
	} while (retry == 1);

	//����2
	//Ű(cm)���հ� ���ϱ�
	int* height;
	int number;
	printf("����� �� : ");
	scanf_s("%d", &number);
	height = calloc(number, sizeof(int));
	printf("%d ����� Ű�� �Է��ϼ��� \n", number);
	for (int i = 0; i < number; i++) {
		printf("height[%d] : ", i);
		scanf_s("%d", &height[i]);
	}
	printf("Ű�� �հ�� %d�Դϴ�\n", sumof(height, number));
	free(height);

	//����4
	//Ű�� ����� ������ �����Ͽ� Ű�� �ִ밪���ϱ�
	//��� ���� 5�̻� 20����
	//Ű�� 100�̻� 189����
	int* height_2;
	int number_2;
	srand(time(NULL));
	number_2 = 5 + rand() % 16;
	printf("��� �� : %d\n",number_2);
	height_2 = calloc(number_2, sizeof(int));
	for (int i = 0; i < number_2; i++) {
		height_2[i] = 100 + rand() % 90;
		printf("height_2[%d] = %d\n", i, height_2[i]);
	}
	printf("�ִ��� %d�Դϴ�\n", maxof(height_2, number_2));
	free(height_2);

	//����5
	//�������� �����ϴ� ���� ������ ����ϱ�
	int* x; //�迭 ù ���� ����� ������
	int nx; //�迭 x�� ��� ����
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));
	printf("%d���� ������ �Է��ϼ���.\n", nx);
	for (int i = 0; i < nx; i++) {
		printf("x[%d] = ", i);
		scanf_s("%d", &x[i]);
	}
	ary_reverse(x, nx);
	free(x);
	printf("���� ������ �����մϴ�\n");

	//����7
	//�����ȯ ���� ���� ����ϱ�
	unsigned no_2;
	int cd_2;
	int dno_2;
	int retry_2;
	char cno_2[512];
	printf("10������ ��� ��ȯ�մϴ�.\n");
	do {
		printf("��ȯ�ϴ� ���� �ƴ� ���� : ");
		scanf_s("%u", &no_2);
		do {
			printf("� ������ ��ȯ�ұ��?(2-36) : ");
			scanf_s("%d", &cd_2);
		} while (cd_2 < 2 || cd_2>36);
		dno_2 = card_conv(no_2, cd_2, cno_2);
		printf("%d ������ ", cd_2);
		for (int i = 0; i < dno_2; i++) {
			printf("%c", cno_2[i]);
		}
		printf("�Դϴ�\n");
		printf("�ٽ� �ѹ� �ұ��?(1 �� / 0 �ƴϿ�) : ");
		scanf_s("%d", &retry_2);
	} while (retry_2 == 1);
	return 0;
}