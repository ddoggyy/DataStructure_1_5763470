#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  
#include "LinearList.h"

int getNumber(const char* str, int* i) {
    int num = 0;
    while (isdigit(str[*i])) {
        num = num * 10 + (str[*i] - '0');
        (*i)++;
    }
    return num;
}

// �Ľ� �Լ�
void parsePolynomial(const char* str, listType* poly) {
    int i = 0;
    int sign = 1;

    while (str[i] != '\0') {
        // 1. ��ȣ ó��
        if (str[i] == '+') {
            sign = 1;
            i++;
        }
        else if (str[i] == '-') {
            sign = -1;
            i++;
        }

        // 2. ��� �б�
        int coef = 0, expo = 0;

        if (isdigit(str[i])) {
            coef = getNumber(str, &i);
        }
        else if (str[i] == 'x') {
            coef = 1;
        }

        // 3. x ó��
        if (str[i] == 'x') {
            i++;
            if (str[i] == '^') {
                i++;
                expo = getNumber(str, &i);
            }
            else {
                expo = 1;
            }
        }
        else {
            expo = 0;
        }

        // ����� ��ȣ ����
        coef *= sign;

        // 4. �� ����
        elementType term = { coef, expo };
        ordered_insertItem(poly, term);
    }
}


listType* polyMultiply(listType* f, listType* s) {
	listType* a;
	int i = 0, j = 0;
	elementType f_item, s_item, fs_item;
	a = createList(f->last + s->last + 2);
	for (i = 0; i <= f->last; i++) {
		f_item = readItem(f, i);
		for (j = 0; j <= s->last; j++) {
			s_item = readItem(s, j);
			fs_item.coef = f_item.coef * s_item.coef;
			fs_item.expo = f_item.expo + s_item.expo;
			ordered_insertItem(a, (elementType) { fs_item.coef, fs_item.expo });
		}
	}
	return a;
}

int main(void) {
	listType* poly1, * poly2, * poly3;
    char input[100];

	poly1 = createList(10);
    printf("ù ��° ���׽��� �Է��ϼ��� (��: 3x^2-4x+1):\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    parsePolynomial(input, poly1);
	printList(poly1);

	poly2 = createList(10);
    printf("\n�� ��° ���׽��� �Է��ϼ��� (��: 2x^2+5x+3):\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    parsePolynomial(input, poly2);
	printList(poly2);

	poly3 = polyMultiply(poly1, poly2);
    printf("\n\n[���� ���]\n");
	printList(poly3);

	destroyList(poly1);
	destroyList(poly2);
	destroyList(poly3);
}