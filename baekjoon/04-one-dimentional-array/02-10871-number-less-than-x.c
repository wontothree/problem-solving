#include <stdio.h>

int main(void) {
    int sequence_num, choosed_num;
    scanf("%d %d", &sequence_num, &choosed_num);

    int sequence[10000];
    for (int i = 0; i < sequence_num; i++) {
        scanf("%d", &sequence[i]);
    }

    for (int i = 0; i < sequence_num; i++) {
        if (sequence[i] < choosed_num) {
            printf("%d ", sequence[i]);
        }
    }

    return 0;
}