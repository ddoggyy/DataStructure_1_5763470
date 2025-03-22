/*
    DECLARE str[100] AS STRING

    PRINT "계산할 수식을 입력하세요 (예: 3 + 5 * 2 - 8 / 4):"
    READ str 

    DECLARE result AS DOUBLE
    result = CALL Calculator WITH str

    PRINT "결과: ", result %.6f

 FUNCTION Calculator(str: STRING) AS DOUBLE {

    DECLARE stack[100] AS DOUBLE
    DECLARE stackIndex AS INTEGER = -1
    DECLARE op AS CHAR = '+'
    DECLARE num AS DOUBLE

    FOR i FROM 0 TO LENGTH OF str - 1 DO {
        DECLARE currentChar AS CHAR
        currentChar = str[i]

        IF currentChar IS DIGIT THEN
            num = num * 10 + (currentChar - '0')

        ELSE IF currentChar IS SPACE THEN
            CONTINUE

        ELSE IF currentChar IS an operator (+, -, *, /) DO {
            IF op IS '+' DO {
                PUSH num TO stack[stackIndex + 1]
                stackIndex = stackIndex + 1
                }
            ELSE IF op IS '-' DO {
                PUSH -num TO stack[stackIndex + 1]
                stackIndex = stackIndex + 1
                }
            ELSE IF op IS '*' DO {
                stack[stackIndex] = stack[stackIndex] * num
                }
            ELSE IF op IS '/' DO {
                stack[stackIndex] = stack[stackIndex] / num
                }
            op = currentChar
            num = 0.0
            }
        }

    IF op IS '+' DO {
        PUSH num TO stack[stackIndex + 1]
        stackIndex = stackIndex + 1
        }
    ELSE IF op IS '-' DO {
        PUSH -num TO stack[stackIndex + 1]
        stackIndex = stackIndex + 1
        }
    ELSE IF op IS '*' DO {
        stack[stackIndex] = stack[stackIndex] * num
        }
    ELSE IF op IS '/' DO {
        stack[stackIndex] = stack[stackIndex] / num
        }

    DECLARE result AS DOUBLE
    result = 0.0
    FOR i FROM 0 TO stackIndex DO 
        result = result + stack[i]

    RETURN result
}
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double Calculator(char* str);

int main() {
    char str[100];

    // 수식을 입력받음
    printf("계산할 수식을 입력하세요 (예: 3 + 5 * 2 - 8 / 4): ");
    fgets(str, sizeof(str), stdin);

    // 수식을 계산하고 결과 출력
    double result = Calculator(str);
    printf("결과: %.6f\n", result);

    return 0;
}

// 수식을 계산하는 함수
double Calculator(char* str) {
    double stack[100];
    int stackIndex = -1;
    char op = '+';
    double num = 0.0;

    for (int i = 0; str[i] != '\0'; i++) {
        char currentStr = str[i];

        if (isdigit(currentStr)) {
            num = num * 10 + (currentStr - '0');  // 숫자 조합
        }
        else if (currentStr == ' ') {
            // 공백 무시
            continue;
        }
        else if (currentStr == '+' || currentStr == '-' || currentStr == '*' || currentStr == '/') {
            // 연산자가 나오면 그때까지 쌓인 숫자를 처리
            if (op== '+') {
                stack[++stackIndex] = num;
            }
            else if (op == '-') {
                stack[++stackIndex] = -num;
            }
            else if (op == '*') {
                stack[stackIndex] = stack[stackIndex] * num;
            }
            else if (op == '/') {
                stack[stackIndex] = stack[stackIndex] / num;
            }

            // 새로운 연산자와 숫자 초기화
            op = currentStr;
            num = 0;
        }
    }

    if (op == '+') {
        stack[++stackIndex] = num;
    }
    else if (op == '-') {
        stack[++stackIndex] = -num;
    }
    else if (op == '*') {
        stack[stackIndex] = stack[stackIndex] * num;
    }
    else if (op == '/') {
        stack[stackIndex] = stack[stackIndex] / num;
    }

    // 최종 결과 계산 (스택의 모든 값을 더함)
    double result = 0.0;
    for (int i = 0; i <= stackIndex; i++) {
        result += stack[i];
    }

    return result;
}
