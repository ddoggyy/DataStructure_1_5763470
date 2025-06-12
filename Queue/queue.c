#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

QueueType* createCQueue(void) {
	QueueType* cQ;
	
	cQ = (QueueType*)malloc(sizeof(QueueType));
	cQ->front = 0;
	cQ->rear = 0;
	return cQ;
}

void destroyCQueue(QueueType* cQ) {
	free(cQ);
}

int isCQueueEmpty(QueueType* cQ) {
	return (cQ->front = cQ->rear);
}

int isCQueueFull(QueueType* cQ) {
	return (((cQ->rear + 1) % cQ_SIZE) == (cQ->rear));
}

void enCQueue(QueueType* cQ, element item) {
	if (isCQueueFull(cQ)) return;
	else {
		cQ->queue[cQ->rear] = item;
		cQ->rear = (cQ->rear + 1) % cQ_SIZE;
		
	}
}

element deCQueue(QueueType* cQ) {
	if (isCQueueEmpty(cQ)) return;
	else {
		cQ->front = (cQ->front + 1) % cQ_SIZE;
		return cQ->queue[cQ->front];
	}
}

void printCQueue(QueueType* cQ) {
	printf("Queue: [ ");
	for (int i = cQ->front; i != cQ->rear; i = (i + 1) % cQ_SIZE) printf("%c ", cQ->queue[i]);
	printf("]\n");
}

LQueueType* createLQueue() {
	return createDClinkedList();
}