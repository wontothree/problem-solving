#include <stdio.h>

int main(void) {
    int num, th;
    scanf("%d %d", &num, &th);

    int divisor[num];
    for (int i = 0; i < num; i++) {
        divisor[i] = 0;
    }

    int last = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            divisor[last] = i;
            last++;
        }
    }

    printf("%d", divisor[th - 1]);

    return 0;
}