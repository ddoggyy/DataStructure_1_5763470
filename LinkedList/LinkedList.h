#pragma once

typedef int elementType; // ��Ʈ�� ������ �����ʹ� ����

typedef struct ListNode { // linked List�� ��� Ÿ�� ����
	elementType data;
	struct listNode* link;
} listNode;

typedef struct { // linked List�� ���
	listNode* head;
} linkedList_h;

extern printList(linkedList_h* L);
extern insertFirstNode(linkedList_h* L, elementType item);