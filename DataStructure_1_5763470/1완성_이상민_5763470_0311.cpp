#include <stdio.h>

int main(void) {
	int num;
	printf("������ �Է��ϼ��� : ");
	scanf("%d", &num);

	printf("�Էµ� ������ 32��Ʈ ǥ�� : ");
	for (int i = 31; i >= 0; --i) {
		printf("%d", (num >> i) & 1);
	}
}

