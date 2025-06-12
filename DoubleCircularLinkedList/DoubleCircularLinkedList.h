#pragma once

// typedef int elementType;

typedef struct {
	int coef;
	int expo;
} elementType;

typedef struct Node {
	struct Node* llink;
	elementType data;
	struct Node* rlink;
} NodeType;


extern NodeType* createDClinkedList();
extern void insertDClinkedList(NodeType* p, elementType item);
extern void insertLastDClinkedList(NodeType* H, elementType item);
extern elementType deleteDClinkedList(NodeType* p);
extern void deleteLastDClinkedList(NodeType* H);
extern void printDClinkedList(NodeType* H);