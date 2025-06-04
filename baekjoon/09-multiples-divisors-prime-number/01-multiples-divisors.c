#include <stdio.h>

int main(void) {
    while (1) {
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        if (num1 == 0 && num2 == 0) {
            break;
        }

        if (num2 % num1 == 0) {
            printf("%s\n", "factor");
        } else if (num1 % num2 == 0) {
            printf("%s\n", "multiple");
        } else {
            printf("%s\n", "neither");
        }
    }

    return 0;
}