

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
	listNode* newNode; // 노드 생성

	newNode = (listNode*)malloc(sizeof(listNode)); // listNode 크기 만큼 메모리 할당
	newNode->data = item; // newNode가 가리키는 data 주소에 item을 집어넣음
	newNode->link = L->head; // newNode가 가리키는 link 주소에 L이 가리키는 head 값을 집어넣음 (1) 
	L->head = newNode; // L이 가리키는 head 값에 newNode를 집어넣음 (2)

	return 0;
}