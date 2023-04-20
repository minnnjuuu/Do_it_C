#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//정수를 비교하는 함수(오름차순)
int int_cmp(const int* a, const int* b) {
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;
}

//덧셈 함수
int sum(int a, int b) {
	return a + b;
}

//곱셈 함수
int mul(int a, int b) {
	return a * b;
}

//표 출력 함수
void kuku(int(*calc)(int, int)) {
	int i, j;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) 
			printf("%3d", (*calc)(i, j));
		printf("\n");
	}
}

//구조체 정의
typedef struct {
	char name[10];
	int height;
	int weight;
} Person;


//Person형 구조체의 비교함수
int npcmp(const Person* x, const Person* y) {
	return strcmp(x->name, y->name);
}

//long 형 정수를 비교하는 함수(내림차순)
int long_cmp(const long* a, const long* b) {
	if (*a < *b)
		return 1;
	else if (*a > *b)
		return -1;
	else
		return 0;
}

int main(void) {
	//오름차순 정수를 비교하는 함수
	int i, nx, ky;
	int* x; //배열의 첫번쨰 요소에 대한 포인터
	int* p; //검색한 요소에 대한 포인터
	puts("bsearch 함수를 사용하여 검색");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int)); //요소의 개수가 nx인 int형 배열을 생성
	puts("오름차순으로 입력하세요.");
	printf("x[0] = ");
	scanf_s("%d", &x[0]);
	for (i = 1; i < nx; i++) {
		do {
			printf("x[%d] = ", i);
			scanf_s("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}
	printf("검색값 : ");
	scanf_s("%d", &ky);
	p = bsearch(&ky, x, nx, sizeof(int), (int(*)(const void*, const void*)) int_cmp);
	if (p == NULL)
		puts("검색에 실패했습니다.");
	else
		printf("%d은(는) x[%d]에 있습니다\n", ky, (int)(p - x));
	free(x);

	//함수 포인터
	//덧셈, 곱셈표
	puts("덧셈표");
	kuku(sum);
	puts("곱셈표");
	kuku(mul);

	//구조체 배열에서 검색하기
	Person xx[] = {
		{"김영준",179,79},
		{"박현규",172,63},
		{"이수진",176,52},
		{"최윤미",165,51},
		{"함진아",181,73},
		{"홍연의",172,84},

	};
	int nxx = sizeof(xx) / sizeof(xx[0]); //배열 x의 요소 개수
	int retryy;
	puts("이름으로 검색합니다. ");
	do {
		Person temp, * pp;
		printf("이름 : ");
		scanf_s("%s", temp.name,sizeof(temp.name));
		pp = bsearch(&temp, xx, nxx, sizeof(Person), (int(*)(const void*, const void*)) npcmp);
		if (pp == NULL)
			puts("검색 실패");
		else {
			puts("검색 성공! 아래 요소를 찾았습니다");
			printf("xx[%d]:%s %dcm %dkg\n", (int)(pp - xx),pp->name, pp->height, pp->weight);
		}
		printf("다시 검색할까요?(1) 예/(0) 아니오 : ");
		scanf_s("%d", &retryy);
	} while (retryy == 1);

	//문제6
	//내림차순 정렬된 long형 배열에서의 검색을 bsearch 함수를 이용하여 작성
	int a, num, key;
	long* y;
	long* po;
	puts("bsearch 함수를 사용하여 검색");
	printf("요소 개수 : ");
	scanf_s("%d", &num);
	y = calloc(num, sizeof(long));
	puts("내림차순으로 입력하세요");
	printf("y[0] = ");
	scanf_s("%ld", &y[0]);
	for (a = 1; a < num; a++) {
		do {
			printf("y[%d] = ",a);
			scanf_s("%ld", &y[a]);
		} while (y[a] > y[a - 1]);
	}
	printf("검색값 : ");
	scanf_s("%d", &key);
	po = bsearch(&key, y, num, sizeof(int), (int(*)(const void*, const void*)) long_cmp);
	if (po == NULL)
		puts("검색 실패");
	else
		printf("%d은(는) y[%d]에 있습니다\n",key,(int)(po-y));
	free(y);
	return 0;
}