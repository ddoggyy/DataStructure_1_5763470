

#include <stdio.h>
#include <stdlib.h>

#include "Linked List.h"

linkedList_h* createLinkedList(void) {
	linkedList_h* lptr;

	lptr = (linkedList_h*)malloc(sizeof(linkedList_h));
	lptr->head = (listNode*)NULL;
	lptr->follow = 0;
	return lptr;
}

linkedList_h* createCLinkedList(void) {
	return createLinkedList();
}

void destroyLinkedList(linkedList_h* L) {
	listNode* p;

	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;  // L->head = p->link;
		free(p);
	}
	free(L);
}


void destroyCLinkedList(linkedList_h* L) {

	/*
	while (L->head != L->head->link) {
		p = L->head;
		L->head = L->head->link;  // L->head = p->link;
		free(p);
	}
	free(L->head);
	free(L); 빈 리스트일 경우 오류 발생 가능 및 double free 발생
	*/ 
	
	if (L == NULL || L->head == NULL) { // NULL 인지 먼저 검사
		free(L);
		return;
	}

	listNode* p = L->head;
	listNode* temp;

	// 마지막 노드가 자기 자신을 가리키는 경우 (노드 1개)
	if (p->link == p) {
		free(p);
	}
	else {
		do {
			temp = p->link;
			free(p);
			p = temp;
		} while (p != L->head);
	}

	free(L);
}

int printList(linkedList_h* L) {
	listNode* lptr = L->head;

	printf("Linked List(%d): ", L->follow);
	while (lptr->link != (listNode*)NULL) {
		printf("[%d]", lptr->data);
		lptr = lptr->link;
	}
	printf("[%d] \n", lptr->data);
}

int printCList(linkedList_h* L) {
	listNode* lptr = L->head;

	printf("Circlular Linked List(%d): ", L->follow);
	if (lptr == NULL) {
		printf("\n");
		return;
	}
	while (lptr->link != L->head) {
		printf("[%d]", lptr->data);
		lptr = lptr->link;
	}
	printf("[%d] \n", lptr->data);
}


void insertFirstNode(linkedList_h* L, elementType item) {
	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = L->head; //(1)
	L->head = newNode;  //(2)

	// return 0; void 함수이므로 리턴값 없음
}

void insertFirstCNode(linkedList_h* L, elementType item) {
	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = L->head; //(1)

	if (L->head != (listNode*)NULL) {
		listNode* temp = L->head;
		while (temp->link != L->head) {
			// tepm = temp->link; 오타로 인한 syntax error 발생
			temp = temp->link;
			L->follow++;
		}
		temp->link = newNode;
	}
	else {
		newNode->link = newNode;
	}
	L->head = newNode;  //(2)

	return 0;
}


void insertLastNode(linkedList_h* L, elementType item) {
	listNode* temp, * newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = (listNode*)NULL;

	temp = L->head;
	if (temp == (listNode*)NULL) {
		L->head = newNode;
		return;
	}

	while (temp->link != (listNode*)NULL) {
		temp = temp->link;
		L->follow++;
	}

	temp->link = newNode;

	return;
}

void insertMiddleNode(linkedList_h* L, listNode* pre, elementType item) {

	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;

	if (L->head == (listNode*)NULL) {
		newNode->link = (listNode*)NULL;
		L->head = newNode;
	}
	else if (pre == (listNode*)NULL) {
		newNode->link = L->head;
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

void insertNthNode(linkedList_h* L, int loc, elementType item) {
	if (L->head == (listNode*)NULL) {
		if (loc == 0) insertFirstNode(L, item);
		else fprintf(stderr, "[insertNthNode: list empty and loc not 0\n");
		return;
	}
	else {
		if (loc == 0) insertFirstNode(L, item);
		else {
			int i = loc; listNode* pre = L->head;
			while (i > 1 && pre->link != (listNode*)NULL) {
				i--, pre = pre->link;
				L->follow++;
			}
			if (i == 1) insertMiddleNode(L, pre, item);
			else fprintf(stderr, "[insertNthNode: location error");

		}
		return;
	}
}

int compare_item(elementType first, elementType second) {
	return (first - second);
}

void ordered_insertNode(linkedList_h* L, elementType item) {
	listNode* pre;

	if (L->head == (listNode*)NULL) insertFirstNode(L, item);
	else {
		if (compare_item(L->head->data, item) > 0)
			insertFirstNode(L, item);
		else {
			pre = L->head;
			while (pre->link != (listNode*)NULL) {
				if (compare_item(pre->data, item) < 0 &&
					compare_item(pre->link->data, item) > 0) break;
				pre = pre->link;
				L->follow++;
			}
			insertMiddleNode(L, pre, item);
		}
	}
}

void deleteNode(linkedList_h* L, listNode* p) {
	listNode* pre;

	if (L->head == (listNode*)NULL) return;
	/* if (L->head->link == (listNode*)NULL) {
		free(L->head);
		L->head = (listNode*)NULL;
		return;
	} */
	else if (p == (listNode*)NULL) return;
	else {
		pre = L->head;
		while (pre->link != p && p->link != (listNode*)NULL) {
			pre = pre->link;
			L->follow++;
		}
		if (pre->link == p) {
			pre->link = p->link; // 
			free(p);
		}
		else {
			fprintf(stderr, " delete item not in the list\n");
		}
	}
}

void deleteCNode(linkedList_h* L, listNode* p) {
	listNode* pre;

	if (L->head == (listNode*)NULL) return;
	/* if (L->head->link == (listNode*)NULL) {
		free(L->head);
		L->head = (listNode*)NULL;
		return;
	} */
	else if (p == (listNode*)NULL) return;
	else {
		pre = L->head;
		while (pre->link != p && p->link != L->head) {
			pre = pre->link;
			L->follow++;
		}
		if (pre->link == p) {
			pre->link = p->link; // 
			free(p);
		}
		else {
			fprintf(stderr, " delete item not in the list\n");
		}
	}
}