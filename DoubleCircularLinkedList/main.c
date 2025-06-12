#include <stdio.h>
#include <stdlib.h>
#include "DoubleCircularLinkedList.h"

void addPoly(NodeType* AH, NodeType* BH, NodeType* CH) {
	NodeType* a = AH->rlink;
	NodeType* b = BH->rlink;
	
	while (a != AH || b != BH) {
		if (a->data.expo > b->data.expo) {
			insertLastDClinkedList(CH, a->data);
			a = a->rlink;
		}
		else if (a->data.expo < b->data.expo) {
			insertLastDClinkedList(CH, b->data);
			b = b->rlink;
		}
		else {
			insertLastDClinkedList(CH, (elementType) { (a->data.coef + b->data.coef), a->data.expo });
			b = b->rlink;
			a = a->rlink;
		}
	}
	while (a != AH) {
		insertLastDClinkedList(CH, a->data);
		a = a->rlink;
	}
}

main() {
	NodeType* A, * B, * C;
	A = createDClinkedList();
	B = createDClinkedList();
	C = createDClinkedList();

	printf("Polynomial A(x)\n");
	insertLastDClinkedList(A, (elementType) { 4, 3 });
	insertLastDClinkedList(A, (elementType) { 3, 2 });
	insertLastDClinkedList(A, (elementType) { 5, 1 });
	
	printDClinkedList(A);

	printf("Polynomial B(x)\n");
	insertLastDClinkedList(B, (elementType) { 3, 4 });
	insertLastDClinkedList(B, (elementType) { 1, 3 });
	insertLastDClinkedList(B, (elementType) { 2, 1 });
	insertLastDClinkedList(B, (elementType) { 1, 0 });
	
	printDClinkedList(B);

	addPoly(A, B, C);

	printDClinkedList(C);

	/*
	NodeType* myList;
	myList = createDClinkedList();
	insertDClinkedList(myList, 1);
	insertDClinkedList(myList, 2);
	insertDClinkedList(myList, 3);
	insertDClinkedList(myList, 4);
	insertDClinkedList(myList->llink, 5);
	insertDClinkedList(myList->rlink, 6);

	printDClinkedList(myList);

	deleteDClinkedList(myList->rlink);
	deleteDClinkedList(myList->llink);
	deleteDClinkedList(myList->rlink->rlink);

	printDClinkedList(myList);

	insertLastDClinkedList(myList, 7);
	printDClinkedList(myList);

	deleteLastDClinkedList(myList);
	deleteLastDClinkedList(myList);
	printDClinkedList(myList);
	*/
}