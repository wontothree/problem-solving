#include <stdio.h>

int main(void) {
    int num;
    scanf("%d", &num);

    printf("%d", (2 + num * (num + 1) / 2) * (2 + num * (num + 1) / 2));

    return 0;
}
