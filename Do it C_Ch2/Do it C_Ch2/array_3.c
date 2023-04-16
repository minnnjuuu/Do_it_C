#include <stdio.h>

//�� ���� ���� �� �� ���ϱ�
//�� ���� �� ��
int mdays[][12] = {
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}
};

//�������� �ƴ���
int isleap(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	//4�� ����̸鼭 100�� ����� �ƴϰų�, 400�� ��� �̸� ����
}

//���� �� �� ���ϱ�
int dayofyear(int y, int m, int d) {
	while (m-1) {
		d += mdays[isleap(y)][m - 2];
		m -= 1;
	}
	return d;
}

int main(void) {
	//1000������ �Ҽ� ����1 - ������ : 78022ȸ
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
	printf("�������� ������ Ƚ�� : %lu\n", counter);
	
	//1000������ �Ҽ� ����2 - ������ : 14622ȸ
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
	printf("�������� ������ ȸ�� : %d\n", counter_2);

	//1000������ �Ҽ� ����3 - ������ : 3774ȸ
	int i_3, n_3;
	int prime_2[500];
	unsigned long counter_3 = 0; //������ ������ Ƚ�� �հ�
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
	printf("������ �������� ������ Ƚ�� : %lu\n", counter_3);

	//������ �迭
	//�� ���� ���� �� �� ���ϱ�
	int year, month, day;
	int retry;
	do {
		printf("�� : ");
		scanf_s("%d", &year);
		printf("�� : ");
		scanf_s("%d", &month);
		printf("�� : ");
		scanf_s("%d", &day);
		printf("%d���� %d�Ϥ� �Դϴ�", year, dayofyear(year, month, day));
		printf("�ٽ� �ұ��?(1 ''' ��/0 ''' �ƴϿ�) : ");
		scanf_s("%d", &retry);
	} while (retry == 1);

	return 0;
}