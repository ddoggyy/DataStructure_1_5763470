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

	printf("몇명의 학생 정보를 입력하시나요? ");
	scanf("%d", &count);
	
	Stdtype *students = (Stdtype*)malloc(count * sizeof(Stdtype));

	for (int i = 0; i < count; i++) {
		printf("[%d] 학생의 정보를 입력하세요 (이름 학번 점수): ", i + 1);
		scanf("%s %d %d", &students[i].name, &students[i].id, &students[i].score);
	}
	
	do {
		isCorrect = 0;
		printf("학번을 입력하세요(0이면 종료)? ");
		scanf("%d", &idSearch);
		for (int i = 0; i < count; i++) {
			if (idSearch == students[i].id) {
				printf("%s %d %d\n", students[i].name, students[i].id, students[i].score);
				isCorrect = 1;
				break;
			}
		}
		if (isCorrect == 0) {
			printf("해당 학번의 학생이 없습니다.\n");
		}
	} while (idSearch != 0);
	
	

	free(students);

	return 0;
	
}


