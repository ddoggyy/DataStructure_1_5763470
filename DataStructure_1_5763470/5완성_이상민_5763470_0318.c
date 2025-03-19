#include <stdio.h>

// µ¡¼À ÇÔ¼ö
int add();

// »¬¼À ÇÔ¼ö
int subtract();

// °ö¼À ÇÔ¼ö
int multiply();

// ³ª´°¼À ÇÔ¼ö
float divide();

int main() {
    int num1, num2;

    // »ç¿ëÀÚ·ÎºÎÅÍ ¾çÀÇ Á¤¼ö ÀÔ·Â¹Ş±â
    printf("Ã¹ ¹øÂ° ¾çÀÇ Á¤¼ö¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
    scanf_s("%d", &num1);

    printf("µÎ ¹øÂ° ¾çÀÇ Á¤¼ö¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
    scanf_s("%d", &num2);

    // »çÄ¢¿¬»ê °á°ú Ãâ·Â
    printf("µ¡¼À: %d\n", add(num1, num2));
    printf("»¬¼À: %d\n", subtract(num1, num2));
    printf("°ö¼À: %d\n", multiply(num1, num2));
    printf("³ª´°¼À: %.2f\n", divide(num1, num2));

    return 0;
}

int add(int num1, int num2) {
    return num1 + num2;
}

// »¬¼À ÇÔ¼ö
int subtract(int num1, int num2) {
    return num1 - num2;
}

// °ö¼À ÇÔ¼ö
int multiply(int num1, int num2) {
    return num1 * num2;
}

// ³ª´°¼À ÇÔ¼ö
float divide(int num1, int num2) {
    return (float)num1 / num2;
}
