#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int returnItem(int item)
{
	printf("삽입할 값: ");
	scanf("%d", &item);
	return item;
}

int returnLocation(int loc)
{
	printf("삽입할 위치: ");
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
		printf("1) insertFirst\t(리스트의 제일 앞에 삽입)\n");
		printf("2) insertLast\t(리스트의 제일 뒤에 삽입)\n");
		printf("3) insertMiddle\t(특정 값 뒤에 삽입)\n");
		printf("4) insertNthNode(N번째 위치 삽입)\n");
		printf("6) deleteNode\t(특정 값 삭제)\n");
		printf("7) print Head/Tail\n");
		printf("0) Program Stop\n");
		printf("Select menu ▶ ");
		scanf("%d", &menuSelect);
		printf("\n");
		if (menuSelect < 0 || menuSelect > 7) {
			printf("잘못된 입력입니다. 다시 입력하세요.\n");
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

	
	