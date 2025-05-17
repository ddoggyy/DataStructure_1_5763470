#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int returnItem(int item)
{
	printf("������ ��: ");
	scanf("%d", &item);
	return item;
}

int returnLocation(int loc)
{
	printf("������ ��ġ: ");
	scanf("%d", &loc);
	return loc;
}

int main(void)
{
	linkedList_h* myList;
	
	myList = createCLinkedList();
	int menuSelect = 1;
	int item = 0, loc = 0;

	while (menuSelect != 0)
	{
		printf("======= Linked_List Menu =======\n");
		printf("1) insertFirst\t(����Ʈ�� ���� �տ� ����)\n");
		printf("2) insertLast\t(����Ʈ�� ���� �ڿ� ����)\n");
		printf("3) insertMiddle\t(Ư�� �� �ڿ� ����)\n");
		printf("4) insertNthNode(N��° ��ġ ����)\n");
		printf("6) deleteNode\t(Ư�� �� ����)\n");
		printf("7) print Head/Tail\n");
		printf("0) Program Stop\n");
		printf("Select menu �� ");
		scanf("%d", &menuSelect);
		printf("\n");
		if (menuSelect < 0 || menuSelect > 7) {
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
			continue;
		}
		

		switch (menuSelect) {
		case 1:
			returnItem(item);
			insertFirstCNode(myList, item);
			break;
		case 2:
			returnItem(item);
			insertLastCNode(myList, item);
			break;
		case 3:
			returnItem(item);
			returnLocation(loc);
			insertMiddleCNode(myList, loc, item);
			break;
		case 4:
			returnItem(item);
			returnLocation(loc);
			insertNthCNode(myList, loc, item);
			break;
		case 6:
			returnItem(item);
			returnLocation(loc);
			deleteCNode(myList, item);
			break;
		case 7:
			printCList(myList);
			break;
		case 0:
			destroyCLinkedList(myList);
			break;
		}
	}
}

	
	