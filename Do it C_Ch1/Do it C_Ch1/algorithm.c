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
	//세 정수 중에서 최대값 구하기
	int a, b, c;
	int max;
	printf("세정수의 최대값을 구합니다\n");
	printf("a의 값 : "); scanf_s("%d", &a);
	printf("b의 값 : "); scanf_s("%d", &b);
	printf("c의 값 : "); scanf_s("%d", &c);
	max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	printf("최댓값은 %d입니다\n",max);

	//네 정수 중에서 최대값 구하기
	int d, e, f, g;
	printf("네정수의 최대값 구합니다\n");
	printf("d의 값 : "); scanf_s("%d", &d);
	printf("e의 값 : "); scanf_s("%d", &e);
	printf("f의 값 : "); scanf_s("%d", &f);
	printf("g의 값 : "); scanf_s("%d", &g);
	printf("max4(%d, %d, %d, %d) = %d\n", d, e, f, g, max4(d, e, f, g));

	//세 정수의 중에서 중앙값 구하기
	int h, i, j;
	printf("세정수의 중앙값을 구합니다\n");
	printf("h의 값 : "); scanf_s("%d", &h);
	printf("i의 값 : "); scanf_s("%d", &i);
	printf("j의 값 : "); scanf_s("%d", &j);
	printf("medi3(%d, %d, %d) = %d", h, i, j, medi3(h, i, j));

	return 0;
}
