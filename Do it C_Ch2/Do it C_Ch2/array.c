//책 ch2 67p 까지
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define a 5
#define swap(type,x,y) do{type l = x;x = y;y = l;} while(0) //type 형 x,y 값을 교환

//요소 개수가 i인 배열 h의 요소의 최댓값 구하는 함수
int maxof(const int h[], int i) {
	int max = h[0];
	for (int j = 1; j < i; j++) {
		if (h[j] > max) {
			max = h[j];
		}
	}
	return max;
}

//요소 개수가 m인 배열 n의 요소를 역순으로 정렬
void array_reverse(int n[], int m) {
	for (int o = 0; o < m / 2; o++) {
		swap(int, n[o], n[m - o - 1]);
	}
}

int main(void) {
	//정수 5개 입력받아 출력
	int b;
	int c[5];
	for (b = 0; b < a; b++) {
		printf("c[%d] : ", b);
		scanf_s("%d", &c[b]);
	}
	puts("각 요소의 값");
	for (b = 0; b < a; b++) {
		printf("c[%d] = %d\n", b, c[b]);
	}

	//int형 객체를 동적으로 생성하고 해제-단일 객체
	int* d;
	d = calloc(1, sizeof(int));
	if (d == NULL) {
		puts("메모리 할당 실패");
	}
	else {
		*d = 57;
		printf("*d = %d\n", *d);
		free(d);
	}

	//int 형 객체를 동적으로 생성하고 해제-배열 객체
	int e;
	int* f; //배열 포인터
	int g;  //배열의 요소 개수
	printf("요소 개수 : ");
	scanf_s("%d", &g);
	f = calloc(g, sizeof(int));
	if (f == NULL) {
		printf("메모리 확보 실패");
	}
	else {
		printf("%d개의 정수를 입력하세요\n", g);
		for (e = 0; e < g; e++) {
			printf("f[%d] = ", e);
			scanf_s("%d", &f[e]);
		}
		printf("각 요소의 값은 아래와 같습니다.\n");
		for (e = 0; e < g; e++) {
			printf("f[%d] = %d\n", e, f[e]);
		}
		free(f);
	}

	//직접 입력받은 배열 요소의 최댓값 구하기
	int* height; //배열의 첫번째 요소의 포인터
	int number; //인원 = 배열 height의 요소 개수
	printf("사람 수 : ");
	scanf_s("%d", &number);
	height = calloc(number, sizeof(int));
	if (height == NULL) {
		printf("메모리 확보 실패");
	}
	printf("%d 명의 키를 입력하세요 \n", number);
	for (int h = 0; h < number; h++) {
		printf("height[%d] : ", h);
		scanf_s("%d", &height[h]);
	}
	printf("최댓값은 %d입니다.\n", maxof(height, number));
	free(height);

	//난수 사용해 배열의 요솟값 설정하기
	int* height_2;
	int number_2;
	printf("사람 수 : ");
	scanf_s("%d", &number_2);
	height_2 = calloc(number_2, sizeof(int));
	srand(time(NULL));
	for (int k = 0; k < number_2; k++) {
		height_2[k] = 100 + rand() % 90;
		printf("height_2[%d} = %d\n", k, height_2[k]);
	}
	printf("최댓값은 %d입니다\n", maxof(height_2, number_2));
	free(height_2);

	//배열 요소 역순으로 정렬
	int* p; //배열 첫 번째 요소의 포인터
	int q;  //배열 p의 요소 개수
	printf("요소 개수 : ");
	scanf_s("%d", &q);
	p = calloc(q, sizeof(int));
	printf("%d개의 정수를 입력하세요\n", q);
	for (int i = 0; i < q; i++) {
		printf("p[%d] : ", i);
		scanf_s("%d", &p[i]);
	}
	array_reverse(p, q);
	printf("배열의 요소를 역순으로 정렬했습니다\n");
	for (int r = 0; r < q; r++) {
		printf("p[%d] = %d\n", r, p[r]);
	}
	free(p);
	return 0;
}