#include <stdio.h>
#include "IntStack.h"

//�ϳ����� ž(���)
void move(int no, int x, int y) {
	if (no > 1)
		move(no - 1, x, 6 - x - y);
	printf("����[%d]��(��) %d��տ��� %d ������� �ű�\n", no, x, y);
	if (no > 1)
		move(no - 1, 6 - x - y, y);
}

//�ϳ����� ž(�����)
void move_2(int no, int x, int y) {
	int sw = 0;
	IntStack stk_1, stk_2, stk_3;
	Initialize(&stk_1, 100);
	Initialize(&stk_2, 100);
	Initialize(&stk_3, 100);
	while (1) {
		if (sw == 0 && no > 1) {
			Push(&stk_1, x);
			Push(&stk_2, y);
			Push(&stk_3, sw);
			no = no - 1;
			y = 6 - x - y;
			continue;
		}
		printf("���� [%d]�� %d��տ��� %d������� �̵�\n", no, x, y);
		if (sw == 1 && no > 1) {
			Push(&stk_1, x);
			Push(&stk_2, y);
			Push(&stk_3, sw);
			no = no - 1;
			x = 6 - x - y;
			if (++sw == 2)
				sw = 0;
			continue;
		}
		do {
			if (IsEmpty(&stk_1))
				return;
			Pop(&stk_1, &x);
			Pop(&stk_2, &y);
			Pop(&stk_3, &sw);
			sw++;
			no++;
		} while (sw == 2);
	}
	Terminate(&stk_1);
	Terminate(&stk_2);
	Terminate(&stk_3);
}


int main(void) {
	int n;
	puts("�ϳ����� ž");
	printf("���� ���� : ");
	scanf_s("%d", &n);
	move(n, 1, 3);

	int m;
	puts("�ϳ����� ž (�����)");
	printf("���� ���� : ");
	scanf_s("%d", &m);
	move_2(m, 1, 3);
	return 0;
}