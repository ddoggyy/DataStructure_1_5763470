#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void) {

	typedef struct student {
		char name[20];
		int id;
		int score;
	} Stdtype;
	int count = 0, idSearch = 0, isCorrect = 0;

	printf("����� �л� ������ �Է��Ͻó���? ");
	scanf("%d", &count);
	
	Stdtype *students = (Stdtype*)malloc(count * sizeof(Stdtype));

	for (int i = 0; i < count; i++) {
		printf("[%d] �л��� ������ �Է��ϼ��� (�̸� �й� ����): ", i + 1);
		scanf("%s %d %d", &students[i].name, &students[i].id, &students[i].score);
	}
	
	do {
		isCorrect = 0;
		printf("�й��� �Է��ϼ���(0�̸� ����)? ");
		scanf("%d", &idSearch);
		for (int i = 0; i < count; i++) {
			if (idSearch == students[i].id) {
				printf("%s %d %d\n", students[i].name, students[i].id, students[i].score);
				isCorrect = 1;
				break;
			}
		}
		if (isCorrect == 0) {
			printf("�ش� �й��� �л��� �����ϴ�.\n");
		}
	} while (idSearch != 0);
	
	

	free(students);

	return 0;
	
}


