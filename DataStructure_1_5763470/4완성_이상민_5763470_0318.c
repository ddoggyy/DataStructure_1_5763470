/*
 DECLARE int count, n
	PRINT "정수 n을 입력하세요: "
	READ n

	PRINT "n 이하의 소수: "

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
	printf("정수 n을 입력하세요: ");
	scanf_s("%d", &n);

	printf("%d 이하의 소수: ", n);
	for (int i = 2; i <= n; i++) {
		count = 0; 
		for (int j = 2; j < i; j++) {
			if (i % j == 0) count++; // i의 나누어 떨어지는 횟수를 계산
		}
		if (count == 0) printf("%d ", i); // 나누어 떨어지는 횟수가 없는 경우 출력
	}
	return 0;
}