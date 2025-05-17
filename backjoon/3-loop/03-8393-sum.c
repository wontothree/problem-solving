#include <stdio.h>

int main(void) {
    int num;

    scanf("%d", &num);

    int sum = 0;
    for (int i = 1; i <= num; i++) {
        sum += i;
    }
    printf("%d", sum);

    return 0;
}