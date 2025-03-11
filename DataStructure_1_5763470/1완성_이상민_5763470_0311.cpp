#include <stdio.h>

int main(void) {
	int num;
	printf("정수를 입력하세요 : ");
	scanf("%d", &num);

	printf("입력된 정수의 32비트 표현 : ");
	for (int i = 31; i >= 0; --i) {
		printf("%d", (num >> i) & 1);
	}
}

