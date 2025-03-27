#include <stdio.h>
#include <stdlib.h>

int	main() {
	int i;
	int *iptr;
	/*int iArray[10] = {1,2,3,4,5,6,7,8,9,10};
	int iArray2[10] = { 10,20,30,40,50,60,70,80,90,100 };

	i = 10;
	iptr = &i;

	printf("i : %d, address of i 0x%X\n\n", i, &i);
	printf("iptr; 0x%X, value of iptr pointer : %d\n", iptr, *iptr);

	printf("\niArray: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", iArray[i]);
	}
	printf("\n");

	add1array(&iArray[0]);

	printf("iArray: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", iArray[i]);
	}

	iptr = &iArray2[0];
	printf("iArray: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", iArray[i]);
	}*/

	printf("number of iArray element? ");
	scanf_s("%d", &i);
	iptr = (int*)malloc(i * sizeof(int));
	for (int j = 0; j < i; j++) {
		*(iptr + j) = j + 1;
		// == iptr[j] = j + 1; 
	}


	printf("memory alloc array = ");

	for (int j = 0; j < i; j++) {
		printf("%d ", *(iptr + j));
	}
	printf("\n");

	typedef struct student {
		char name[20];
		int id;
		int score;
	} Stdtype;

	Stdtype students[3] = { {"Hong Gildong", 10, 90}, {"Lee MongRyong", 20, 80}, {"Seong ChoonHyang", 30, 70} };
	Stdtype* sptr = students; // &students[0]
	for (int k = 0; k < 3; k++) {
		students[k].score += 10;
	}
	for (int k = 0; k < 3; k++) {
		(*sptr).score += 10; // sptr->score += 10;
		sptr++;
	}