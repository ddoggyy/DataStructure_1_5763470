#pragma once

#include "DCLinkedList.h"
#define cQ_SIZE 4

typedef char element;

typedef struct {
	element queue[cQ_SIZE];
	int front, rear; 
}QueueType;

typedef NodeType LQueueType;

extern QueueType* createCQueue(void);
extern void destroyCQueue(QueueType* cQ);
extern int isCQueueEmpty(QueueType* cQ);
extern int isCQueueFull(QueueType* cQ);
extern void enCQueue(QueueType* cQ, element item);
extern element deCQueue(QueueType* cQ);
extern void printCQueue(QueueType* cQ);

extern LQueueType* createLQueue(void);