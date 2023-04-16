#include <stdio.h>

//한 해의 지난 날 수 구하기
//각 달의 날 수
int mdays[][12] = {
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}
};

//윤년인지 아닌지
int isleap(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	//4의 배수이면서 100의 배수가 아니거나, 400의 배수 이면 윤년
}

//지난 날 수 구하기
int dayofyear(int y, int m, int d) {
	while (m-1) {
		d += mdays[isleap(y)][m - 2];
		m -= 1;
	}
	return d;
}

int main(void) {
	//1000이하의 소수 나열1 - 나눗셈 : 78022회
	int i, n;
	unsigned long counter = 0;
	for ( n = 2; n <= 1000; n++) {
		for (i = 2; i < n; i++) {
			counter++;
			if (n % i == 0) {
				break;
			}
		}
		if (n == i) {
			printf("%d\n", n);
		}
	}
	printf("나눗셈을 실행한 횟수 : %lu\n", counter);
	
	//1000이하의 소수 나열2 - 나눗셈 : 14622회
	int i_2, n_2;
	int prime[500];
	int ptr = 0;
	unsigned int counter_2 = 0;
	prime[ptr++] = 2;
	for (n_2 = 3; n_2 <= 1000; n_2+=2) {
		for (i_2 = 1; i_2 < ptr; i_2++) {
			counter_2++;
			if (n_2 % prime[i_2] == 0)
				break;
		}
		if (ptr == i_2) 
			prime[ptr++] = n_2;
	}
	for (i_2 = 0; i_2 < ptr; i_2++) {
		printf("%d\n", prime[i_2]);
	}
	printf("나눗셈을 실행한 회수 : %d\n", counter_2);

	//1000이하의 소수 나열3 - 나눗셈 : 3774회
	int i_3, n_3;
	int prime_2[500];
	unsigned long counter_3 = 0; //곱셈과 나눗셈 횟수 합계
	int ptr_2 = 0;
	prime_2[ptr_2++] = 2;
	prime_2[ptr_2++] = 3;
	for (n_3 = 5; n_3 <= 1000; n_3 += 2) {
		int flag = 0;
		for (i_3 = 1; counter_3++, prime_2[i_3]*prime_2[i_3] <= n_3; i_3++) {
			counter_3++;
			if (n_3 % prime_2[i_3] == 0) {
				flag = 1;
				break;
			}
		}
		if (flag==0)
			prime_2[ptr_2++] = n_3;
	}
	for (i_3 = 0; i_3 < ptr_2; i_3++)
		printf("%d\n", prime_2[i_3]);
	printf("곱셈과 나눗셈을 실행한 횟수 : %lu\n", counter_3);

	//다차원 배열
	//한 해의 지난 날 수 구하기
	int year, month, day;
	int retry;
	do {
		printf("년 : ");
		scanf_s("%d", &year);
		printf("월 : ");
		scanf_s("%d", &month);
		printf("일 : ");
		scanf_s("%d", &day);
		printf("%d년의 %d일쨰 입니다", year, dayofyear(year, month, day));
		printf("다시 할까요?(1 ''' 예/0 ''' 아니요) : ");
		scanf_s("%d", &retry);
	} while (retry == 1);

	return 0;
}