#include <stdio.h>

int main(void) {
	float num; // ���� num ����
	int tmp;
	printf("�Ǽ��� �Է��ϼ��� : ");
	scanf_s("%f", &num); // num�� �� ����

	tmp = *(unsigned int*)&num; //num�� �ּҸ� unsigned int*�� �ؼ��Ͽ� ����
	printf("�Էµ� ������ 32��Ʈ ǥ�� : \n"); 

	printf("��ȣ : ");
	for (int i = 31; i >= 31; --i) {
		printf("%d ", (tmp >> i) & 1);
	} 
	printf("\n���� : ");
	for (int i = 30; i >= 23; --i) {
		printf("%d ", (tmp >> i) & 1);
	}
	printf("\n���� : ");
	for (int i = 22; i >= 0; --i) {
		printf("%d ", (tmp >> i) & 1);
	} // ����� ���
}

