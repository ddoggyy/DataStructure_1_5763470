#include <stdio.h>

int main(void) {
	int num; // �������� �ޱ� ���� integer ���� num ����
	printf("������ �Է��ϼ��� : "); 
	scanf_s("%d", &num); // num�� �� ����

	printf("�Էµ� ������ 32��Ʈ ǥ�� : ");
	for (int i = 31; i >= 0; --i) {
		printf("%d", (num >> i) & 1);
	} // 2������ ��ȯ�Ͽ� �� �ڸ��� ���
}

