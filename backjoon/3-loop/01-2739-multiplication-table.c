#include <stdio.h>

int main(void) {
    int number;

    scanf("%d", &number);

    for (int i = 1; i <=9; i++) {
        printf("%d * %d = %d\n", number, i, number * i);
    }

    return 0;
}