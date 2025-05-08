#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

main()
{
	linkedList_h myList;

	myList.head = (listNode*)NULL;
	insertFirstNode(&myList, 1);
	insertFirstNode(&myList, 2);
	insertFirstNode(&myList, 3);
	insertFirstNode(&myList, 4);
	insertFirstNode(&myList, 5);
	
	printList(&myList);
}