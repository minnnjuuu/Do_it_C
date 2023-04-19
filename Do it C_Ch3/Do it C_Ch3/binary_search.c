#include <stdio.h>
#include <stdlib.h>

//요소의 개수가 n인 배열 a에서 key와 일치하는 요소를 이진검색
int bin_search(const int a[], int n, int key) {
	int pl = 0; //검색범위 맨 앞의 인덱스
	int pr = n - 1; //검색범위 맨 뒤의 인덱스
	int pc; //검색범위 한 가운데의 인덱스
	do {
		pc = (pl + pr) / 2;
		if (a[pc] == key)
			return pc;
		else if (a[pc] < key)
			pl = pc + 1;
		else
			pr = pc - 1;
	} while (pl <= pr);
	return -1;
}

//요소의 개수가 n인 배열 a에서 key와 일치하는 모든 요소의 인덱스를 배열idx에 순서대로 저장하고,
//일치한 요소의 개수를 반환
int search_idx(const int a[], int n, int key, int idx[]) {
	int i;
	int cnt = 0;
	for (i = 0; i < n; i++) {
		if (a[i] == key) {
			idx[cnt++] = i;
		}
	}
	return cnt;
}

//이진 검색의 과정을 자세히 출력하는 프로그램
int bin_search2(const int a[], int n, int key) {
	int pl = 0; //검색범위 맨 앞 인덱스
	int pr = n - 1; //검색범위 맨 뒤 인덱스
	int pc; //검색범위 한 가운데의 인덱스
	printf("  | ");
	for (int i = 0; i < n; i++) {
		printf("%d ", i);
	}
	printf("\n");
	printf("---+--------------------------\n");
	do {
		pc = (pl + pr) / 2;
		printf("  |");
		for (int x = 0; x < pl; x++)
			printf("  ");
		printf(" <-");
		for (int x = 1; x < pc - pl; x++)
			printf("  ");
		printf("+ ");
		for (int x = 1; x < pc - pl; x++)
			printf("  ");
		printf(" ->\n");
		printf(" %d|", pc);
		for (int x = 0; x < n; x++) {
			printf(" %d", a[x]);
		}
		printf("\n");
		printf("  |\n");
		if (a[pc] == key)
			return pc;
		else if (a[pc] < key)
			pl = pc + 1;
		else
			pr = pc - 1;
	} while (pl <= pr);
	return -1;
}
int main(void) {
	//이진 검색
	int i, nx, key, index; //nx->요소개수,key->검색값,index->찾을 값의 인덱스 번호
	int* x; //x->배열
	puts("이진 검색");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	puts("오름차순으로 입력하세요");
	x = calloc(nx, sizeof(int));
	printf("x[0] = ");
	scanf_s("%d", &x[0]);
	for (i = 1; i < nx; i++) {
		do {		
		printf("x[%d] = ", i);
		scanf_s("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}
	printf("검색값 : ");
	scanf_s("%d", &key);
	index = bin_search(x, nx, key);
	if (index == -1)
		puts("검색 실패");
	else
		printf("%d는(은) x[%d]에 있습니다\n", key, index);
	free(x);

	//문제 3
	//배열에서 입력받은 값과 일치하는 인덱스 번호 모두 출력
	int a, n, ky; //n->요소 개수, ky->찾을 값
	int* y; //입력받을 배열
	int* idx; //key와 일치하는 배열
	printf("요소 개수 : ");
	scanf_s("%d", &n);
	y = calloc(n, sizeof(int));
	idx = calloc(n, sizeof(int));
	for (a = 0; a < n; a++) {
		printf("y[%d] = ",a);
		scanf_s("%d", &y[a]);
	}
	printf("검색값 : ");
	scanf_s("%d", &ky);
	printf("%d\n", search_idx(y, n, ky, idx));
	free(y);
	free(idx);

	//문제 4
	//이진 탐색 과정 자세히 출력
	int m, num, k, indexx;
	int* z;
	printf("요소 개수 : ");
	scanf_s("%d", &num);
	z = calloc(num, sizeof(int));
	printf("z[0] = ");
	scanf_s("%d", &z[0]);
	for (m = 1; m < num; m++) {
		do {
			printf("z[%d] = ", m);
			scanf_s("%d", &z[m]);
		} while (z[m] < z[m - 1]);
	}
	printf("검색값 : ");
	scanf_s("%d", &k);
	indexx = bin_search2(z, num, k);
	if (indexx == -1)
		puts("검색 실패");
	else
		printf("%d는 z[%d]에 있습니다.\n", k, indexx);
	free(z);

	return 0;
}