#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int fibo_rec(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else {
		return fibo_rec(n - 1) + fibo_rec(n - 2);
	}
}

int fibo_itr(int n) {
	int f_n_2 = 0, f_n_1 = 1, f_n;
	for (int i = 2; i <= n; i++) {
		f_n = f_n_1 + f_n_2;
		f_n_2 = f_n_1;
		f_n_1 = f_n;
	}

	if (n == 0) return f_n_2;
	else if (n == 1) return f_n_1;
	else return f_n;
}

int main() {
	int selectMenu, n;
	while (1) {
		printf("�Ǻ���ġ ���� ��� ���� (1: �����, 2: ��ȯ��, 0: ����): ");
		scanf("%d", &selectMenu);
		if (selectMenu == 0) break;
		printf("���� N�� �Է��ϼ��� (�����Ϸ��� 0 �Է�): ");
		scanf("%d", &n);
		if (n == 0) break;
		else if (selectMenu == 1) printf("F(%d) = %d (����� ���)\n", n, fibo_rec(n));
		else if (selectMenu == 2) printf("F(%d) = %d (��ȯ�� ���)\n", n, fibo_itr(n));
		else printf("�߸��� �Է��Դϴ�.");
	}
	printf("���α׷��� ����Ǿ����ϴ�.");
	return 0;
}