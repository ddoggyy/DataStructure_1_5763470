/*
 변수 count, n 선언
	"정수 n을 입력하세요: " 메시지 출력
	사용자로부터 n 값을 입력 받음

	"n 이하의 소수: " 출력

	i를 2부터 n까지 반복
		count를 0으로 초기화
		j를 2부터 i까지 반복
			만약 i가 j로 나누어 떨어지면
				count를 1 증가시킴 (나누어떨어지는 횟수)
		만약 count가 1이라면 i는 소수이므로
			i를 출력
*/

#include <stdio.h>

int main(void) {
	int count, n;
	printf("정수 n을 입력하세요: ");
	scanf_s("%d", &n);

	printf("%d 이하의 소수: ", n);
	for (int i = 2; i <= n; i++) {
		count = 0; 
		for (int j = 2; j <= i; j++) {
			if (i % j == 0) count++; // i의 나누어 떨어지는 횟수를 계산
		}
		if (count == 1) printf("%d ", i); // 나누어 떨어지는 횟수가 1번 뿐인 경우 출력
	}
	return 0;
}