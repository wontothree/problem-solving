#include <stdio.h>

int main(void) {
    int num;
    scanf("%d", &num);

    int sequence[1000000];
    for (int i = 0; i < num; i++) {
        scanf("%d", &sequence[i]);
    }

    int min = sequence[0];
    int max = sequence[0];
    for (int i = 0; i < num; i++) {
        if (min > sequence[i]) {
            min = sequence[i];
        }

        if (max < sequence[i]) {
            max = sequence[i];
        }
    }
    printf("%d %d", min, max);

    return 0;
}