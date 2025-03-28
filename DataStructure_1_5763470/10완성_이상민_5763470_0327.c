#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* num1 = (int*)malloc(4 * sizeof(int));
    int* num2 = (int*)malloc(4 * sizeof(int));
    int* result = (int*)malloc(4 * sizeof(int));

    printf("첫 번째 2x2 행렬 입력: \n");
    scanf("%d %d", &num1[0], &num1[1]);
    scanf("%d %d", &num1[2], &num1[3]);

	printf("두 번째 2x2 행렬 입력: \n");
	scanf("%d %d", &num2[0], &num2[1]);
	scanf("%d %d", &num2[2], &num2[3]);

	for (int i = 0; i < 4; i++) {
		result[i] = num1[i] + num2[i];
	}
	printf("행렬 덧셈 결과: \n");
	for (int i = 0; i < 4; i += 2) {
		printf("%d %d\n", result[i], result[i+1]);
	}
	free(num1);
	free(num2);
	free(result);

    return 0;
}