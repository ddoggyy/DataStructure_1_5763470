#include <stdio.h>
#include <stdlib.h>
#include "DoubleCircularLinkedList.h"

NodeType* createDClinkedList() {
	NodeType* H;

	H = (NodeType*)malloc(sizeof(NodeType));
	H->llink = H->rlink = H; // ����� ���� ��ũ�� ������ ��ũ�� ����� �ʱ�ȭ
	return H;
}

void insertDClinkedList(NodeType* p, elementType item) {
	NodeType* newNode;
	newNode = (NodeType*)malloc(sizeof(NodeType));

	newNode->data = item;

	newNode->llink = p; // �� ����� ���� ��ũ�� p�� �ּҸ� ����Ŵ
	newNode->rlink = p->rlink; // �� ����� ������ ��ũ�� p�� �����״� ������ ���(�� p�� ���� ���� ���(p->rlink))�� ����Ŵ
	p->rlink->llink = newNode; // p->rlink�� ���� ��ũ�� ���� p�� ����Ű�� �־����� newNode�� ���������� �ٲ���
	p->rlink = newNode; // p�� ������ ��ũ�� newNode�� �ٲ���
}

void insertLastDClinkedList(NodeType* H, elementType item) {
	insertDClinkedList(H->llink, item); 
}

elementType deleteDClinkedList(NodeType* p) {
	elementType r = p->data; // data�� �����ص�

	p->llink->rlink = p->rlink; // p�� ���� ���� p�� ������ ��带 ����Ŵ
	p->rlink->llink = p->llink; // p�� ���� ���� p�� ���� ��带 ����Ŵ
	free(p); // p�� �޸𸮸� ����
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

	printf("���߿��Ḯ��Ʈ ���\n������: ");

	while (nptr != H) {
		printf("(%d, %d)", nptr->data.coef, nptr->data.expo);
		nptr = nptr->rlink;
	} 
	printf("\n");

	printf("������: ");
	nptr = H->llink;
	while (nptr != H) {
		printf("(%d, %d)", nptr->data.coef, nptr->data.expo);
		nptr = nptr->llink;
	}
	printf("\n\n");
}