

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int printList(linkedList_h* L) {
	listNode* lptr = L->head;
	printf("Linked List(%d): ", L->follow);
	while (lptr->link != (listNode*)NULL) {
		printf("[%d]", lptr->data);
		lptr = lptr->link;
	}
	printf("[%d] \n", lptr->data);
}

void insertFirstNode(linkedList_h* L, elementType item) {
	listNode* newNode; // ��� ����

	newNode = (listNode*)malloc(sizeof(listNode)); // listNode ũ�� ��ŭ �޸� �Ҵ�
	newNode->data = item; // newNode�� ����Ű�� data �ּҿ� item�� �������
	newNode->link = L->head; // newNode�� ����Ű�� link �ּҿ� L�� ����Ű�� head ���� ������� (1) 
	L->head = newNode; // L�� ����Ű�� head ���� newNode�� ������� (2)

	return 0;
}

linkedList_h* createLinkedList(void) { // linkedList_h ����ü�� �����͸� ��ȯ
	linkedList_h* lptr; // linkedList_h ����ü ������
	lptr = (linkedList_h*)malloc(sizeof(linkedList_h)); 
	lptr->head = (linkedList_h*)NULL; 
	lptr->follow = 0; // ��� �̵� Ƚ�� ���� ������ �ʱ�ȭ
	return lptr;
}

void destroyLinkedList(linkedList_h* L) {
	listNode* p; // listNode ����ü ������

	while (L->head != NULL) { // 
		p = L->head; 
		L->head = L->head->link; // L->head = p->link; ����� NULL�϶����� ����� ���� ����Ʈ�� ������ ��, ù ��带 ������
		free(p); 
	}
	free(L); // ����Ʈ ��ü
}

void insertLastNode(linkedList_h* L, elementType item) {
	listNode* temp, * newNode; // temp�� ����Ʈ ��ȸ��, newNode�� �� ��带 �ǹ�
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item; 
	newNode->link = (listNode*)NULL; // �� ����� link�� ������ ����̹Ƿ� NULL

	temp = L->head;
	if (temp == (listNode*)NULL) { // ����Ʈ�� ��������� �� ��带 ����Ʈ�� ����� ����
		L->head = newNode;
		return;
	}
	while (temp->link != (listNode*)NULL) { // temp�� ���� ��尡 NULL�϶����� (����Ʈ�� ������ ������) 
		temp = temp->link; // temp�� ���� ���� �̵�
		L->follow++; // ��� �̵� Ƚ�� 
	}
	temp->link = newNode; // temp�� ���� ��带 newNode�� ����

	return;
}

void insertMiddleNode(linkedList_h* L, listNode* pre, elementType item) {

	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item; // �� ����

	if (L->head == (listNode*)NULL) { // ����Ʈ�� ����ִٸ�
		newNode->link = (listNode*)NULL; // �� ��带 ����Ʈ�� ����� ����
		L->head = newNode;
	}
	else if (pre == (listNode*)NULL) { // pre�� ����ִٸ� (���� ����� ���� ��尡 ����ִٸ�)
		newNode->link = L->head; // �� ����� ���� ��带 ����� ����
		L->head = newNode; // ����� �� ���� ���� (�� �տ� ����)
	}
	else { 
		newNode->link = pre->link; // �� ����� ���� ���� ���� ����� ���� ��带 ����Ŵ
		pre->link = newNode; // ������ ��ġ�� �� ��带 ����
	}
}

void insertNthNode(linkedList_h* L, int loc, elementType item) { // loc�� ������ ���� ��ġ

	if (L->head == (listNode*)NULL) { // ����Ʈ�� ����ִٸ�
		if (loc == 0) insertFirstNode(L, item);  // ��ǥ ��ġ�� 0�̸� �� �տ� ��� ����
		else fprintf("[insertNthNode: list empty and lo not 0\n", stderr); // 0�� �ƴ϶�� ���� �޽��� ��� �� ����
		return;
	}
	else { // ����Ʈ�� ������� �ʴٸ�
		if(loc == 0) insertFirstNode(L, item); // ��ǥ ��ġ�� 0�̸� �� �տ� ��� ����
		else {
			int i = loc; listNode* pre = L->head;  
			while (i > 1 && pre->link != (listNode*)NULL) { // ��ġ�� �� ���� �ƴϰ� pre->link�� NULL�� �ƴҶ����� �ݺ�
				i--; // ��ǥ ��ġ�� 1�� �ݴ�� �̵� (�̵��Ͽ����� ��ǥ ��ġ������ �Ÿ��� ����)
				pre = pre->link; // pre�� ����Ű�� ��带 ���� ���� �����ϴ� ��, �� pre�� ���� ���� �̵���Ŵ
			}
				insertMiddleNode(L, pre, item); // pre��, �� loc-1 ������(loc�� ��ġ��) �� ��带 ����
		}
		return;
	}
}

	int compare_item(elementType first, elementType second) {
		return (first - second);
	}

	void ordered_insertNode(linkedList_h* L, elementType item) { 
		listNode* pre;

		if (L->head == (listNode*)NULL) insertFirstNode(L, item); // ����Ʈ�� ��������� insertFirstNode ȣ��
		else { // ������� �ʴٸ�
			if (compare_item(L->head->data, item) > 0) // ����� �� - item > 0�̸�
				insertFirstNode(L, item); // �� �տ� ���� (��, ���� ���� �� ������ ��)
			else { // ����� �� - item =< 0 �̸�
				pre = L->head; // ����Ʈ�� �� �� ���� pre�� �ʱ�ȭ
				while (pre->link != (listNode*)NULL) { // pre�� ���� ��尡 NULL�� �ƴҶ����� �ݺ�
					if (compare_item(pre->data, item) < 0 && compare_item(pre->link->data, item) > 0) {
						break;
					}
					// pre�� ���� item���� �۰� �� ���� ����� ���� item���� ũ�ٸ�, break 
					pre = pre->link; // pre�� ���� ���� �̵�
					L->follow++;
				}
				insertMiddleNode(L, pre, item);
			}
		}
	}

void deleteNode(linkedList_h* L, listNode* p) { // p�� �����Ϸ��� ��带 ��Ÿ���� ������
	listNode* pre;

	if (L->head == (listNode*)NULL) return; // ����Ʈ�� ����ִٸ� ������ ��尡 �����Ƿ� ����
	/*if (L->head->link == (listNode*)NULL) { // ����Ʈ�� ���� ��尡 ����ִٸ�
		free(L->head);
		L->head = (listNode*)NULL;
		return;
	}*/
	else if (p == (listNode*)NULL) return; // ���� ��� ��尡 NULL�̸� �����Ƿ� ����
	else {
		pre = L->head; // pre�� ����Ʈ�� ����� �ʱ�ȭ
		while (pre->link != p && p->link != (listNode*)NULL) pre = pre->link;
		// pre�� ���� ��尡 ���� ��尡 �ƴϰ�, ���� ����� ���� ��尡 NULL�� �ƴҶ����� pre�� ���� ���� �̵�
		if (pre->link == p) { //  pre�� ���� ��尡 ���� �����
			pre->link = p->link; // pre�� ���� ���� ���� ����� ���� ���� �̵�
			free(p); 
			L->follow++;
		}
		else fprintf(stderr, "delete item not in the list\n"); // p�� ����Ʈ ���� ������ ���� �޽��� ���
	}
}