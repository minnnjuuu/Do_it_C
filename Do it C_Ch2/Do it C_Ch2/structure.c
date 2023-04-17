#include <stdio.h>

//구조체
//신체검사 데이터용 구조체 배열
#define VMAX 21

//신체검사 데이터형
typedef struct {
	char name[20];
	int height;
	double vision;
} PhysCheck;

//키의 평균값 구하기
double ave_height(const PhysCheck dat[], int n) {
	int i;
	double sum = 0;
	for (i = 0; i < n; i++)
		sum += dat[i].height;
	return sum / n;
}

//시력 분포 구하기
void dist_vision(const PhysCheck dat[], int n, int dist[]) {
	int i;
	for (i = 0; i < VMAX; i++)
		dist[i] = 0;
	for (i = 0; i < n; i++)
		if (dat[i].vision >= 0.0 && dat[i].vision <= VMAX / 10.0)
			dist[(int)(dat[i].vision * 10)]++;
}

//날짜 구조체
typedef struct {
	int y;
	int m;
	int d;
} Date;

//y년 m월 d일을 반환하는 함수
Date DateOf(int y, int m, int d) {
	Date temp;
	temp.y = y;
	temp.m = m;
	temp.d = d;
	return temp;
}

//윤년,평년 각 달의 일 수
int mdays[][12] = {
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}
};

//윤년,평년 판단
int isleap(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	//4의 배수이면서 100의 배수가 아니거나, 400의 배수 이면 윤년
	//윤년이면 1, 평년이면 0 반환
}

//날짜 x의 n일 뒤의 날짜를 반환하는 함수
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

//날짜 x의 n일 앞의 날짜를 반환하는 함수
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
	//신체검사 구조체
	int i;
	PhysCheck x[] = {
		{"박현규",162,0.3},
		{"함진아",173,0.7},
		{"최윤미",175,2.0},
		{"홍연의",171,1.5},
		{"이수진",168,0.4},
		{"김영준",174,1.2},
		{"박용규",169,0.8}
	};
	int nx = sizeof(x) / sizeof(x[0]);
	int vdist[VMAX];
	printf("--- 신체검사표 ---\n");
	printf("\t이름 \t키   시력\n");
	printf("--------------------\n");
	for (i = 0; i < nx; i++)
		printf("%-18.18s%4d%5.1f\n", x[i].name, x[i].height, x[i].vision);
	printf("\n 평균 키 : %5.1f cm\n", ave_height(x, nx));
	dist_vision(x, nx, vdist);
	printf("\n시력 분포\n");
	for (i = 0; i < VMAX; i++)
		printf("%3.1f ~ : %2d명\n", i / 10.0, vdist[i]);

	//문제13
	int y, m, d;
	int n;
	Date day;
	printf("년 : ");
	scanf_s("%d", &y);
	printf("월 : ");
	scanf_s("%d", &m);
	printf("일 : ");
	scanf_s("%d", &d);

	day = DateOf(y, m, d);

	printf("몇 일 앞/뒤의 날짜를 구할까요? : ");
	scanf_s("%d", &n);

	printf("%d일 뒤의 날짜 : ", n);
	printf("%d년 %d월 %d일", After(day, n).y, After(day, n).m, After(day, n).d);
	printf("\n");

	printf("%d일 앞의 날짜 : ", n);
	printf("%d년 %d월 %d일", Before(day, n).y, Before(day, n).m, Before(day, n).d);
	printf("\n");
	return 0;
}




