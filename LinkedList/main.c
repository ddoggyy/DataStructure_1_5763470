
#include <stdio.h>
#include <stdlib.h>

#include "Linked List.h"

main() {

	// linkedList_h mylist;
	// mylist.head = (listNode*)NULL;

	linkedList_h* mylist;
	mylist = createLinkedList();

	insertFirstNode(mylist, 1);
	insertFirstNode(mylist, 2);
	insertFirstNode(mylist, 3);
	insertFirstNode(mylist, 4);
	insertFirstNode(mylist, 5);

	insertLastNode(mylist, 6);
	insertLastNode(mylist, 7);
	insertLastNode(mylist, 8);

	insertMiddleNode(mylist, mylist->head->link->link, 9);

	insertNthNode(mylist, 2, 20);

	printList(mylist);
	destroyLinkedList(mylist);

	printf(" Destroy unoreder linked list and new oredered linked list\n");
	mylist = createLinkedList();

	ordered_insertNode(mylist, 5);
	ordered_insertNode(mylist, 3);
	ordered_insertNode(mylist, 8);
	ordered_insertNode(mylist, 2);
	ordered_insertNode(mylist, 9);
	ordered_insertNode(mylist, 11);

	printList(mylist);

	deleteNode(mylist, mylist->head->link->link);
	printList(mylist);

	destroyLinkedList(mylist);

	mylist = createCLinkedList();
	insertFirstCNode(mylist, 1);
	insertFirstCNode(mylist, 2);
	insertFirstCNode(mylist, 3);
	insertFirstCNode(mylist, 4);
	insertFirstCNode(mylist, 5);

	printCList(mylist);
	deleteCNode(mylist, mylist->head->link->link);
	printCList(mylist);

	destroyCLinkedList(mylist);

}