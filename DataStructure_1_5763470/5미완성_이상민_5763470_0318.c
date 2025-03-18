/*
	문자형 sign 선언
    정수형 a, b 선언
    실수형 result 선언

    a 입력 받기
    sign 입력 받기
    b 입력 받기

    sign이
        +일 경우:
            result = a + b
            result를 정수로 출력
            종료

        -일 경우:
            result = a - b
            result를 정수로 출력
            종료

        *일 경우:
            result = a * b
            result를 정수로 출력
            종료

        /일 경우:
            만약 b가 0이 아니라면:
                result = a / b
*/

#include <stdio.h>

int main(void) {
	char sign = 0;	
	int a, b = 0;
	double result = 0;

	scanf_s("%d", &a);
	scanf_s(" %c", &sign, 1);
	scanf_s("%d", &b);
	switch (sign) {
	case '+': 
		result = a + b;
		printf("%d", (int)result);
		break;
	case '-': 
		result = a - b;
		printf("%d", (int)result);
		break;
	case '*': 
		result = a * b;
		printf("%d", (int)result);
		break;
	case '/':
		if (b != 0) {
			result = (double)a / b;
			printf("%.2f", result);
		}
		break;
	}
	return 0;
}