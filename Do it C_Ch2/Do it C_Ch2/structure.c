#include <stdio.h>

//����ü
//��ü�˻� �����Ϳ� ����ü �迭
#define VMAX 21

//��ü�˻� ��������
typedef struct {
	char name[20];
	int height;
	double vision;
} PhysCheck;

//Ű�� ��հ� ���ϱ�
double ave_height(const PhysCheck dat[], int n) {
	int i;
	double sum = 0;
	for (i = 0; i < n; i++)
		sum += dat[i].height;
	return sum / n;
}

//�÷� ���� ���ϱ�
void dist_vision(const PhysCheck dat[], int n, int dist[]) {
	int i;
	for (i = 0; i < VMAX; i++)
		dist[i] = 0;
	for (i = 0; i < n; i++)
		if (dat[i].vision >= 0.0 && dat[i].vision <= VMAX / 10.0)
			dist[(int)(dat[i].vision * 10)]++;
}

//��¥ ����ü
typedef struct {
	int y;
	int m;
	int d;
} Date;

//y�� m�� d���� ��ȯ�ϴ� �Լ�
Date DateOf(int y, int m, int d) {
	Date temp;
	temp.y = y;
	temp.m = m;
	temp.d = d;
	return temp;
}

//����,��� �� ���� �� ��
int mdays[][12] = {
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}
};

//����,��� �Ǵ�
int isleap(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	//4�� ����̸鼭 100�� ����� �ƴϰų�, 400�� ��� �̸� ����
	//�����̸� 1, ����̸� 0 ��ȯ
}

//��¥ x�� n�� ���� ��¥�� ��ȯ�ϴ� �Լ�
Date After(Date day, int n) {
	day.d += n;
	while (day.d > mdays[isleap(day.y)][day.m - 1]) {
		day.d -= mdays[isleap(day.y)][day.m - 1];
		day.m++;
		if (day.m > 12) {
			day.y++;
			day.m = 1;
		}
	}
	return day;
}

//��¥ x�� n�� ���� ��¥�� ��ȯ�ϴ� �Լ�
Date Before(Date day, int n) {
	day.d -= n;
	while (day.d <= 0) {
		day.m -= 1;
		day.d += mdays[isleap(day.y)][day.m - 1];
		if (day.m <= 0) {
			day.y--;
			day.m = 12;
		}
	}
	return day;
}



int main(void) {
	//��ü�˻� ����ü
	int i;
	PhysCheck x[] = {
		{"������",162,0.3},
		{"������",173,0.7},
		{"������",175,2.0},
		{"ȫ����",171,1.5},
		{"�̼���",168,0.4},
		{"�迵��",174,1.2},
		{"�ڿ��",169,0.8}
	};
	int nx = sizeof(x) / sizeof(x[0]);
	int vdist[VMAX];
	printf("--- ��ü�˻�ǥ ---\n");
	printf("\t�̸� \tŰ   �÷�\n");
	printf("--------------------\n");
	for (i = 0; i < nx; i++)
		printf("%-18.18s%4d%5.1f\n", x[i].name, x[i].height, x[i].vision);
	printf("\n ��� Ű : %5.1f cm\n", ave_height(x, nx));
	dist_vision(x, nx, vdist);
	printf("\n�÷� ����\n");
	for (i = 0; i < VMAX; i++)
		printf("%3.1f ~ : %2d��\n", i / 10.0, vdist[i]);

	//����13
	int y, m, d;
	int n;
	Date day;
	printf("�� : ");
	scanf_s("%d", &y);
	printf("�� : ");
	scanf_s("%d", &m);
	printf("�� : ");
	scanf_s("%d", &d);

	day = DateOf(y, m, d);

	printf("�� �� ��/���� ��¥�� ���ұ��? : ");
	scanf_s("%d", &n);

	printf("%d�� ���� ��¥ : ", n);
	printf("%d�� %d�� %d��", After(day, n).y, After(day, n).m, After(day, n).d);
	printf("\n");

	printf("%d�� ���� ��¥ : ", n);
	printf("%d�� %d�� %d��", Before(day, n).y, Before(day, n).m, Before(day, n).d);
	printf("\n");
	return 0;
}




