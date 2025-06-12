#pragma once
#define STACK_SIZE 100

typedef int element;

typedef struct {
	int top;
	element data[STACK_SIZE];
} stackType;

typedef struct StackNode{
	element data;
	struct StackNode* link;
} stackNode;

// extern element stack[STACK_SIZE];

extern stackType *A_createStack();
extern void A_destroyStack(stackType* stack);
extern void A_push(stackType* stack, element item);
extern element A_pop(stackType* stack);
extern int A_isEmpty(stackType* stack);
extern int A_isFull(stackType* stack);
extern void A_printStack(stackType* stack);

extern stackNode* topNode;
extern stackNode* L_createStack();
extern void L_destroyStack();
extern void L_push(element item);
extern element L_pop();
extern int L_isEmpty();
extern int L_isFull();
extern void L_printStack();