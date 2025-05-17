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
	listNode* newNode; // 노드 생성

	newNode = (listNode*)malloc(sizeof(listNode)); // listNode 크기 만큼 메모리 할당
	newNode->data = item; // newNode가 가리키는 data 주소에 item을 집어넣음
	newNode->link = L->head; // newNode가 가리키는 link 주소에 L이 가리키는 head 값을 집어넣음 (1) 
	L->head = newNode; // L이 가리키는 head 값에 newNode를 집어넣음 (2)

	return 0;
}

void insertFirstCNode(linkedList_h* L, elementType item) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;

	if (L->head == NULL) {
		// 리스트가 비어있을 때
		newNode->link = newNode;
		L->head = L->tail = newNode; // tail도 같이 갱신
	}
	else {
		newNode->link = L->head;
		L->tail->link = newNode; // tail의 link를 새 노드로
		L->head = newNode;
	}
}

linkedList_h* createLinkedList(void) { // linkedList_h 구조체의 포인터를 반환
	linkedList_h* lptr; // linkedList_h 구조체 포인터
	lptr = (linkedList_h*)malloc(sizeof(linkedList_h));
	lptr->head = (linkedList_h*)NULL;
	lptr->tail = (linkedList_h*)NULL;
	lptr->follow = 0; // 노드 이동 횟수 세는 변수를 초기화
	return lptr;
}

linkedList_h* createCLinkedList(void) {
	return createLinkedList();
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

void destroyCLinkedList(linkedList_h* L) {
	listNode* p; // listNode 구조체 포인터

	if (L == NULL || L->head == NULL) {
		free(L);
		return;
	}

	p = L->head;
	listNode* temp;
	// 원형 리스트이므로 do-while 사용
	do {
		temp = p->link;
		free(p);
		p = temp;
	} while (p != L->head);

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

void insertLastCNode(linkedList_h* L, elementType item) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = (listNode*)NULL; // 일단 NULL로 초기화

	if (L->head == (listNode*)NULL) {
		// 리스트가 비어있을 때
		newNode->link = newNode; // 자기 자신을 가리키게 함
		L->head = L->tail = newNode;
	}
	else {
		// 리스트에 노드가 이미 존재할 때
		newNode->link = L->head; // 새 노드가 리스트의 처음을 가리키게 함
		L->tail->link = newNode; // 기존 마지막 노드가 새 노드를 가리키게 함
		L->tail = newNode;       // tail 갱신
	}
	L->follow++;
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

void insertMiddleCNode(linkedList_h* L, listNode* pre, elementType item) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;

	if (L->head == (listNode*)NULL) {
		// 리스트가 비어있을 때
		newNode->link = newNode; // 자기 자신을 가리키게 함
		L->head = L->tail = newNode;
	}
	else if (pre == (listNode*)NULL) {
		// pre가 NULL이면 맨 앞에 삽입
		newNode->link = L->head;
		L->tail->link = newNode; // tail의 link를 새 노드로
		L->head = newNode;       // head 갱신
	}
	else {
		// 일반적인 중간 또는 마지막 위치에 삽입
		newNode->link = pre->link;
		pre->link = newNode;

		// 만약 tail 뒤에 삽입되면 tail 갱신
		if (pre == L->tail) {
			L->tail = newNode;
		}
	}
}

void insertNthNode(linkedList_h* L, int loc, elementType item) { // loc은 데이터 삽입 위치

	if (L->head == (listNode*)NULL) { // 리스트가 비어있다면
		if (loc == 0) insertFirstNode(L, item);  // 목표 위치가 0이면 맨 앞에 노드 삽입
		else fprintf("[insertNthNode: list empty and lo not 0\n", stderr); // 0이 아니라면 오류 메시지 출력 후 리턴
		return;
	}
	else { // 리스트가 비어있지 않다면
		if (loc == 0) insertFirstNode(L, item); // 목표 위치가 0이면 맨 앞에 노드 삽입
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

void insertNthCNode(linkedList_h* L, int loc, elementType item) { // loc은 데이터 삽입 위치

	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;

	if (L->head == (listNode*)NULL) { // 리스트가 비어있을 때
		if (loc == 0) {
			newNode->link = newNode; // 자기 자신을 가리키게 함 (원형 리스트)
			L->head = L->tail = newNode;
			L->follow++;
		}
		else {
			fprintf(stderr, "[insertNthNode: list empty and loc not 0]\n");
		}
		return;
	}

	if (loc == 0) {
		// 맨 앞에 삽입
		newNode->link = L->head;
		L->tail->link = newNode; // tail의 link를 새 노드로
		L->head = newNode;       // head 갱신
		L->follow++;
	}
	else {
		// 특정 위치에 삽입
		int i = 0;
		listNode* pre = L->head;

		// 위치를 찾기 위해 순회
		while (i < loc - 1 && pre->link != L->head) {
			pre = pre->link;
			i++;
		}

		// 위치가 리스트 길이보다 크면 마지막에 삽입
		if (i < loc - 1) {
			// 리스트 길이보다 크면 마지막에 삽입
			pre = L->tail;
		}

		insertMiddleNode(L, pre, item);
		L->follow++;
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
		while (pre->link != p && p->link != (listNode*)NULL) {
			pre = pre->link;
			L->follow++;
		}
		// pre의 다음 노드가 삭제 노드가 아니고, 삭제 노드의 다음 노드가 NULL이 아닐때까지 pre를 다음 노드로 이동
		if (pre->link == p) { //  pre의 다음 노드가 삭제 노드라면
			pre->link = p->link; // pre의 다음 노드는 삭제 노드의 다음 노드로 이동
			free(p);
		}
		else fprintf(stderr, "delete item not in the list\n"); // p가 리스트 내에 없으니 오류 메시지 출력
	}
}

void deleteCNode(linkedList_h* L, listNode* p) { // p는 삭제하려는 노드를 나타내는 포인터
	if (L->head == (listNode*)NULL || p == (listNode*)NULL) return; // 리스트가 비어있거나 삭제 대상이 NULL이면 종료

	listNode* pre = L->head;

	// p가 head인 경우 처리
	if (p == L->head) {
		if (L->head->link == L->head) {
			// 리스트에 노드가 하나만 있을 때
			free(L->head);
			L->head = L->tail = (listNode*)NULL;
		}
		else {
			// 여러 노드가 있을 때
			L->tail->link = L->head->link; // tail의 link를 새 head로 변경
			free(L->head);
			L->head = pre->link; // head를 다음 노드로 변경
		}
		return;
	}

	// p가 head가 아닌 경우
	// pre를 p 이전 노드로 찾기
	do {
		if (pre->link == p) break;
		pre = pre->link;
	} while (pre != L->tail);

	if (pre->link == p) {
		// p가 리스트 내에 존재하는 경우
		pre->link = p->link;
		if (p == L->tail) {
			// 삭제하는 노드가 tail인 경우 tail 갱신
			L->tail = pre;
		}
		free(p);
	}
	else {
		// 리스트 내에 p가 없음
		fprintf(stderr, "delete item not in the list\n");
	}
}