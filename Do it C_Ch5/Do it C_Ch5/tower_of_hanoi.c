#include <stdio.h>
#include "IntStack.h"

//하노이의 탑(재귀)
void move(int no, int x, int y) {
	if (no > 1)
		move(no - 1, x, 6 - x - y);
	printf("원반[%d]를(을) %d기둥에서 %d 기둥으로 옮김\n", no, x, y);
	if (no > 1)
		move(no - 1, 6 - x - y, y);
}

//하노이의 탑(비재귀)
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
		printf("원판 [%d]를 %d기둥에서 %d기둥으로 이동\n", no, x, y);
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
	puts("하노이의 탑");
	printf("원판 개수 : ");
	scanf_s("%d", &n);
	move(n, 1, 3);

	int m;
	puts("하노이의 탑 (비재귀)");
	printf("원판 개수 : ");
	scanf_s("%d", &m);
	move_2(m, 1, 3);
	return 0;
}