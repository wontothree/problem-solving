#include <stdio.h>

int main(void) {
    while (1) {
        int num;
        scanf("%d", &num);
        if (num == -1) {
            break;
        }

        int divisor[num];
        int last = 0;
        for (int i = 0; i < num; i++) {
            divisor[i] = 0;
        }

        for (int i = 1; i < num; i++) {
            if (num % i == 0) {
                divisor[last] = i;
                last++;
            }
        }

        int sum = 0;
        for (int i = 0; i < num; i++) {
            sum += divisor[i];
        }

        if (num == -1) {
            break;
        } else if (num == sum) {
            printf("%d = ", num);
            for (int i = 0; i < last - 1; i++) {
                printf("%d + ", divisor[i]);
            }

            printf("%d\n", divisor[last - 1]);
        } else {
            printf("%d is NOT perfect.\n", num);
        }
    }

    return 0;
}