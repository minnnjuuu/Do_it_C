#include <stdio.h>

int max4(int a, int b, int c, int d) {
	int max_4 = a;
	if (b > max_4) max_4 = b;
	if (c > max_4) max_4 = c;
	if (d > max_4) max_4 = d;
	return max_4;
}
int medi3(int a, int b, int c) {
	if (a >= b) {
		if (b >= c) return b;
		else if (a <= c) return a;
		else return c;
	}
	else if (a > c) return a;
	else if (b > c) return c;
	else return b;
}

int main_algorithm(void) {
	//�� ���� �߿��� �ִ밪 ���ϱ�
	int a, b, c;
	int max;
	printf("�������� �ִ밪�� ���մϴ�\n");
	printf("a�� �� : "); scanf_s("%d", &a);
	printf("b�� �� : "); scanf_s("%d", &b);
	printf("c�� �� : "); scanf_s("%d", &c);
	max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	printf("�ִ��� %d�Դϴ�\n",max);

	//�� ���� �߿��� �ִ밪 ���ϱ�
	int d, e, f, g;
	printf("�������� �ִ밪 ���մϴ�\n");
	printf("d�� �� : "); scanf_s("%d", &d);
	printf("e�� �� : "); scanf_s("%d", &e);
	printf("f�� �� : "); scanf_s("%d", &f);
	printf("g�� �� : "); scanf_s("%d", &g);
	printf("max4(%d, %d, %d, %d) = %d\n", d, e, f, g, max4(d, e, f, g));

	//�� ������ �߿��� �߾Ӱ� ���ϱ�
	int h, i, j;
	printf("�������� �߾Ӱ��� ���մϴ�\n");
	printf("h�� �� : "); scanf_s("%d", &h);
	printf("i�� �� : "); scanf_s("%d", &i);
	printf("j�� �� : "); scanf_s("%d", &j);
	printf("medi3(%d, %d, %d) = %d", h, i, j, medi3(h, i, j));

	return 0;
}
