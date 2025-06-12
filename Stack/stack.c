#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stackType* A_createStack() {
	stackType* s = (stackType*)malloc(sizeof(stackType));
	s->top = -1; // index 0번부터 시작하기 때문에 -1로 초기화
	return s;
}

void A_destroyStack(stackType* stack) {
	free(stack);
}

void A_push(stackType* stack, element item) {
	if (!A_isFull(stack)) stack->data[++(stack->top)] = item;
	else fprintf(stderr, "Stack is Full\n");
}

element A_pop(stackType* stack) {
	element r = stack->data[stack->top];
	if (!A_isEmpty(stack)) {
		stack->top--;
		return r;
	}
	else {
		fprintf(stderr, "Stack is Empty\n");
	}
}

int A_isEmpty(stackType* stack) {
	return (stack->top == -1);
}

int A_isFull(stackType* stack) {
	return (stack->top == (STACK_SIZE - 1));
}

void A_printStack(stackType* stack) {
	printf("Stack: ");
	for (int i = 0; i <= stack->top; i++) {
		printf("[%02d]{%2d} ", i, stack->data[i]);
	}
	printf("\n");
}

stackNode* topNode;

stackNode* L_createStack() {
	topNode = (stackNode*)NULL;
}

void L_destroyStack() {
	if (topNode != (stackNode*)NULL) {
		stackNode* s = topNode->link;
		while (s != (stackNode*)NULL) {
			free(topNode);
			topNode = s;
			s = topNode->link;
		}
		free(topNode);
		topNode = (stackNode*)NULL;
	}
}

void L_push(element item) {
	stackNode* n = (stackNode*)malloc(sizeof(stackNode));
	n->data = item;
	n->link = topNode;
	topNode = n;
}

element L_pop() {
	if (!L_isEmpty()) {
		element r = topNode->data;
		stackNode* n = topNode->link;
		free(topNode);
		topNode = n;
		return r;
	}
	else {
		fprintf(stderr, "Stack is Empty\n");
		return -1;
	}
}

int L_isEmpty() {
	return (topNode == (stackNode*)NULL);
}

int L_isFull() {
	return 0;
}

void L_printStack() {
	stackNode* n = topNode;

	printf("Stack: ");
	while (n != (stackNode*)NULL) {
		printf("{%c}", n->data);
		n = n->link;
	}
	printf("\n");
}