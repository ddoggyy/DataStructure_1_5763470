#include <stdio.h>
#include <stdlib.h>

#include "LinearList.h"

listType* createList(int size) {
	listType* lptr;

	lptr = (listType*)malloc(sizeof(listType));
	lptr->array = (elementType*)malloc(sizeof(elementType) * size);
	lptr->size = size;
	lptr->last = -1;
	lptr->move = 0;

	return lptr;
}

int destroyList(listType* list) {
	free(list->array);
	free(list);
}

elementType readItem(listType* list, int index) {
	if (index < 0 || index > list->last) {
		fprintf(stderr, "Index error %d in readItem\n", index);
		return NULL_ITEM;
	}
	return list->array[index];
}
int compare_item(elementType item1, elementType item2) {
	return (item1.expo - item2.expo);
}
/*
int compare_item(elementType item1, elementType item2) {
	if (item1.row != item2.row) return (item1.row - item2.row);
	else return (item1.col - item2.col);
}
*/

int ordered_insertItem(listType* list, elementType item) {
	int i, j;

	for (i = 0; i <= list->last; i++) {
		if (list->array[i].expo == item.expo) {
			list->array[i].coef += item.coef;

			// 계수가 0이면 삭제
			if (list->array[i].coef == 0) {
				deleteItem(list, i);
			}
			return 1;
		}
		else if (list->array[i].expo > item.expo) {
			break;
		}
	}

	// 새 항 삽입
	for (j = list->last + 1; j > i; j--) {
		list->array[j] = list->array[j - 1];
		list->move++;
	}
	list->array[i] = item;
	list->last++;

	return 1;

}

int insertItem(listType* list, int index, elementType item) {
	if (index < 0 || index >(list->last + 1)) {
		fprintf(stderr, "Index error %d in readItem\n", index);
		return -1;
	}
	if (index > list->size) {
		fprintf(stderr, "list is full(%d) in readItem\n", index);
		return -1;
	}

	for (int i = list->last + 1; i > index; i--) {
		list->array[i] = list->array[i - 1];
		list->move++;
	}
	list->array[index] = item;
	list->last++;

	return 1;
}

elementType deleteItem(listType* list, int index) {
	elementType r = list->array[index];

	if (index < 0 || index > list->last) {
		fprintf(stderr, "Index error %d in deleteItem\n", index);
		return NULL_ITEM;
	}

	for (int i = index; i < list->last; i++) {
		list->array[i] = list->array[i + 1];
		list->move++;
	}
	list->last--;

	return r;
}
int printList(listType* list) {
	printf("List: size = %d, last = %d, move = %d\n\t Items:", list->size, list->last, list->move);
	for (int i = list->last; i >= 0; i--) {
		printf("%d", list->array[i].coef); 
		if (list->array[i].expo != 0) printf("X^%d", list->array[i].expo);
		if (i != 0) printf(" + ");
	}
}

/*
int printList(listType* list) {
	printf("List: size = %d, last = %d, move = %d\n\t Items:", list->size, list->last, list->move);
	for (int i = 0; i <= list->last; i++) {
		printf(" [%d]{%d,%d,%d} ", i, list->array[i].row,
			list->array[i].col,
			list->array[i].val);
	}
	printf("\n");
}
*/

int initList(listType* list) {
	list->last = -1;
	list->move = 0;
}