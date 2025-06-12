#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int check_brace(char* ex) {
	stackType* myStack = A_createStack();
	char* cptr = ex;


	while (*cptr != '\0') {
		switch (*cptr) {
		case '(' : A_push(myStack, *cptr); cptr++; break;
		case ')': A_pop(myStack); cptr++; break;
		default: cptr++;
		}
	}

	if (A_isEmpty(myStack)) printf("Correct!!!");
	else printf("Error!!!");

	A_destroyStack(myStack);

	return 0;
}

char* infix_to_postfix(char* expr) {
	char* postfix = (char*)malloc(strlen(expr) + 1);
	stackType* myStack;
	char* cptr;

	myStack = A_createStack();

	cptr = postfix;
	while (*expr != '\0') {
		switch (*expr) {
		case '*':
		case '+':
		case '-':
		case '/':
			A_push(myStack, *expr);
			expr++;
			break;
		case ')':
			*cptr = *expr;
			cptr++;
			*cptr = A_pop(myStack);
			expr++;
			cptr++;
			break;
		default: *cptr++ = *expr++;
			break;
		}
	}
	*cptr = '\0';
	A_destroyStack(myStack);
	return postfix;
}


int eval_postfix(char* postfix) {
	int opr1, opr2, value, i = 0;
	int length = strlen(postfix);
	char symbol;

	stackType* myStack;
	myStack = A_createStack();

	for (i = 0; i < length; i++) {
		symbol = postfix[i];
		switch (symbol) {
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			A_push(myStack, symbol);
			break;
		case '+':
			opr1 = (int)A_pop(myStack) - '0';
			opr2 = (int)A_pop(myStack) - '0';
			value = opr2 + opr1;
			A_push(myStack, (element)value + '0'); break;
		case '-':
			opr1 = (int)A_pop(myStack) - '0';
			opr2 = (int)A_pop(myStack) - '0';
			value = opr2 - opr1;
			A_push(myStack, (element)value + '0'); break;
		case '*':
			opr1 = (int)A_pop(myStack) - '0';
			opr2 = (int)A_pop(myStack) - '0';
			value = opr2 * opr1;
			A_push(myStack, (element)value + '0'); break;
		case '/':
			opr1 = (int)A_pop(myStack) - '0';
			opr2 = (int)A_pop(myStack) - '0';
			value = opr2 / opr1;
			A_push(myStack, (element)value + '0'); break;
		default: break;
		}
	}

	value = (int)A_pop(myStack) - '0';

	A_destroyStack(myStack);

	return value;
}

main() {
	/*
	stackType* myStack;
	element item;

	myStack = A_createStack();

	A_push(myStack, 1);
	A_printStack(myStack);

	A_push(myStack, 2);
	A_printStack(myStack);

	A_push(myStack, 3);
	A_printStack(myStack);

	A_push(myStack, 4);
	A_printStack(myStack);

	item = A_pop(myStack);
	printf("Poped item = %d\n", item);
	A_printStack(myStack);

	item = A_pop(myStack);
	printf("Poped item = %d\n", item);
	A_printStack(myStack);

	item = A_pop(myStack);
	printf("Poped item = %d\n", item);
	A_printStack(myStack);

	item = A_pop(myStack);
	printf("Poped item = %d\n", item);
	A_printStack(myStack);

	item = A_pop(myStack);
	printf("Poped item = %d\n", item);
	A_printStack(myStack);

	A_destroyStack(myStack);


	L_createStack();

	L_push(1);

	L_push(2);

	L_push(3);

	L_push(4);
	L_printStack();

	item = L_pop();
	printf("Poped item = %d\n", item);
	L_printStack();

	item = L_pop();
	printf("Poped item = %d\n", item);
	L_printStack();

	item = L_pop();
	printf("Poped item = %d\n", item);
	L_printStack();

	item = L_pop();
	printf("Poped item = %d\n", item);
	L_printStack();

	item = L_pop();
	printf("Poped item = %d\n", item);
	L_printStack();

	L_destroyStack();
	return 0;
	*/

	char* expr = "((2+(3*4))-(5*6))";
	char* postfix;
	int r;

	check_brace(expr);

	postfix = infix_to_postfix(expr);
	printf("\nInfix = %s\n", expr);
	printf("Postfix = %s\n", postfix);

	r = eval_postfix(postfix);
	printf("Evaluation result = %d\n", r);

	free(postfix);
}