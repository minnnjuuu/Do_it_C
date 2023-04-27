#include <stdio.h>
#include <stdlib.h>

//정수 n의 순차곱셈 값을 반환
int factorial(int n) {
	if (n > 0)
		return n * factorial(n - 1);
	else
		return 1;
}

//유클리드 호제법에 의해 최대공약수를 구하는 함수
int gcd(int x, int y) {
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}

//배열 a의 모든 요소의 최대공약수 구하는 함수
int gcd_array(const int a[], int n) {
	if (n == 1)
		return a[0];
	else if (n == 2)
		return gcd(a[0], a[1]);
	else
		return gcd(a[0], gcd_array(&a[1], n - 1));
}

int main(void) {
	//순차곱셈
	int a;
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &a);
	printf("%d의 순차곱셈 값은 %d입니다\n", a, factorial(a));

	//최대공약수 구하기
	int b, c;
	puts("두 정수의 최대공약수를 구합니다");
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &b);
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &c);
	printf("최대공약수는 %d입니다\n", gcd(b, c));

	//여러개의 정수의 최대공약수 구하기
	int d;
	int* f;
	printf("요소의 개수 : ");
	scanf_s("%d", &d);
	f = calloc(d, sizeof(int));
	for (int i = 0; i < d; i++) {
		printf("정수 입력 : ");
		scanf_s("%d", &f[i]);
	}
	printf("최대공약수는 %d입니다\n", gcd_array(f, d));











	return 0;
}