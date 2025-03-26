/*
FUNCTION Sort(int* a, int* b){
	DECLARE tmp AS INTEGER
	tmp = *a
	*a = *b
	*b = tmp
}

DECLARE i, j, numCount AS INTEGER
DECLARE num AS ARRAY OF INTEGER

PRINT "정수의 개수를 입력하세요: "
READ numCount

ALLOCATE num[numCount]
PRINT numCount "개의 정수를 입력하세요: "
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

PRINT "오름차순으로 정렬된 정수들: "
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

	printf("정수의 개수를 입력하세요: ");
	scanf_s("%d", &numCount);

	num = (int*)malloc(numCount * sizeof(int));

	printf("%d개의 정수를 입력하세요: \n", numCount);
	for (i = 0; i < numCount; i++) {
		scanf_s("%d", &num[i]);
	}
	for (i = 0; i < numCount; i++)		//선택정렬 사용 
	{
		for (j = i + 1; j < numCount; j++)
		{
			if (num[i] > num[j]) Sort(&num[i], &num[j]);
		}
	}

	printf("오름차순으로 정렬된 정수들: \n");
	for (i = 0; i < numCount; i++) {
		printf("%d ", num[i]);
	}
	free(num);

	return 0;
}