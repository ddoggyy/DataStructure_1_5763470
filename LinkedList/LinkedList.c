

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int printList(linkedList_h* L) {
	listNode* lptr = L->head;
	printf("Linked List: ");
	while (lptr->link != (listNode*)NULL) {
		printf("[%d]", lptr->data);
		lptr = lptr->link;
	}
	printf("[%d] \n", lptr->data);
}

int insertFirstNode(linkedList_h* L, elementType item) {
	listNode* newNode; // ��� ����

	newNode = (listNode*)malloc(sizeof(listNode)); // listNode ũ�� ��ŭ �޸� �Ҵ�
	newNode->data = item; // newNode�� ����Ű�� data �ּҿ� item�� �������
	newNode->link = L->head; // newNode�� ����Ű�� link �ּҿ� L�� ����Ű�� head ���� ������� (1) 
	L->head = newNode; // L�� ����Ű�� head ���� newNode�� ������� (2)

	return 0;
}