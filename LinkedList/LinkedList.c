

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
	listNode* newNode; // 노드 생성

	newNode = (listNode*)malloc(sizeof(listNode)); // listNode 크기 만큼 메모리 할당
	newNode->data = item; // newNode가 가리키는 data 주소에 item을 집어넣음
	newNode->link = L->head; // newNode가 가리키는 link 주소에 L이 가리키는 head 값을 집어넣음 (1) 
	L->head = newNode; // L이 가리키는 head 값에 newNode를 집어넣음 (2)

	return 0;
}

linkedList_h* createLinkedList(void) { // linkedList_h 구조체의 포인터를 반환
	linkedList_h* lptr; // linkedList_h 구조체 포인터
	lptr = (linkedList_h*)malloc(sizeof(linkedList_h)); 
	lptr->head = (linkedList_h*)NULL; 
	lptr->follow = 0; // 노드 이동 횟수 세는 변수를 초기화
	return lptr;
}

void destroyLinkedList(linkedList_h* L) {
	listNode* p; // listNode 구조체 포인터

	while (L->head != NULL) { // 
		p = L->head; 
		L->head = L->head->link; // L->head = p->link; 헤더가 NULL일때까지 헤더를 다음 리스트로 복제한 후, 첫 노드를 해제함
		free(p); 
	}
	free(L); // 리스트 해체
}

void insertLastNode(linkedList_h* L, elementType item) {
	listNode* temp, * newNode; // temp는 리스트 순회용, newNode는 새 노드를 의미
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item; 
	newNode->link = (listNode*)NULL; // 새 노드의 link는 마지막 노드이므로 NULL

	temp = L->head;
	if (temp == (listNode*)NULL) { // 리스트가 비어있으면 새 노드를 리스트의 헤더로 지정
		L->head = newNode;
		return;
	}
	while (temp->link != (listNode*)NULL) { // temp의 다음 노드가 NULL일때까지 (리스트의 마지막 노드까지) 
		temp = temp->link; // temp를 다음 노드로 이동
		L->follow++; // 노드 이동 횟수 
	}
	temp->link = newNode; // temp의 다음 노드를 newNode로 지정

	return;
}

void insertMiddleNode(linkedList_h* L, listNode* pre, elementType item) {

	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item; // 값 저장

	if (L->head == (listNode*)NULL) { // 리스트가 비어있다면
		newNode->link = (listNode*)NULL; // 새 노드를 리스트의 헤더로 지정
		L->head = newNode;
	}
	else if (pre == (listNode*)NULL) { // pre가 비어있다면 (원래 노드의 이전 노드가 비어있다면)
		newNode->link = L->head; // 새 노드의 다음 노드를 헤더로 지정
		L->head = newNode; // 헤더를 새 노드로 변경 (맨 앞에 삽입)
	}
	else { 
		newNode->link = pre->link; // 새 노드의 다음 노드는 원래 노드의 다음 노드를 가리킴
		pre->link = newNode; // 지정된 위치에 새 노드를 삽입
	}
}

void insertNthNode(linkedList_h* L, int loc, elementType item) { // loc은 데이터 삽입 위치

	if (L->head == (listNode*)NULL) { // 리스트가 비어있다면
		if (loc == 0) insertFirstNode(L, item);  // 목표 위치가 0이면 맨 앞에 노드 삽입
		else fprintf("[insertNthNode: list empty and lo not 0\n", stderr); // 0이 아니라면 오류 메시지 출력 후 리턴
		return;
	}
	else { // 리스트가 비어있지 않다면
		if(loc == 0) insertFirstNode(L, item); // 목표 위치가 0이면 맨 앞에 노드 삽입
		else {
			int i = loc; listNode* pre = L->head;  
			while (i > 1 && pre->link != (listNode*)NULL) { // 위치가 맨 앞이 아니고 pre->link가 NULL이 아닐때까지 반복
				i--; // 목표 위치를 1씩 반대로 이동 (이동하였으니 목표 위치까지의 거리를 줄임)
				pre = pre->link; // pre가 가리키던 노드를 다음 노드로 변경하는 것, 즉 pre를 다음 노드로 이동시킴
			}
				insertMiddleNode(L, pre, item); // pre에, 즉 loc-1 다음에(loc의 위치에) 새 노드를 연결
		}
		return;
	}
}

	int compare_item(elementType first, elementType second) {
		return (first - second);
	}

	void ordered_insertNode(linkedList_h* L, elementType item) { 
		listNode* pre;

		if (L->head == (listNode*)NULL) insertFirstNode(L, item); // 리스트가 비어있으면 insertFirstNode 호출
		else { // 비어있지 않다면
			if (compare_item(L->head->data, item) > 0) // 헤더의 값 - item > 0이면
				insertFirstNode(L, item); // 맨 앞에 삽입 (즉, 작은 값이 맨 앞으로 옴)
			else { // 헤더의 값 - item =< 0 이면
				pre = L->head; // 리스트의 맨 앞 노드로 pre를 초기화
				while (pre->link != (listNode*)NULL) { // pre의 다음 노드가 NULL이 아닐때까지 반복
					if (compare_item(pre->data, item) < 0 && compare_item(pre->link->data, item) > 0) {
						break;
					}
					// pre의 값이 item보다 작고 그 다음 노드의 값이 item보다 크다면, break 
					pre = pre->link; // pre를 다음 노드로 이동
					L->follow++;
				}
				insertMiddleNode(L, pre, item);
			}
		}
	}

void deleteNode(linkedList_h* L, listNode* p) { // p는 삭제하려는 노드를 나타내는 포인터
	listNode* pre;

	if (L->head == (listNode*)NULL) return; // 리스트가 비어있다면 삭제할 노드가 없으므로 리턴
	/*if (L->head->link == (listNode*)NULL) { // 리스트의 다음 노드가 비어있다면
		free(L->head);
		L->head = (listNode*)NULL;
		return;
	}*/
	else if (p == (listNode*)NULL) return; // 삭제 대상 노드가 NULL이면 없으므로 리턴
	else {
		pre = L->head; // pre를 리스트의 헤더로 초기화
		while (pre->link != p && p->link != (listNode*)NULL) pre = pre->link;
		// pre의 다음 노드가 삭제 노드가 아니고, 삭제 노드의 다음 노드가 NULL이 아닐때까지 pre를 다음 노드로 이동
		if (pre->link == p) { //  pre의 다음 노드가 삭제 노드라면
			pre->link = p->link; // pre의 다음 노드는 삭제 노드의 다음 노드로 이동
			free(p); 
			L->follow++;
		}
		else fprintf(stderr, "delete item not in the list\n"); // p가 리스트 내에 없으니 오류 메시지 출력
	}
}