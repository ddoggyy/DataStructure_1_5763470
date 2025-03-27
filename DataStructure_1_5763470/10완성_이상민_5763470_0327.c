#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* num1 = (int*)malloc(4 * sizeof(int));
    int* num2 = (int*)malloc(4 * sizeof(int));
    int* result = (int*)malloc(4 * sizeof(int));

    printf("첫 번째 2x2 행렬 입력: \n");
    scanf_s("%d %d", num1, num1 + 1);
    scanf_s("%d %d", num1 + 2, num1 + 3);

	printf("두 번째 2x2 행렬 입력: \n");
	scanf_s("%d %d", num2, num2 + 1);
	scanf_s("%d %d", num2 + 2, num2 + 3);

	for (int i = 0; i <= 3; i++) {
		*(result + i) = *(num1 + i) + *(num2 + i);
	}
	printf("행렬 덧셈 결과: \n");
	for (int i = 0; i <= 3; i = i + 2) {
		printf("%d ", *(result + i));
		printf("%d\n", *(result + (i + 1)));
	}

    return 0;
}