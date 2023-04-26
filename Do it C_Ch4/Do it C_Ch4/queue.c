#include <stdio.h>
#include "IntQueue.h"

#define N 10

int main(void) {
	IntQueue que;

	if (Initialize(&que, 64) == -1) {
		puts("큐의 생성에 실패하였습니다");
		return 1;
	}
	while (1) {
		int m, x;
		printf("현재 데이터 수 : %d / %d \n", Size(&que), Capacity(&que));
		printf("(1)인큐 (2)디큐 (3)피크 (4)출력 (0)종료 : ");
		scanf_s("%d", &m);
		if (m == 0) break;
		switch (m) {
		case 1:
			printf("데이터 : ");
			scanf_s("%d", &x);
			if (Enque(&que, x) == -1)
				puts("\a오류 : 인큐에 실패하였습니다.");
			break;
		case 2:
			if (Deque(&que, &x) == -1)
				puts("\a오류 : 디큐에 실패하였습니다");
			else
				printf("디큐한 데이터는 %d입니다\n", x);
			break;
		case 3:
			if (Peek(&que, &x) == -1)
				puts("\a오류 : 피크에 실패하였습니다");
			else
				printf("피크한 데이터는 %d입니다\n", x);
			break;
		case 4:
			Print(&que);
			break;
		}
	}
	Terminate(&que);

	//원하는 개수만큼 데이터를 입력하고, 요소의 개수가 n인 배열에는 최근에 입력한 n개만 저장
	int a;
	int b[N];
	int cnt = 0;
	int retry;
	puts("정수를 입력하세요");
	do {
		printf("%d번째 정수 : ", cnt + 1);
		scanf_s("%d", &b[cnt++ % N]);
		printf("계속할까요?(YES ''' 1/NO ''' 0) : ");
		scanf_s("%d", &retry);
	} while (retry == 1);
	a = cnt - N;
	if (a < 0) a = 0;
	for (; a < cnt; a++)
		printf("%2d번쨰 정수 = %d\n", a + 1, b[a % 10]);
	return 0;
}