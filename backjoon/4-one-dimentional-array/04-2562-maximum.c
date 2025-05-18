#include <stdio.h>

int main(void) {
    int sequence[9];
    for (int i = 0; i < 9; i++) {
        scanf("%d", &sequence[i]);
    }

    int max = sequence[0];
    int max_index;
    for (int i = 0; i < 9; i++) {
        if (max <= sequence[i]) {
            max = sequence[i];
            max_index = i;
        }
    }

    printf("%d\n%d", max, max_index + 1);

    return 0;
}
