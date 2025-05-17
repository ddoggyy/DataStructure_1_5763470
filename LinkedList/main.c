#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

main()
{
	/*
	linkedList_h myList;
	myList.head = (listNode*)NULL;
	*/

	linkedList_h* myList;
	myList = createLinkedList();

	insertFirstNode(myList, 1);
	insertFirstNode(myList, 2);
	insertFirstNode(myList, 3);
	insertFirstNode(myList, 4);
	insertFirstNode(myList, 5);

	insertLastNode(myList, 6);
	insertLastNode(myList, 7);
	insertLastNode(myList, 8);
	
	insertMiddleNode(myList, myList->head->link->link, 9);

	insertNthNode(myList, 2, 20);

	printList(myList);
	destroyLinkedList(myList);

	printf("Destroy unorder linked list and create new ordered linked list\n");
	myList = createLinkedList();

	ordered_insertNode(myList, 5);
	ordered_insertNode(myList, 3);
	ordered_insertNode(myList, 8);
	ordered_insertNode(myList, 2);
	ordered_insertNode(myList, 9);
	ordered_insertNode(myList, 11);

	printList(myList);

	deleteNode(myList, myList->head->link->link);
	printList(myList);
<<<<<<< HEAD

	destroyLinkedList(myList);

	myList = createCLinkedList();

	insertFirstCNode(myList, 1);
	insertFirstCNode(myList, 2);
	insertFirstCNode(myList, 3);
	insertFirstCNode(myList, 4);
	insertFirstCNode(myList, 5);

	printCList(myList);
	deleteCNode(myList, myList->head->link->link);
	printCList(myList);
=======
>>>>>>> 436ffbbf1f7d160979f5e2f6ca34170026c2cf72
}