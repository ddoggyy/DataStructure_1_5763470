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
	printf("�̸��� �Է��ϼ���: ");
	fgets(newContact.name, sizeof(newContact.name), stdin);
	printf("��ȭ��ȣ�� �Է��ϼ���: ");
	fgets(newContact.phone, sizeof(newContact.phone), stdin);
	newContact.name[strcspn(newContact.name, "\n")] = 0;
	newContact.phone[strcspn(newContact.phone, "\n")] = 0;
	list->last++;
	list->array[list->last] = newContact;
	printf("����ó�� �߰��Ǿ����ϴ�.\n");
}

void deleteContact(listType* list) {
	char name[30];
	printf("������ �̸��� �Է��ϼ���: ");
	fgets(name, sizeof(name), stdin);
	name[strcspn(name, "\n")] = 0;
	for (int i = 0; i <= list->last; i++) {
		if (strcmp(list->array[i].name, name) == 0) {
			for (int j = i; j < list->last; j++) {
				list->array[j] = list->array[j + 1];
			}
			list->last--;
			printf("�����Ǿ����ϴ�.\n");
		}
	}
}
void searchContact(listType* list) {
	char name[30];
	int count = 0;
	printf("�˻��� �̸��� �Է��ϼ���: ");
	fgets(name, sizeof(name), stdin);
	name[strcspn(name, "\n")] = 0;
	for (int i = 0; i <= list->last; i++) {
		if (strcmp(list->array[i].name, name) == 0) {
			printf("�̸�: %s, ��ȭ��ȣ: %s\n", list->array[i].name, list->array[i].phone);
			count = 1;
		}
	}
	if (count == 0) printf("���� ����ó�Դϴ�.\n");
	
}
void printAllContacts(listType* list) {
	printf("----- ��ü ����ó -----\n");
	for (int i = 0; i <= list->last; i++) {
		printf("[%d] �̸�: %s, ��ȭ��ȣ: %s\n", i + 1, list->array[i].name, list->array[i].phone);
	}
	printf("------------------------\n");
}