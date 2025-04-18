#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinearList.h"

int main(void) {
    int choice;
    listType* phoneList = (listType*)malloc(sizeof(listType));
    initList(phoneList); // ����Ʈ �ʱ�ȭ

    while (1) {
        choice = 0;
        printf("\n===== ��ȭ��ȣ�� �޴� =====\n");
        printf("1. ����ó �߰�\n");
        printf("2. ����ó ����\n");
        printf("3. ����ó �˻�\n");
        printf("4. ��ü ����ó ���\n");
        printf("0. ����\n");
        printf("�޴��� �����ϼ���: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // ���� ����

        switch (choice) {
        case 1:
            addContact(phoneList);
            break;
        case 2:
            deleteContact(phoneList);
            break;
        case 3:
            searchContact(phoneList);
            break;
        case 4:
            printAllContacts(phoneList);
            break;
        case 0:
            free(phoneList);
            printf("���α׷��� �����մϴ�.\n");
            return 0;
        default:
            printf("�߸� �Է��ϼ̽��ϴ�.\n");
            break;
        }
    }
}