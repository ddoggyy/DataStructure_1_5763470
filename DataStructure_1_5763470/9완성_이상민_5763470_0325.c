/*
FUNCTION Sort(int* a, int* b){
	DECLARE tmp AS INTEGER
	tmp = *a
	*a = *b
	*b = tmp
}

DECLARE i, j, numCount AS INTEGER
DECLARE num AS ARRAY OF INTEGER

PRINT "������ ������ �Է��ϼ���: "
READ numCount

ALLOCATE num[numCount]
PRINT numCount "���� ������ �Է��ϼ���: "
FOR i FROM 0 TO numCount - 1 DO
	READ num[i]
END FOR

FOR i FROM 0 TO numCount - 1 DO
	FOR j FROM i + 1 TO numCount - 1 DO
		IF num[i] > num[j] THEN
			CALL Sort WITH num[i], num[j]
		END IF
	END FOR
END FOR

PRINT "������������ ���ĵ� ������: "
FOR i FROM 0 TO numCount - 1 DO
	PRINT num[i], " "
END FOR

FREE num
*/
#include <stdio.h>
#include <stdlib.h>

void Sort(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void) {
	int i, j;
	int numCount;
	int* num;

	printf("������ ������ �Է��ϼ���: ");
	scanf_s("%d", &numCount);

	num = (int*)malloc(numCount * sizeof(int));

	printf("%d���� ������ �Է��ϼ���: \n", numCount);
	for (i = 0; i < numCount; i++) {
		scanf_s("%d", &num[i]);
	}
	for (i = 0; i < numCount; i++)		//�������� ��� 
	{
		for (j = i + 1; j < numCount; j++)
		{
			if (num[i] > num[j]) Sort(&num[i], &num[j]);
		}
	}

	printf("������������ ���ĵ� ������: \n");
	for (i = 0; i < numCount; i++) {
		printf("%d ", num[i]);
	}
	free(num);

	return 0;
}