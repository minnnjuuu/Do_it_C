#include <time.h>
#include <stdio.h>
#include <stdlib.h>

//68p ~ 75p
//2~36진수 기수 변환 함수
//정수 값 x를 n진수로 변환하여 배열 d에 아랫자리부터 저장
int card_convr(unsigned x, int n, char d[]) {
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0;
	if (x == 0) {
		d[digits++] = dchar[0];
	}
	else {
		while (x) {
			d[digits++] = dchar[x % n];
			x /= n;
		}
	}
	return digits;
}

//키(cm) 합계 구하는 함수
int sumof(const int a[], int n) {
	int sum = a[0];
	for (int i = 1; i < n; i++) {
		sum += a[i];
	}
	return sum;
}

//요소개수가 n인 배열 a의 요소의 최댓값 구하기
int maxof(const int a[], int n) {
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}

//역순으로 정렬하는 과정 일일이 출력하는 함수
void ary_reverse(int a[], int n) {
	int t;
	for (int i = 0; i < n / 2; i++) {
		t = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = t;
		printf("a[%d]와(과) a[%d]를 교환합니다\n",i,n-i-1);
		for (int m = 0; m < n; m++) {
			printf("%d ", a[m]);
		}
		printf("\n");
	}
}

//기수 변환 과정 상세 출력 함수
#define swap(type,x,y) do {type t=x;x=y;y=t;} while(0)

int card_conv(unsigned x, int n, char d[]) {
	int digits = 0;
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (x == 0) {
		d[digits++] = dchar[0];
	}
	else {
		while (x) {
			printf("%2d | %7d ... %c\n", n, x, dchar[x % n]);
			printf("   + --------\n");
			d[digits++] = dchar[x % n];
			x /= n;
		}
		printf("%12d\n", x);
	}
	for (int i = 0; i < digits / 2; i++) {
		swap(char, d[i], d[digits - i - 1]);
	}
	return digits;
}

int main(void) {
	//기수 변환하기
	unsigned no; //변환할 정수
	int cd; //기수
	int dno; //변환한 자릿수
	char cno[512]; //변환한 값의 각 자리의 숫자를 저장하는 문자배열
	int retry; //계속 할지 말지
	printf("10진수를 기수 변환합니다.\n");
	do {
		printf("변환하는 음이 아닌 정수 입력 : ");
		scanf_s("%u", &no);
		do {
			printf("어떤 진수로 변환할까요? ");
			scanf_s("%d", &cd);
		} while (cd < 2 || cd>36);
		dno = card_convr(no, cd, cno);
		printf("%d진수로는 ", cd);
		for (int i = dno - 1; i >= 0; i--) {
			printf("%c", cno[i]);
		}
		printf("입니다\n");
		printf("한번 더 할까요? 1번: 예 / 0번 : 아니요    ");
		scanf_s("%d", &retry);
	} while (retry == 1);

	//문제2
	//키(cm)의합계 구하기
	int* height;
	int number;
	printf("사람의 수 : ");
	scanf_s("%d", &number);
	height = calloc(number, sizeof(int));
	printf("%d 사람의 키를 입력하세요 \n", number);
	for (int i = 0; i < number; i++) {
		printf("height[%d] : ", i);
		scanf_s("%d", &height[i]);
	}
	printf("키의 합계는 %d입니다\n", sumof(height, number));
	free(height);

	//문제4
	//키와 사람수 난수로 생성하여 키의 최대값구하기
	//사람 수는 5이상 20이하
	//키는 100이상 189이하
	int* height_2;
	int number_2;
	srand(time(NULL));
	number_2 = 5 + rand() % 16;
	printf("사람 수 : %d\n",number_2);
	height_2 = calloc(number_2, sizeof(int));
	for (int i = 0; i < number_2; i++) {
		height_2[i] = 100 + rand() % 90;
		printf("height_2[%d] = %d\n", i, height_2[i]);
	}
	printf("최댓값은 %d입니다\n", maxof(height_2, number_2));
	free(height_2);

	//문제5
	//역순으로 정렬하는 과정 일일이 출력하기
	int* x; //배열 첫 번쨰 요소의 포인터
	int nx; //배열 x의 요소 개수
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));
	printf("%d개의 정수를 입력하세요.\n", nx);
	for (int i = 0; i < nx; i++) {
		printf("x[%d] = ", i);
		scanf_s("%d", &x[i]);
	}
	ary_reverse(x, nx);
	free(x);
	printf("역순 정렬을 종료합니다\n");

	//문제7
	//기수변환 과정 상세히 출력하기
	unsigned no_2;
	int cd_2;
	int dno_2;
	int retry_2;
	char cno_2[512];
	printf("10진수를 기수 변환합니다.\n");
	do {
		printf("변환하는 음이 아닌 정수 : ");
		scanf_s("%u", &no_2);
		do {
			printf("어떤 진수를 변환할까요?(2-36) : ");
			scanf_s("%d", &cd_2);
		} while (cd_2 < 2 || cd_2>36);
		dno_2 = card_conv(no_2, cd_2, cno_2);
		printf("%d 진수로 ", cd_2);
		for (int i = 0; i < dno_2; i++) {
			printf("%c", cno_2[i]);
		}
		printf("입니다\n");
		printf("다시 한번 할까요?(1 예 / 0 아니오) : ");
		scanf_s("%d", &retry_2);
	} while (retry_2 == 1);
	return 0;
}