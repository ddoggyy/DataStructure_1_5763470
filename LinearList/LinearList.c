#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinearList.h"


void initList(listType* list) { 
	list->last = -1;
	list->size = MAX;
}
void addContact(listType* list) {
	elementType newContact;
	printf("이름을 입력하세요: ");
	fgets(newContact.name, sizeof(newContact.name), stdin);
	printf("전화번호를 입력하세요: ");
	fgets(newContact.phone, sizeof(newContact.phone), stdin);
	newContact.name[strcspn(newContact.name, "\n")] = 0;
	newContact.phone[strcspn(newContact.phone, "\n")] = 0;
	list->last++;
	list->array[list->last] = newContact;
	printf("연락처가 추가되었습니다.\n");
}

void deleteContact(listType* list) {
	char name[30];
	printf("삭제할 이름을 입력하세요: ");
	fgets(name, sizeof(name), stdin);
	name[strcspn(name, "\n")] = 0;
	for (int i = 0; i <= list->last; i++) {
		if (strcmp(list->array[i].name, name) == 0) {
			for (int j = i; j < list->last; j++) {
				list->array[j] = list->array[j + 1];
			}
			list->last--;
			printf("삭제되었습니다.\n");
		}
	}
}
void searchContact(listType* list) {
	char name[30];
	int count = 0;
	printf("검색할 이름을 입력하세요: ");
	fgets(name, sizeof(name), stdin);
	name[strcspn(name, "\n")] = 0;
	for (int i = 0; i <= list->last; i++) {
		if (strcmp(list->array[i].name, name) == 0) {
			printf("이름: %s, 전화번호: %s\n", list->array[i].name, list->array[i].phone);
			count = 1;
		}
	}
	if (count == 0) printf("없는 연락처입니다.\n");
	
}
void printAllContacts(listType* list) {
	printf("----- 전체 연락처 -----\n");
	for (int i = 0; i <= list->last; i++) {
		printf("[%d] 이름: %s, 전화번호: %s\n", i + 1, list->array[i].name, list->array[i].phone);
	}
	printf("------------------------\n");
}