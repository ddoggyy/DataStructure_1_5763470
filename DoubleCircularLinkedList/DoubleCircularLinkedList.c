#include <stdio.h>
#include <stdlib.h>
#include "DoubleCircularLinkedList.h"

NodeType* createDClinkedList() {
	NodeType* H;

	H = (NodeType*)malloc(sizeof(NodeType));
	H->llink = H->rlink = H; // 헤더의 왼쪽 링크와 오른쪽 링크를 헤더로 초기화
	return H;
}

void insertDClinkedList(NodeType* p, elementType item) {
	NodeType* newNode;
	newNode = (NodeType*)malloc(sizeof(NodeType));

	newNode->data = item;

	newNode->llink = p; // 새 노드의 왼쪽 링크는 p의 주소를 가리킴
	newNode->rlink = p->rlink; // 새 노드의 오른쪽 링크는 p가 가리켰던 오른쪽 노드(즉 p의 원래 다음 노드(p->rlink))를 가리킴
	p->rlink->llink = newNode; // p->rlink의 왼쪽 링크는 원래 p를 가리키고 있었으나 newNode가 끼어들었으니 바꿔줌
	p->rlink = newNode; // p의 오른쪽 링크를 newNode로 바꿔줌
}

void insertLastDClinkedList(NodeType* H, elementType item) {
	insertDClinkedList(H->llink, item); 
}

elementType deleteDClinkedList(NodeType* p) {
	elementType r = p->data; // data를 저장해둠

	p->llink->rlink = p->rlink; // p의 이전 노드는 p의 오른쪽 노드를 가리킴
	p->rlink->llink = p->llink; // p의 다음 노드는 p의 왼쪽 노드를 가리킴
	free(p); // p의 메모리를 해제
	return r; 
}

void deleteLastDClinkedList(NodeType* H) {
	deleteDClinkedList(H->llink);
}

void printDClinkedList(NodeType* H) {
	NodeType* nptr = H->rlink;

	/*
	if (nptr->rlink == H) return;
	nptr = nptr->rlink;
	*/

	printf("이중연결리스트 출력\n순방향: ");

	while (nptr != H) {
		printf("(%d, %d)", nptr->data.coef, nptr->data.expo);
		nptr = nptr->rlink;
	} 
	printf("\n");

	printf("역방향: ");
	nptr = H->llink;
	while (nptr != H) {
		printf("(%d, %d)", nptr->data.coef, nptr->data.expo);
		nptr = nptr->llink;
	}
	printf("\n\n");
}