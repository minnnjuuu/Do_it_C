#include <stdio.h>
#include "IntStack.h"

//����Լ� recur
void recur(int n) {
	if (n > 0) {
		recur(n - 1);
		printf("%d\n", n);
		recur(n - 2);
	}
}

//������ ����� ����������� ������ recur_2
void recur_2(int n) {
	IntStack stk;
	Initialize(&stk, 100);
Top:
	if (n > 0) {
		Push(&stk, n);
		n = n - 1;
		goto Top;
	}
	if (!IsEmpty(&stk)) {
		Pop(&stk, &n);
		printf("%d\n", n);
		n = n - 2;
		goto Top;
	}
	Terminate(&stk);
}


int main(void) {
	int a;
	printf("������ �Է��ϼ��� : ");
	scanf_s("%d", &a);
	recur(a);

	int b;
	printf("������ �Է��ϼ��� : ");
	scanf_s("%d", &b);
	recur_2(b);
	return 0;
}