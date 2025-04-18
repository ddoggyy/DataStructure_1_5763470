#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinearList.h"

int main(void) {
    int choice;
    listType* phoneList = (listType*)malloc(sizeof(listType));
    initList(phoneList); // 리스트 초기화

    while (1) {
        choice = 0;
        printf("\n===== 전화번호부 메뉴 =====\n");
        printf("1. 연락처 추가\n");
        printf("2. 연락처 삭제\n");
        printf("3. 연락처 검색\n");
        printf("4. 전체 연락처 출력\n");
        printf("0. 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // 버퍼 정리

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
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못 입력하셨습니다.\n");
            break;
        }
    }
}