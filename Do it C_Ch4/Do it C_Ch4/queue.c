#include <stdio.h>
#include "IntQueue.h"

#define N 10

int main(void) {
	IntQueue que;

	if (Initialize(&que, 64) == -1) {
		puts("ť�� ������ �����Ͽ����ϴ�");
		return 1;
	}
	while (1) {
		int m, x;
		printf("���� ������ �� : %d / %d \n", Size(&que), Capacity(&que));
		printf("(1)��ť (2)��ť (3)��ũ (4)��� (0)���� : ");
		scanf_s("%d", &m);
		if (m == 0) break;
		switch (m) {
		case 1:
			printf("������ : ");
			scanf_s("%d", &x);
			if (Enque(&que, x) == -1)
				puts("\a���� : ��ť�� �����Ͽ����ϴ�.");
			break;
		case 2:
			if (Deque(&que, &x) == -1)
				puts("\a���� : ��ť�� �����Ͽ����ϴ�");
			else
				printf("��ť�� �����ʹ� %d�Դϴ�\n", x);
			break;
		case 3:
			if (Peek(&que, &x) == -1)
				puts("\a���� : ��ũ�� �����Ͽ����ϴ�");
			else
				printf("��ũ�� �����ʹ� %d�Դϴ�\n", x);
			break;
		case 4:
			Print(&que);
			break;
		}
	}
	Terminate(&que);

	//���ϴ� ������ŭ �����͸� �Է��ϰ�, ����� ������ n�� �迭���� �ֱٿ� �Է��� n���� ����
	int a;
	int b[N];
	int cnt = 0;
	int retry;
	puts("������ �Է��ϼ���");
	do {
		printf("%d��° ���� : ", cnt + 1);
		scanf_s("%d", &b[cnt++ % N]);
		printf("����ұ��?(YES ''' 1/NO ''' 0) : ");
		scanf_s("%d", &retry);
	} while (retry == 1);
	a = cnt - N;
	if (a < 0) a = 0;
	for (; a < cnt; a++)
		printf("%2d���� ���� = %d\n", a + 1, b[a % 10]);
	return 0;
}