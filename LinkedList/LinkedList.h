#pragma once

typedef int elementType; // 노트에 저장할 데이터는 정수

typedef struct ListNode { // linked List의 노드 타입 정의
	elementType data;
	struct listNode* link;
} listNode;

typedef struct { // linked List의 헤더
	listNode* head;
} linkedList_h;

extern printList(linkedList_h* L);
extern insertFirstNode(linkedList_h* L, elementType item);