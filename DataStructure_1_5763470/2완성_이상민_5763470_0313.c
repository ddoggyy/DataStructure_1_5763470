#include <stdio.h>

int main(void) {
	float num; // 변수 num 선언
	int tmp;
	printf("실수를 입력하세요 : ");
	scanf_s("%f", &num); // num의 값 받음

	tmp = *(unsigned int*)&num; //num의 주소를 unsigned int*로 해석하여 저장
	printf("입력된 정수의 32비트 표현 : \n"); 

	printf("부호 : ");
	for (int i = 31; i >= 31; --i) {
		printf("%d ", (tmp >> i) & 1);
	} 
	printf("\n지수 : ");
	for (int i = 30; i >= 23; --i) {
		printf("%d ", (tmp >> i) & 1);
	}
	printf("\n가수 : ");
	for (int i = 22; i >= 0; --i) {
		printf("%d ", (tmp >> i) & 1);
	} // 나누어서 출력
}

