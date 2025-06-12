#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

main() {
	QueueType *myQ;

	myQ = createCQueue();

	printCQueue(myQ);	

	printf("Enqueue : A\n");
	enCQueue(myQ, 'A');
	printCQueue(myQ);

	printf("Dequeue : %c\n", myQ->queue[myQ->front]);
	deCQueue(myQ);
	printCQueue(myQ);

	printf("Enqueue : B\n");
	enCQueue(myQ, 'B');
	printCQueue(myQ);

	printf("Enqueue : C\n");
	enCQueue(myQ, 'C');
	printCQueue(myQ);

	printf("Enqueue : D\n");
	enCQueue(myQ, 'D');
	printCQueue(myQ);

	printf("Enqueue : E\n");
	enCQueue(myQ, 'E');
	printCQueue(myQ);
	
	destroyCQueue(myQ);
}
