#include <stdio.h>
#include <string.h>

void toggle(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        // 대문자 -> 소문자 변환
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; // 아스키 코드 차이만큼 더함
        }
        // 소문자 -> 대문자 변환
        else if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32; // 아스키 코드 차이만큼 빼줌
        }
    }
}

int main() {
    char str[100];

    // 문자열 입력 받기
    printf("알파벳을 입력하시오 : ");
    fgets(str, sizeof(str), stdin);

    // 대소문자 변환
    toggle(str);

    // 변환된 문자열 출력
    printf("%s\n", str);

    return 0;
}