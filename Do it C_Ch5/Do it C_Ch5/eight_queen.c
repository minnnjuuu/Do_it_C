#include <stdio.h>

//각 행, 각 열에 1개의 퀸을 배치하는 조합을 재귀적으로 나열
int flag[8];
int pos[8];

void print(void) {
	int i;
	for (i = 0; i < 8; i++)
		printf("%2d", pos[i]);
	putchar('\n');
}

void set(int i) {
	for (int j = 0; j < 8; j++) {
		if (!flag[j]) {
			pos[i] = j;
			if (i == 7)
				print();
			else {
				flag[j] = 1;
				set(i + 1);
				flag[j] = 0;
			}
		}
	}
}

//찐 8퀸 문제 풀기
int flag_a[8];
int flag_b[15];
int flag_c[15];
int pos[8];

void set_2(int i) {
	int j;
	for (j = 0; j < 8; j++) {
		if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7]) {
			pos[i] = j;
			if (i == 7)
				print();
			else {
				flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
				set_2(i + 1);
				flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
			}
		}
	}
}


int main(void) {
	for (int i = 0; i < 8; i++)
		flag[i] = 0;
	set(0);

	for (int i = 0; i < 8; i++)
		flag_a[i] = 0;
	for (int i = 0; i < 15; i++)
		flag_b[i] = flag_c[i] = 0;
	set_2(0);

	return 0;
}