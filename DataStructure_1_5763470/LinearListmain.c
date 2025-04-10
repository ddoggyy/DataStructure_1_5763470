#include <stdio.h>
#include <stdlib.h>

#include "LinearList.h"

/*
listType* SmTranspose(listType* org) {
	listType* tr;
	elementType o_item;

	tr = createList(org->size);

	for (int i = 0; i <= org->last; i++) {
		o_item = readItem(org, i);
		ordered_insertItem(tr, (elementType) { o_item.col, o_item.row, o_item.val });
	}
	return tr;
}
	

main() {
	
	listType* myList, * trans;

	myList = createList(20);

	ordered_insertItem(myList, (elementType) { 0, 2, 2 });
	ordered_insertItem(myList, (elementType) { 0, 6, 12 });
	ordered_insertItem(myList, (elementType) { 1, 4, 7 });
	ordered_insertItem(myList, (elementType) { 2, 0, 23 });
	ordered_insertItem(myList, (elementType) { 3, 3, 31 });
	ordered_insertItem(myList, (elementType) { 4, 1, 14 });
	ordered_insertItem(myList, (elementType) { 4, 5, 26 });
	ordered_insertItem(myList, (elementType) { 5, 6, 6 });
	ordered_insertItem(myList, (elementType) { 6, 0, 52 });
	ordered_insertItem(myList, (elementType) { 7, 4, 11 });

	printf("Original Matrix\n");
	printList(myList);

	trans = SmTranspose(myList);
	printf("Transpose Matrix\n");
	printList(trans);


	ordered_insertItem(myList, 10);
	ordered_insertItem(myList, 40);
	ordered_insertItem(myList, 20);
	ordered_insertItem(myList, 30);


	printList(myList);

	ordered_insertItem(myList, 5);
	printList(myList);

	ordered_insertItem(myList, 15);
	printList(myList);

	ordered_insertItem(myList, 45);
	printList(myList);

	ordered_insertItem(myList, 100);
	printList(myList);

	ordered_insertItem(myList, 200);
	printList(myList);
	
}
*/

listType* polyadd(listType* f, listType* s) {
	listType* a;
	int i = 0, j = 0;
	elementType f_item, s_item;
	a = createList(f->last + s->last + 2);

	while (i <= f->last && j <= s->last) {  
		f_item = readItem(f, i);
		s_item = readItem(s, j);
		if (f_item.expo < s_item.expo) {
			ordered_insertItem(a, f_item);
			i++;
		}
		else if (f_item.expo == s_item.expo) {
			ordered_insertItem(a, (elementType) { (f_item.coef + s_item.coef), f_item.expo });
			i++; j++;
		}
		else {
			ordered_insertItem(a, s_item);
			j++;
		}
	} // 두 다항식의 차수가 같으면 지수를 더해줌

	while (i <= f->last) {
		ordered_insertItem(a, readItem(f, i));
		i++;
	}

	while (j <= s->last) {
		ordered_insertItem(a, readItem(s, j));
		j++;
	} // 더해서 남은 항을 넣어줌			

	return a;
}

main() {
	listType* poly1, * poly2, * poly3;
	poly1 = createList(10);
	ordered_insertItem(poly1, (elementType) { 4, 3 });
	ordered_insertItem(poly1, (elementType) { 2, 1 });
	ordered_insertItem(poly1, (elementType) { 1, 0 });
	printf(" First Polynomial\n");
	printList(poly1);		

	poly2 = createList(10);
	ordered_insertItem(poly2, (elementType) { 3, 2 });
	ordered_insertItem(poly2, (elementType) { 4, 1 });
	printf("\n Second Polynomial\n");
	printList(poly2);

	poly3 = polyadd(poly1, poly2);
	printf("\n Added Polynomial\n");
	printList(poly3);

	destroyList(poly1);
	destroyList(poly2);
	destroyList(poly3);
}