#include <stdio.h>

// ���� �Լ�
int add();

// ���� �Լ�
int subtract();

// ���� �Լ�
int multiply();

// ������ �Լ�
float divide();

int main() {
    int num1, num2;

    // ����ڷκ��� ���� ���� �Է¹ޱ�
    printf("ù ��° ���� ������ �Է��ϼ���: ");
    scanf_s("%d", &num1);

    printf("�� ��° ���� ������ �Է��ϼ���: ");
    scanf_s("%d", &num2);

    // ��Ģ���� ��� ���
    printf("����: %d\n", add(num1, num2));
    printf("����: %d\n", subtract(num1, num2));
    printf("����: %d\n", multiply(num1, num2));
    printf("������: %.2f\n", divide(num1, num2));

    return 0;
}

int add(int num1, int num2) {
    return num1 + num2;
}

// ���� �Լ�
int subtract(int num1, int num2) {
    return num1 - num2;
}

// ���� �Լ�
int multiply(int num1, int num2) {
    return num1 * num2;
}

// ������ �Լ�
float divide(int num1, int num2) {
    return (float)num1 / num2;
}
