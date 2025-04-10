	#define _CRT_SECURE_NO_WARNINGS	
	#include <stdio.h>
	#include <stdlib.h>
	#include "LinearList.h"

	int main() {
		listType* List1;
		listType* List2;
		listType* sumList;

		List1 = createList(10);
		List2 = createList(10);
		sumList = createList(List1->size + List2->size);

		int row, col, val;

		printf("����� �Է��Ͻÿ�? (-1�Է� �� ����� �Է��� �����)\n");
		for (int i = 0; i < List1->size; i++) {
			scanf("%d", &row);
			if (row == -1) break;
			scanf("%d %d", &col, &val);
			ordered_insertItem(List1, (elementType) { row, col, val });
		}

		printf("����� �Է��Ͻÿ�? (-1�Է� �� ����� �Է��� �����)\n");
		for (int i = 0; i < List2->size; i++) {
			scanf("%d", &row);
			if (row == -1) break; 
			scanf("%d %d", &col, &val);
			ordered_insertItem(List2, (elementType) { row, col, val }); 
		}

		for (int i = 0; i < List1->last + 1; i++) {
			ordered_insertItem(sumList, List1->array[i]); // List1�� ���� sumList�� ����
		}

		for (int i = 0; i < List2->last + 1; i++) {
			ordered_insertItem(sumList, List2->array[i]); // List2�� ���� sumList�� ����
		}

		for (int i = 0; i < sumList->last; i++) { 
			for (int j = i + 1; j < sumList->last; j++) {
				if (sumList->array[i].row == sumList->array[j].row && sumList->array[i].col == sumList->array[j].col) { // ��, �� ��
					sumList->array[i].val += sumList->array[j].val;
					deleteItem(sumList, j); //  �� �� �ߺ��Ǵ� �� ����
				}
			}
		}
	
		printf("�� ����� ��\n");
		printf("List: size = %d, last = %d\n", sumList->size, sumList->last);
		printf("Items: \n");
		for (int i = 0; i < sumList->last + 1; i++) {
			printf("   [%d] %d, %d, %d\n", i, sumList->array[i].row, sumList->array[i].col, sumList->array[i].val);
		}


	}