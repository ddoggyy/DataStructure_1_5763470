/*
 DECLARE int count, n
	PRINT "���� n�� �Է��ϼ���: "
	READ n

	PRINT "n ������ �Ҽ�: "

	FOR i FROM 2 to n DO {
		count = 0 
		FOR j FROM 2 TO i-1 DO {
			IF (i % j == 0) THEN count = count + 1
		}
		IF (count == 0) THEN PRINT i
*/

#include <stdio.h>

int main(void) {
	int count, n;
	printf("���� n�� �Է��ϼ���: ");
	scanf_s("%d", &n);

	printf("%d ������ �Ҽ�: ", n);
	for (int i = 2; i <= n; i++) {
		count = 0; 
		for (int j = 2; j < i; j++) {
			if (i % j == 0) count++; // i�� ������ �������� Ƚ���� ���
		}
		if (count == 0) printf("%d ", i); // ������ �������� Ƚ���� ���� ��� ���
	}
	return 0;
}