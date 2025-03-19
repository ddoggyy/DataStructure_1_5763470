/*
    DECLARE int num1, num2
    PRINT "ù ��° ���� ������ �Է��ϼ���: "
    READ num1

    PRINT "�� ��° ���� ������ �Է��ϼ���: "
    READ num2

    result = add(num1, num2)
    PRINT "����: " + result

    result = subtract(num1, num2)
    PRINT "����: " + result

    result = multiply(num1, num2)
    PRINT "����: " + result

    result = divide(num1, num2)
    PRINT "������: " + result

FUNCTION add(num1, num2)
    RETURN num1 + num2

FUNCTION subtract(num1, num2)
    RETURN num1 - num2

FUNCTION multiply(num1, num2)
    RETURN num1 * num2

FUNCTION divide(num1, num2)
    IF num2 IS NOT 0 THEN
        RETURN num1 / num2
 */

#include <stdio.h>

// ���� �Լ�
int add(int num1, int num2);

// ���� �Լ�
int subtract(int num1, int num2);

// ���� �Լ�
int multiply(int num1, int num2);

// ������ �Լ�
float divide(int num1, int num2);

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
    if (num2 != 0) return (float)num1 / num2;
}
