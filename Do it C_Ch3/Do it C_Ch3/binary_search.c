#include <stdio.h>
#include <stdlib.h>

//����� ������ n�� �迭 a���� key�� ��ġ�ϴ� ��Ҹ� �����˻�
int bin_search(const int a[], int n, int key) {
	int pl = 0; //�˻����� �� ���� �ε���
	int pr = n - 1; //�˻����� �� ���� �ε���
	int pc; //�˻����� �� ����� �ε���
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

//����� ������ n�� �迭 a���� key�� ��ġ�ϴ� ��� ����� �ε����� �迭idx�� ������� �����ϰ�,
//��ġ�� ����� ������ ��ȯ
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

//���� �˻��� ������ �ڼ��� ����ϴ� ���α׷�
int bin_search2(const int a[], int n, int key) {
	int pl = 0; //�˻����� �� �� �ε���
	int pr = n - 1; //�˻����� �� �� �ε���
	int pc; //�˻����� �� ����� �ε���
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
	//���� �˻�
	int i, nx, key, index; //nx->��Ұ���,key->�˻���,index->ã�� ���� �ε��� ��ȣ
	int* x; //x->�迭
	puts("���� �˻�");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	puts("������������ �Է��ϼ���");
	x = calloc(nx, sizeof(int));
	printf("x[0] = ");
	scanf_s("%d", &x[0]);
	for (i = 1; i < nx; i++) {
		do {		
		printf("x[%d] = ", i);
		scanf_s("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}
	printf("�˻��� : ");
	scanf_s("%d", &key);
	index = bin_search(x, nx, key);
	if (index == -1)
		puts("�˻� ����");
	else
		printf("%d��(��) x[%d]�� �ֽ��ϴ�\n", key, index);
	free(x);

	//���� 3
	//�迭���� �Է¹��� ���� ��ġ�ϴ� �ε��� ��ȣ ��� ���
	int a, n, ky; //n->��� ����, ky->ã�� ��
	int* y; //�Է¹��� �迭
	int* idx; //key�� ��ġ�ϴ� �迭
	printf("��� ���� : ");
	scanf_s("%d", &n);
	y = calloc(n, sizeof(int));
	idx = calloc(n, sizeof(int));
	for (a = 0; a < n; a++) {
		printf("y[%d] = ",a);
		scanf_s("%d", &y[a]);
	}
	printf("�˻��� : ");
	scanf_s("%d", &ky);
	printf("%d\n", search_idx(y, n, ky, idx));
	free(y);
	free(idx);

	//���� 4
	//���� Ž�� ���� �ڼ��� ���
	int m, num, k, indexx;
	int* z;
	printf("��� ���� : ");
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
	printf("�˻��� : ");
	scanf_s("%d", &k);
	indexx = bin_search2(z, num, k);
	if (indexx == -1)
		puts("�˻� ����");
	else
		printf("%d�� z[%d]�� �ֽ��ϴ�.\n", k, indexx);
	free(z);

	return 0;
}