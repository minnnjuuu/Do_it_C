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
	//1부터 n까지의 정수 합 구하기
	int n, sum = 0;
	puts("1부터 n까지의 합을 구합니다");//puts : 출력하는 문자열 뒤에 자동으로 줄바꿈 해줌
	do {
		printf("정수 n 입력 : ");
		scanf_s("%d", &n);
	} while (n <= 0);
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	printf("1부터 %d까지의 합은 %d입니다\n", n, sum);

	//1부터 m까지 정수 합 과wjd 풀어쓰기
	int m, sum1=0;
	puts("1부터 m까지의 합을 구합니다");
	printf("정수 m 입력 : ");
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
	//양의 정수 자릿수 구하기
	int y, digits = 0;
	puts("양의 정수 y의 자릿수를 출력합니다");
	do {
		printf("정수 y 입력 : ");
		scanf_s("%d", &y);
	} while (y <= 0);
	while (y>0) {
		y = y / 10;
		digits++;
	}
	printf("양수는 %d 자릿수 입니다\n",digits);
	//곱셈표 출력
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
	//n단 피라미트 출력
	int z;
	do {
		printf("몇 단 피라미드를 만드시겠습니까? ");
		scanf_s("%d", &z);
	} while (z <= 0);
	piramid(z);
	return 0;
}