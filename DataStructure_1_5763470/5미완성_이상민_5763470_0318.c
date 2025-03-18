/*
	������ sign ����
    ������ a, b ����
    �Ǽ��� result ����

    a �Է� �ޱ�
    sign �Է� �ޱ�
    b �Է� �ޱ�

    sign��
        +�� ���:
            result = a + b
            result�� ������ ���
            ����

        -�� ���:
            result = a - b
            result�� ������ ���
            ����

        *�� ���:
            result = a * b
            result�� ������ ���
            ����

        /�� ���:
            ���� b�� 0�� �ƴ϶��:
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