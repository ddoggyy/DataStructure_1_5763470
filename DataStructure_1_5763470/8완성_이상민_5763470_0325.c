/*
DECLARE num1[2][2] AS INTEGER
DECLARE num2[2][2] AS INTEGER
DECLARE result[2][2] AS INTEGER = {0}

PRINT "ù ��° 2x2 ��� �Է�: "
READ num1[0][0], num1[0][1]
READ num1[1][0], num1[1][1]

PRINT "�� ��° 2x2 ��� �Է�: "
READ num2[0][0], num2[0][1]
READ num2[1][0], num2[1][1]

FOR i FROM 0 TO 1 DO {
	result[i][0] = num1[i][0] + num2[i][0]
	result[i][1] = num1[i][1] + num2[i][1]
}
FOR i FROM 0 TO 1 DO {
	PRINT result[i][0], result[i][1]
}

PRINT "��� ���� ���: "
FOR i FROM 0 TO 1 DO {
	PRINT result[i][0], result[i][1]
}
*/ 

#include <stdio.h>
int main(void) {
	int num1[2][2];
	int num2[2][2];
	int result[2][2] = { 0 };

	printf("ù ��° 2x2 ��� �Է�: \n");
	scanf_s("%d %d", &num1[0][0], &num1[0][1]);
	scanf_s("%d %d", &num1[1][0], &num1[1][1]);

	printf("�� ��° 2x2 ��� �Է�: \n");
	scanf_s("%d %d", &num2[0][0], &num2[0][1]);
	scanf_s("%d %d", &num2[1][0], &num2[1][1]);

	for (int i = 0; i <= 1; i++) {
		result[i][0] = num1[i][0] + num2[i][0];
		result[i][1] = num1[i][1] + num2[i][1];
	}
	printf("��� ���� ���: \n");
	for (int i = 0; i <= 1; i++) {
		printf("%d ", result[i][0]);
		printf("%d\n", result[i][1]);
	}
	
	return 0;
}