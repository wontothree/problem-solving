#include <stdio.h>

int main(void) {
    int num1, num2;

    scanf("%d\n%d", &num1, &num2);

    printf("%d\n", num1 * (num2 % 10));
    printf("%d\n", num1 * (num2 % 100 / 10));
    printf("%d\n", num1 * (num2 / 100));
    printf("%d\n", num1 * num2);

    return 0;
}
