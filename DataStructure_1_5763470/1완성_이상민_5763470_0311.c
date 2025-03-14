#include <stdio.h>

int main(void) {
	int num; // 정수값을 받기 위한 integer 변수 num 선언
	printf("정수를 입력하세요 : "); 
	scanf_s("%d", &num); // num의 값 받음

	printf("입력된 정수의 32비트 표현 : ");
	for (int i = 31; i >= 0; --i) {
		printf("%d", (num >> i) & 1);
	} // 2진수로 변환하여 한 자리씩 출력
}

