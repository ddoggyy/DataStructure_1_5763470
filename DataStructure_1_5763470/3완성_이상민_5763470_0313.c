#include <stdio.h>
#include <string.h>

void toggle(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        // �빮�� -> �ҹ��� ��ȯ
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; // �ƽ�Ű �ڵ� ���̸�ŭ ����
        }
        // �ҹ��� -> �빮�� ��ȯ
        else if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32; // �ƽ�Ű �ڵ� ���̸�ŭ ����
        }
    }
}

int main() {
    char str[100];

    // ���ڿ� �Է� �ޱ�
    printf("���ĺ��� �Է��Ͻÿ� : ");
    fgets(str, sizeof(str), stdin);

    // ��ҹ��� ��ȯ
    toggle(str);

    // ��ȯ�� ���ڿ� ���
    printf("%s\n", str);

    return 0;
}