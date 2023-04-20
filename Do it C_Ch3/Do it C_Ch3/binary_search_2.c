#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//������ ���ϴ� �Լ�(��������)
int int_cmp(const int* a, const int* b) {
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;
}

//���� �Լ�
int sum(int a, int b) {
	return a + b;
}

//���� �Լ�
int mul(int a, int b) {
	return a * b;
}

//ǥ ��� �Լ�
void kuku(int(*calc)(int, int)) {
	int i, j;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) 
			printf("%3d", (*calc)(i, j));
		printf("\n");
	}
}

//����ü ����
typedef struct {
	char name[10];
	int height;
	int weight;
} Person;


//Person�� ����ü�� ���Լ�
int npcmp(const Person* x, const Person* y) {
	return strcmp(x->name, y->name);
}

//long �� ������ ���ϴ� �Լ�(��������)
int long_cmp(const long* a, const long* b) {
	if (*a < *b)
		return 1;
	else if (*a > *b)
		return -1;
	else
		return 0;
}

int main(void) {
	//�������� ������ ���ϴ� �Լ�
	int i, nx, ky;
	int* x; //�迭�� ù���� ��ҿ� ���� ������
	int* p; //�˻��� ��ҿ� ���� ������
	puts("bsearch �Լ��� ����Ͽ� �˻�");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int)); //����� ������ nx�� int�� �迭�� ����
	puts("������������ �Է��ϼ���.");
	printf("x[0] = ");
	scanf_s("%d", &x[0]);
	for (i = 1; i < nx; i++) {
		do {
			printf("x[%d] = ", i);
			scanf_s("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}
	printf("�˻��� : ");
	scanf_s("%d", &ky);
	p = bsearch(&ky, x, nx, sizeof(int), (int(*)(const void*, const void*)) int_cmp);
	if (p == NULL)
		puts("�˻��� �����߽��ϴ�.");
	else
		printf("%d��(��) x[%d]�� �ֽ��ϴ�\n", ky, (int)(p - x));
	free(x);

	//�Լ� ������
	//����, ����ǥ
	puts("����ǥ");
	kuku(sum);
	puts("����ǥ");
	kuku(mul);

	//����ü �迭���� �˻��ϱ�
	Person xx[] = {
		{"�迵��",179,79},
		{"������",172,63},
		{"�̼���",176,52},
		{"������",165,51},
		{"������",181,73},
		{"ȫ����",172,84},

	};
	int nxx = sizeof(xx) / sizeof(xx[0]); //�迭 x�� ��� ����
	int retryy;
	puts("�̸����� �˻��մϴ�. ");
	do {
		Person temp, * pp;
		printf("�̸� : ");
		scanf_s("%s", temp.name,sizeof(temp.name));
		pp = bsearch(&temp, xx, nxx, sizeof(Person), (int(*)(const void*, const void*)) npcmp);
		if (pp == NULL)
			puts("�˻� ����");
		else {
			puts("�˻� ����! �Ʒ� ��Ҹ� ã�ҽ��ϴ�");
			printf("xx[%d]:%s %dcm %dkg\n", (int)(pp - xx),pp->name, pp->height, pp->weight);
		}
		printf("�ٽ� �˻��ұ��?(1) ��/(0) �ƴϿ� : ");
		scanf_s("%d", &retryy);
	} while (retryy == 1);

	//����6
	//�������� ���ĵ� long�� �迭������ �˻��� bsearch �Լ��� �̿��Ͽ� �ۼ�
	int a, num, key;
	long* y;
	long* po;
	puts("bsearch �Լ��� ����Ͽ� �˻�");
	printf("��� ���� : ");
	scanf_s("%d", &num);
	y = calloc(num, sizeof(long));
	puts("������������ �Է��ϼ���");
	printf("y[0] = ");
	scanf_s("%ld", &y[0]);
	for (a = 1; a < num; a++) {
		do {
			printf("y[%d] = ",a);
			scanf_s("%ld", &y[a]);
		} while (y[a] > y[a - 1]);
	}
	printf("�˻��� : ");
	scanf_s("%d", &key);
	po = bsearch(&key, y, num, sizeof(int), (int(*)(const void*, const void*)) long_cmp);
	if (po == NULL)
		puts("�˻� ����");
	else
		printf("%d��(��) y[%d]�� �ֽ��ϴ�\n",key,(int)(po-y));
	free(y);
	return 0;
}